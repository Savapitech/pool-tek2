#pragma once

#include <cstring>
#include <exception>
#include <string>

class IDirectoryLister {
public:
  class OpenFailureException : public std::exception {
    std::string _message;

  public:
    explicit OpenFailureException() : _message(strerror(errno)) {}
    virtual ~OpenFailureException() noexcept = default;
    const char *what() const noexcept override { return _message.c_str(); }
  };

  class NoMoreFileException : public std::exception {
  public:
    explicit NoMoreFileException() = default;
    virtual ~NoMoreFileException() noexcept = default;
    const char *what() const noexcept override { return "End of stream"; }
  };

  virtual ~IDirectoryLister() = default;
  virtual bool open(const std::string &path, bool hidden) = 0;
  virtual std::string get() = 0;
};
