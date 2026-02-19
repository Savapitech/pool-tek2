#include <iostream>
#include <regex>

#include "BistroException.hpp"
#include "Instructions.hpp"
#include "OperandFactory.hpp"

std::string trim(const std::string &str) {
  size_t first = str.find_first_not_of(" \t\r\n");
  if (first == std::string::npos)
    return "";
  size_t last = str.find_last_not_of(" \t\r\n");
  return str.substr(first, last - first + 1);
}

void check_trail(std::istringstream &iss)
{
  std::string out;
  iss >> out;
  if (!out.empty())
    throw BistroException("error: too many arguments in function call.");
}

Instructions::Instructions(std::stack<IOperand *> &stack,
                           std::map<int, IOperand *> &regs, bool &shouldExit)
    : _stack(stack), _registers(regs), _shouldExit(shouldExit) {}

void Instructions::_binOp(IOperand *(IOperand::*op)(const IOperand &) const) {
  if (_stack.size() < 2)
    throw BistroException("error: requires at least 2 values on stack.");
  IOperand *right = _stack.top();
  _stack.pop();
  IOperand *left = _stack.top();
  _stack.pop();

  try {
    IOperand *result = (left->*op)(*right);
    delete left;
    delete right;
    _stack.push(result);
  } catch (...) {
    delete left;
    delete right;
    throw;
  }
}

void Instructions::_parse(std::istringstream &iss, OperandType &type,
                          std::string &value) {
  std::string typeStr;
  iss >> typeStr;
  int bits = 0;
  bool isInt = false;

  size_t parenPos = typeStr.find('(');

  // Format: int32(42), float64(3.14)
  if (parenPos != std::string::npos) {
    std::string baseType = typeStr.substr(0, parenPos);
    isInt = (baseType.rfind("int", 0) == 0);

    std::string bitsStr = isInt ? baseType.substr(3) : baseType.substr(5);
    bits = std::stoi(bitsStr);

    std::string rest;
    std::getline(iss, rest);
    rest = typeStr.substr(parenPos + 1) + rest;

    size_t closePos = rest.find(')');
    if (closePos == std::string::npos)
      throw BistroException("error: parenthesis was not closed.");
    if (!std::regex_match(rest.substr(closePos), std::regex("[)][ \t\r\n]*")))
      throw BistroException("error: extra characters after arguments");
    value = trim(rest.substr(0, closePos));
  }

  // Format: int32 42, float64 3.14
  else if ((typeStr.rfind("int", 0) == 0 && typeStr.size() > 3) ||
           (typeStr.rfind("float", 0) == 0 && typeStr.size() > 5)) {

    isInt = (typeStr.rfind("int", 0) == 0);

    std::string bitsStr = isInt ? typeStr.substr(3) : typeStr.substr(5);
    bits = std::stoi(bitsStr);

    std::getline(iss, value);
    value = trim(value);
  }

  // Format: int 32 42, float 64 3.14
  else {
    isInt = (typeStr == "int");
    iss >> bits;
    std::getline(iss, value);
    value = trim(value);
  }

  if (isInt) {
    type = (bits == 8)    ? Int8
           : (bits == 16) ? Int16
           : (bits == 32) ? Int32
                          : Int64;
  } else {
    type = (bits == 32) ? Float32 : Float64;
  }

  if (!std::regex_match(value, std::regex("[-]?[0-9]+[.]?[0-9]*")))
    throw BistroException("error: value does not match regular expression.");
}

void Instructions::push(std::istringstream &iss) {
  OperandType type;
  std::string valueStr;

  _parse(iss, type, valueStr);
  _stack.push(OperandFactory::createOperand(type, valueStr));
}

void Instructions::pop(std::istringstream &iss) {
  check_trail(iss);
  if (_stack.empty())
    throw BistroException("error: pop on empty stack.");
  delete _stack.top();
  _stack.pop();
}

void Instructions::display(std::istringstream &iss) {
  check_trail(iss);
  if (_stack.empty())
    throw BistroException("error: display on empty stack.");
  std::cout << _stack.top()->toString() << std::endl;
}

void Instructions::clear(std::istringstream &iss) {
  check_trail(iss);
  while (!_stack.empty()) {
    delete _stack.top();
    _stack.pop();
  }
}

void Instructions::swap(std::istringstream &iss) {
  check_trail(iss);
  if (_stack.size() < 2)
    throw BistroException("error: swap requires at least 2 values on stack.");
  IOperand *first = _stack.top();
  _stack.pop();
  IOperand *second = _stack.top();
  _stack.pop();
  _stack.push(first);
  _stack.push(second);
}

void Instructions::assert(std::istringstream &iss) {
  if (_stack.empty())
    throw BistroException("error: assert on empty stack.");

  OperandType type;
  std::string valueStr;

  _parse(iss, type, valueStr);
  IOperand *expected = OperandFactory::createOperand(type, valueStr);
  bool match = (_stack.top()->getType() == expected->getType() &&
                _stack.top()->toString() == expected->toString());
  delete expected;
  if (!match)
    throw BistroException("error: assertion failed.");
}

void Instructions::add(std::istringstream &iss) { check_trail(iss); _binOp(&IOperand::operator+); }

void Instructions::sub(std::istringstream &iss) { check_trail(iss); _binOp(&IOperand::operator-); }

void Instructions::mul(std::istringstream &iss) { check_trail(iss); _binOp(&IOperand::operator*); }

void Instructions::div(std::istringstream &iss) { check_trail(iss); _binOp(&IOperand::operator/); }

void Instructions::mod(std::istringstream &iss) { check_trail(iss); _binOp(&IOperand::operator%); }

void Instructions::load(std::istringstream &iss) {
  int registerNum;
  if (!(iss >> registerNum) || registerNum < 0 || registerNum > 15)
    throw BistroException("error: invalid register.");
  if (_registers.find(registerNum) == _registers.end())
    throw BistroException("error: load on empty register.");
  IOperand *regValue = _registers[registerNum];
  _stack.push(
      OperandFactory::createOperand(regValue->getType(), regValue->toString()));
}

void Instructions::store(std::istringstream &iss) {
  int registerNum;
  if (!(iss >> registerNum) || registerNum < 0 || registerNum > 15)
    throw BistroException("error: invalid register.");
  if (_stack.empty())
    throw BistroException("error: store on empty stack.");
  if (_registers.find(registerNum) != _registers.end())
    delete _registers[registerNum];
  _registers[registerNum] = _stack.top();
  _stack.pop();
}

void Instructions::exit(std::istringstream &iss) {
  check_trail(iss);
  _shouldExit = true;
}
