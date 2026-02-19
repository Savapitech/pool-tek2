#pragma once

#include <cstddef>

#include "IObject.hpp"

class SharedPointer {
private:
  IObject *_ptr;
  std::size_t *_count;

public:
  SharedPointer();
  explicit SharedPointer(IObject *ptr);
  SharedPointer(const SharedPointer &other);
  ~SharedPointer();

  SharedPointer &operator=(const SharedPointer &other);
  SharedPointer &operator=(IObject *ptr);
  IObject *operator->() const;
  IObject &operator*() const;
  void reset(IObject *ptr = nullptr);
  void swap(SharedPointer &other);
  std::size_t use_count() const;
};
