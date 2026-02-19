#pragma once

#include <exception>
#include <stack>
#include <string>

class Stack {
  std::stack<double> _data;

public:
  class Error : public std::exception {
    std::string _message;

  public:
    explicit Error(std::string message) : _message(message) {};
    virtual ~Error() noexcept = default;

    const char *what() const noexcept override { return _message.c_str(); };
  };

  Stack() = default;
  void push(double value);
  double pop();
  double top() const;
  void add();
  void sub();
  void mul();
  void div();
};