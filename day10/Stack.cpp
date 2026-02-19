#include "Stack.hpp"

void Stack::push(double value) { _data.push(value); }

double Stack::pop() {
  if (!_data.size())
    throw Stack::Error("Empty stack");

  double data = _data.top();

  _data.pop();
  return data;
}

double Stack::top() const {
  if (!_data.size())
    throw Stack::Error("Empty stack");

  return _data.top();
}

void Stack::add() {
  if (_data.size() < 2)
    throw Stack::Error("Not enough operands");

  double a = this->pop();
  double b = this->pop();

  this->push(a + b);
}

void Stack::sub() {
  if (_data.size() < 2)
    throw Stack::Error("Not enough operands");

  double b = this->pop();
  double a = this->pop();

  this->push(b - a);
}

void Stack::mul() {
  if (_data.size() < 2)
    throw Stack::Error("Not enough operands");

  double a = this->pop();
  double b = this->pop();

  this->push(a * b);
}

void Stack::div() {
  if (_data.size() < 2)
    throw Stack::Error("Not enough operands");

  double b = this->pop();
  double a = this->pop();
  if (b == 0.0)
    throw Stack::Error("Div by zero");

  this->push(b / a);
}