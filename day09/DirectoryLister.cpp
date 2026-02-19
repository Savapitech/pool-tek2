#include <cstdio>
#include <dirent.h>

#include "DirectoryLister.hpp"

DirectoryLister::DirectoryLister() : _dir(nullptr), _hidden(false) {}

DirectoryLister::DirectoryLister(const std::string &path, bool hidden)
    : _dir(nullptr), _hidden(false) {
  this->open(path, hidden);
}

DirectoryLister::~DirectoryLister() {
  if (_dir != nullptr)
    closedir(_dir);
}

bool DirectoryLister::open(const std::string &path, bool hidden) {
  if (_dir != nullptr)
    closedir(_dir);

  _dir = opendir(path.c_str());
  _hidden = hidden;

  if (_dir == nullptr)
    return perror(path.c_str()), false;
  return true;
}

std::string DirectoryLister::get() {
  if (_dir == nullptr)
    return "";

  for (struct dirent *sd = readdir(_dir); sd != nullptr; sd = readdir(_dir)) {
    if (_hidden)
      return sd->d_name;
    else if (sd->d_name[0] != '.')
      return sd->d_name;
  }
  return "";
}
