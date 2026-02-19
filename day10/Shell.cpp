#include "Shell.hpp"

Shell::Shell(std::istream &stream) : _stream(stream) {}

void Shell::next() {
  std::string line;

  if (!std::getline(_stream, line)) {
    if (_stream.eof())
      throw Error("End of input");
    else
      throw Error("Input failed");
  }

  _currentLine.clear();
  _currentLine.str(line);
}
