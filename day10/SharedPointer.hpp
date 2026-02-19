#pragma once

#include <cstddef>

template <typename Type> class SharedPointer {
private:
  Type *_ptr;
  std::size_t *_refCount;

  void release() {
    if (_refCount) {
      (*_refCount)--;
      if (*_refCount == 0) {
        delete _ptr;
        delete _refCount;
      }
    }
  }

public:
  SharedPointer(Type *ptr = nullptr)
      : _ptr(ptr), _refCount(ptr ? new std::size_t(1) : nullptr) {}

  SharedPointer(const SharedPointer &other)
      : _ptr(other._ptr), _refCount(other._refCount) {
    if (_refCount)
      (*_refCount)++;
  }

  ~SharedPointer() { release(); }

  SharedPointer &operator=(const SharedPointer &other) {
    if (this != &other) {
      release();
      _ptr = other._ptr;
      _refCount = other._refCount;
      if (_refCount)
        (*_refCount)++;
    }
    return *this;
  }

  SharedPointer &operator=(Type *ptr) {
    release();
    _ptr = ptr;
    _refCount = ptr ? new std::size_t(1) : nullptr;
    return *this;
  }

  void reset() {
    release();
    _ptr = nullptr;
    _refCount = nullptr;
  }

  Type *get() { return _ptr; }
  const Type *get() const { return _ptr; }
  Type *operator->() { return _ptr; }
  const Type *operator->() const { return _ptr; }
};
