#include <cmath>
#include <iomanip>
#include <sstream>

#include "BistroException.hpp"
#include "IOperand.hpp"
#include "Operand.hpp"

Operand::Operand(const std::string &value, OperandType type)
    : _value(value), _type(type) {}

std::string Operand::toString() const { return _value; }

OperandType Operand::getType() const { return _type; }

static std::string formatValue(OperandType type, double value) {
  std::ostringstream oss;

  if (type == Float32)
    oss << std::fixed << std::setprecision(7) << value;
  else if (type == Float64)
    oss << std::fixed << std::setprecision(15) << value;
  else
    oss << (long long)value;
  return oss.str();
}

static OperandType getMaxType(OperandType a, OperandType b) {
  return (a > b) ? a : b;
}

IOperand *Operand::operator+(const IOperand &rhs) const {
  OperandType resultType = getMaxType(this->_type, rhs.getType());
  double leftValue = std::stod(this->_value);
  double rightValue = std::stod(rhs.toString());
  double result = leftValue + rightValue;

  return new Operand(formatValue(resultType, result), resultType);
}

IOperand *Operand::operator-(const IOperand &rhs) const {
  OperandType resultType = getMaxType(this->_type, rhs.getType());
  double leftValue = std::stod(this->_value);
  double rightValue = std::stod(rhs.toString());
  double result = leftValue - rightValue;

  return new Operand(formatValue(resultType, result), resultType);
}

IOperand *Operand::operator*(const IOperand &rhs) const {
  OperandType resultType = getMaxType(this->_type, rhs.getType());
  double leftValue = std::stod(this->_value);
  double rightValue = std::stod(rhs.toString());
  double result = leftValue * rightValue;

  return new Operand(formatValue(resultType, result), resultType);
}

IOperand *Operand::operator/(const IOperand &rhs) const {
  OperandType resultType = getMaxType(this->_type, rhs.getType());
  double leftValue = std::stod(this->_value);
  double rightValue = std::stod(rhs.toString());
  if (rightValue == 0.0)
    throw BistroException("error: division by zero.");
  double result = leftValue / rightValue;

  return new Operand(formatValue(resultType, result), resultType);
}

IOperand *Operand::operator%(const IOperand &rhs) const {
  OperandType resultType = getMaxType(this->_type, rhs.getType());
  double leftValue = std::stod(this->_value);
  double rightValue = std::stod(rhs.toString());
  if (rightValue == 0.0)
    throw BistroException("error: modulo by zero.");
  double result;
  if (resultType >= Float32)
    result = fmod(leftValue, rightValue);
  else
    result = (long long)leftValue % (long long)rightValue;

  return new Operand(formatValue(resultType, result), resultType);
}
