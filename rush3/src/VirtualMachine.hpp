#pragma once

#include <functional>
#include <map>
#include <stack>
#include <string>

#include "IOperand.hpp"
#include "Instructions.hpp"

class VirtualMachine {
  std::stack<IOperand *> _stack;
  std::map<int, IOperand *> _registers;
  bool _shouldExit;
  std::map<std::string, std::function<void(std::istringstream &)>>
      _instructions;
  Instructions *_inst;

public:
  VirtualMachine();
  ~VirtualMachine();
  void executeInstruction(const std::string &line);
  bool shouldStop() const;
};
