#pragma once

#include <dirent.h>

#include "IDirectoryLister.hpp"

class SafeDirectoryLister : public IDirectoryLister {
private:
  DIR *_dir;
  bool _hidden;

public:
  SafeDirectoryLister();
  SafeDirectoryLister(const SafeDirectoryLister &) = delete;
  SafeDirectoryLister(const std::string &path, bool hidden);
  ~SafeDirectoryLister();
  bool open(const std::string &path, bool hidden) override;
  std::string get() override;
};
