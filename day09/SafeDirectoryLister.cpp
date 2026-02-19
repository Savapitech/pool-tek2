#include "SafeDirectoryLister.hpp"

SafeDirectoryLister::SafeDirectoryLister() : _dir(nullptr), _hidden(false) {}

SafeDirectoryLister::SafeDirectoryLister(const std::string &path, bool hidden)
    : _dir(nullptr), _hidden(false) {
  this->open(path, hidden);
}

SafeDirectoryLister::~SafeDirectoryLister() {
  if (_dir != nullptr)
    closedir(_dir);
}

bool SafeDirectoryLister::open(const std::string &path, bool hidden) {
  if (_dir != nullptr)
    closedir(_dir);

  _dir = opendir(path.c_str());
  _hidden = hidden;

  if (_dir == nullptr)
    throw IDirectoryLister::OpenFailureException();
  return true;
}

std::string SafeDirectoryLister::get() {
  if (_dir == nullptr)
    throw IDirectoryLister::NoMoreFileException();

  for (struct dirent *sd = readdir(_dir); sd != nullptr; sd = readdir(_dir)) {
    if (_hidden)
      return sd->d_name;
    else if (sd->d_name[0] != '.')
      return sd->d_name;
  }
  throw IDirectoryLister::NoMoreFileException();
}
