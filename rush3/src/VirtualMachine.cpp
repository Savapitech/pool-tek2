#include <sstream>

#include "BistroException.hpp"
#include "VirtualMachine.hpp"
#include "Instructions.hpp"

VirtualMachine::VirtualMachine()
    : _shouldExit(false),
      _inst(new Instructions(_stack, _registers, _shouldExit)) {
  _instructions["push"]    = [this](std::istringstream &iss) { _inst->push(iss); };
  _instructions["pop"]     = [this](std::istringstream &iss) { _inst->pop(iss); };
  _instructions["display"] = [this](std::istringstream &iss) { _inst->display(iss); };
  _instructions["clear"]   = [this](std::istringstream &iss) { _inst->clear(iss); };
  _instructions["swap"]    = [this](std::istringstream &iss) { _inst->swap(iss); };
  _instructions["assert"]  = [this](std::istringstream &iss) { _inst->assert(iss); };
  _instructions["add"]     = [this](std::istringstream &iss) { _inst->add(iss); };
  _instructions["sub"]     = [this](std::istringstream &iss) { _inst->sub(iss); };
  _instructions["mul"]     = [this](std::istringstream &iss) { _inst->mul(iss); };
  _instructions["div"]     = [this](std::istringstream &iss) { _inst->div(iss); };
  _instructions["mod"]     = [this](std::istringstream &iss) { _inst->mod(iss); };
  _instructions["load"]    = [this](std::istringstream &iss) { _inst->load(iss); };
  _instructions["store"]   = [this](std::istringstream &iss) { _inst->store(iss); };
  _instructions["exit"]    = [this](std::istringstream &iss) { _inst->exit(iss); };
}

VirtualMachine::~VirtualMachine() {
  while (!_stack.empty()) {
    delete _stack.top();
    _stack.pop();
  }
  for (auto &reg : _registers)
    delete reg.second;
  delete _inst;
}

void VirtualMachine::executeInstruction(const std::string &line) {
  std::string cleanLine = line;
  size_t commentPos = cleanLine.find(';');

  if (commentPos != std::string::npos)
    cleanLine = cleanLine.substr(0, commentPos);
  cleanLine = trim(cleanLine);
  if (cleanLine.empty())
    return;
  std::istringstream iss(cleanLine);
  std::string instruction;
  iss >> instruction;
  auto it = _instructions.find(instruction);
  if (it != _instructions.end())
    it->second(iss);
  else
    throw BistroException("error: unknown instruction '" + instruction + "'.");
}

bool VirtualMachine::shouldStop() const { return _shouldExit; }
