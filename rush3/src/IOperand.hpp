#pragma once

#include <string>

enum OperandType { Int8, Int16, Int32, Int64, Float32, Float64 };

class IOperand {
public:
  virtual std::string toString() const = 0;
  virtual OperandType getType() const = 0;
  virtual IOperand *operator+(const IOperand &rhs) const = 0;
  virtual IOperand *operator-(const IOperand &rhs) const = 0;
  virtual IOperand *operator*(const IOperand &rhs) const = 0;
  virtual IOperand *operator/(const IOperand &rhs) const = 0;
  virtual IOperand *operator%(const IOperand &rhs) const = 0;
  virtual ~IOperand() = default;
};
