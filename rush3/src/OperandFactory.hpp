#pragma once

#include <string>

#include "IOperand.hpp"

class OperandFactory {
private:
  static IOperand *createInt8(const std::string &value);
  static IOperand *createInt16(const std::string &value);
  static IOperand *createInt32(const std::string &value);
  static IOperand *createInt64(const std::string &value);
  static IOperand *createFloat32(const std::string &value);
  static IOperand *createFloat64(const std::string &value);

public:
  static IOperand *createOperand(OperandType type, const std::string &value);
};
