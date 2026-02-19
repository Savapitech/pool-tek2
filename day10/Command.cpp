#include "Command.hpp"

void Command::registerCommand(const std::string &name,
                              const std::function<void()> &function) {
  if (_commands.find(name) != _commands.end())
    throw Error("Already registered command");
  _commands[name] = function;
}

void Command::executeCommand(const std::string &name) {
  if (_commands.find(name) == _commands.end())
    throw Error("Unknow command");
  _commands[name]();
}
