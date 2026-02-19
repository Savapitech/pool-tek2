#pragma once

#include <string>

#include "IOperand.hpp"

class Operand : public IOperand {
  std::string _value;
  OperandType _type;

public:
  Operand(const std::string &value, OperandType type);
  std::string toString() const override;
  OperandType getType() const override;
  IOperand *operator+(const IOperand &rhs) const override;
  IOperand *operator-(const IOperand &rhs) const override;
  IOperand *operator*(const IOperand &rhs) const override;
  IOperand *operator/(const IOperand &rhs) const override;
  IOperand *operator%(const IOperand &rhs) const override;
};
