#pragma once

#include <exception>
#include <string>

class BistroException : public std::exception {
  std::string message;

public:
  explicit BistroException(const std::string &msg) : message(msg) {}
  virtual ~BistroException() noexcept = default;

  const char *what() const noexcept override { return message.c_str(); }
};
