#pragma once

#include <dirent.h>

#include "IDirectoryLister.hpp"

class DirectoryLister : public IDirectoryLister {
private:
  DIR *_dir;
  bool _hidden;

public:
  DirectoryLister();
  DirectoryLister(const DirectoryLister &) = delete;
  DirectoryLister(const std::string &path, bool hidden);
  ~DirectoryLister();
  bool open(const std::string &path, bool hidden) override;
  std::string get() override;
};
