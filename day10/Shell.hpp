#pragma once

#include <exception>
#include <iostream>
#include <sstream>
#include <string>

class Shell {
public:
  class Error : public std::exception {
  private:
    const char *_message;

  public:
    Error(const char *message) : _message(message) {}
    const char *what() const noexcept override { return _message; }
  };

  class Warning : public std::exception {
  private:
    const char *_message;

  public:
    Warning(const char *message) : _message(message) {}
    const char *what() const noexcept override { return _message; }
  };

  Shell(std::istream &stream);
  void next();

  template <typename T> T extract();

private:
  std::istream &_stream;
  std::stringstream _currentLine;
};

template <typename T> T Shell::extract() {
  T value;
  _currentLine >> value;

  if (_currentLine.fail()) {
    _currentLine.clear();
    std::string word;
    _currentLine >> word;
    throw Warning("Invalid conversion");
  }

  return value;
}