#pragma once

#include "IObject.hpp"

class UniquePointer {
private:
  IObject *_ptr;

public:
  UniquePointer();
  UniquePointer(IObject *ptr);
  UniquePointer(const UniquePointer &) = delete;
  UniquePointer(UniquePointer &&other) noexcept;
  UniquePointer &operator=(const UniquePointer &) = delete;
  UniquePointer &operator=(UniquePointer &&other) noexcept;
  ~UniquePointer();

  IObject *operator->() const;
  IObject &operator*() const;
  UniquePointer &operator=(IObject *ptr);
  void reset(IObject *ptr = nullptr);
  void swap(UniquePointer &other);
};
