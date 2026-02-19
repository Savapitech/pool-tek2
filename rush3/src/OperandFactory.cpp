#include <cmath>
#include <iomanip>
#include <sstream>

#include "BistroException.hpp"
#include "Operand.hpp"
#include "OperandFactory.hpp"

static std::string formatValue(OperandType type, long double value) {
  std::ostringstream oss;

  if (type == Float32)
    oss << std::fixed << std::setprecision(7) << value;
  else if (type == Float64)
    oss << std::fixed << std::setprecision(15) << value;
  else
    oss << std::fixed << (long long)value;
  return oss.str();
}

IOperand *OperandFactory::createInt8(const std::string &value) {
  double num = std::stod(value);
  if (num < -128 || num > 127)
    throw BistroException("overflow");
  return new Operand(formatValue(Int8, num), Int8);
}

IOperand *OperandFactory::createInt16(const std::string &value) {
  double num = std::stod(value);
  if (num < -32768 || num > 32767)
    throw BistroException("overflow");
  return new Operand(formatValue(Int16, num), Int16);
}

IOperand *OperandFactory::createInt32(const std::string &value) {
  double num = std::stod(value);
  if (num < -2147483648.0 || num > 2147483647.0)
    throw BistroException("overflow");
  return new Operand(formatValue(Int32, num), Int32);
}

IOperand *OperandFactory::createInt64(const std::string &value) {
  long long num;
  try {
    num = std::stoll(value);
    return new Operand(formatValue(Int64, num), Int64);
  } catch (...) {
    throw BistroException("overflow");
  }
}

IOperand *OperandFactory::createFloat32(const std::string &value) {
  double num = std::stod(value);
  return new Operand(formatValue(Float32, num), Float32);
}

IOperand *OperandFactory::createFloat64(const std::string &value) {
  double num = std::stod(value);
  return new Operand(formatValue(Float64, num), Float64);
}

IOperand *OperandFactory::createOperand(OperandType type,
                                        const std::string &value) {
  typedef IOperand *(*CreateFunc)(const std::string &);
  static const CreateFunc creators[] = {&createInt8,    &createInt16,
                                        &createInt32,   &createInt64,
                                        &createFloat32, &createFloat64};
  return creators[type](value);
}
