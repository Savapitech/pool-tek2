#pragma once

#include <exception>
#include <functional>
#include <map>
#include <string>

class Command {
public:
  class Error : public std::exception {
  private:
    const char *_message;

  public:
    Error(const char *message) : _message(message) {}
    const char *what() const noexcept override { return _message; }
  };

  void registerCommand(const std::string &name,
                       const std::function<void()> &function);
  void executeCommand(const std::string &name);

private:
  std::map<std::string, std::function<void()>> _commands;
};