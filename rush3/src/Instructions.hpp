#pragma once

#include <map>
#include <sstream>
#include <stack>

#include "IOperand.hpp"

class Instructions {
  std::stack<IOperand *> &_stack;
  std::map<int, IOperand *> &_registers;
  bool &_shouldExit;

  void _parse(std::istringstream &iss, OperandType &type, std::string &value);
  void _binOp(IOperand *(IOperand::*op)(const IOperand &) const);

public:
  Instructions(std::stack<IOperand *> &stack, std::map<int, IOperand *> &regs,
               bool &shouldExit);

  void push(std::istringstream &iss);
  void pop(std::istringstream &iss);
  void display(std::istringstream &iss);
  void clear(std::istringstream &iss);
  void swap(std::istringstream &iss);
  void assert(std::istringstream &iss);
  void add(std::istringstream &iss);
  void sub(std::istringstream &iss);
  void mul(std::istringstream &iss);
  void div(std::istringstream &iss);
  void mod(std::istringstream &iss);
  void load(std::istringstream &iss);
  void store(std::istringstream &iss);
  void exit(std::istringstream &iss);
};

void check_trail(std::istringstream &iss);
std::string trim(const std::string &str);