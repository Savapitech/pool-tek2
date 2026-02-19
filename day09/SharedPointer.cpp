#include "SharedPointer.hpp"

SharedPointer::SharedPointer() : _ptr(nullptr), _count(nullptr) {}

SharedPointer::SharedPointer(IObject *ptr) : _ptr(ptr), _count(nullptr) {
  if (_ptr != nullptr) {
    _count = new std::size_t(1);
  }
}

SharedPointer::SharedPointer(const SharedPointer &other)
    : _ptr(other._ptr), _count(other._count) {
  if (_count != nullptr)
    (*_count)++;
}

SharedPointer::~SharedPointer() {
  if (_count != nullptr) {
    (*_count)--;
    if (*_count == 0) {
      if (_ptr != nullptr)
        delete _ptr;
      delete _count;
    }
  }
}

SharedPointer &SharedPointer::operator=(const SharedPointer &other) {
  if (this != &other) {
    if (_count != nullptr) {
      (*_count)--;
      if (*_count == 0) {
        if (_ptr != nullptr)
          delete _ptr;
        delete _count;
      }
    }
    _ptr = other._ptr;
    _count = other._count;
    if (_count != nullptr)
      (*_count)++;
  }
  return *this;
}

SharedPointer &SharedPointer::operator=(IObject *ptr) {
  if (_count != nullptr) {
    (*_count)--;
    if (*_count == 0) {
      if (_ptr != nullptr)
        delete _ptr;
      delete _count;
    }
  }
  _ptr = ptr;
  if (_ptr != nullptr)
    _count = new std::size_t(1);
  else
    _count = nullptr;
  return *this;
}

IObject *SharedPointer::operator->() const { return _ptr; }

IObject &SharedPointer::operator*() const { return *_ptr; }

void SharedPointer::reset(IObject *ptr) {
  if (_count != nullptr) {
    (*_count)--;
    if (*_count == 0) {
      if (_ptr != nullptr)
        delete _ptr;
      delete _count;
    }
  }
  _ptr = ptr;
  if (_ptr != nullptr)
    _count = new std::size_t(1);
  else
    _count = nullptr;
}

void SharedPointer::swap(SharedPointer &other) {
  IObject *tmpPtr = _ptr;
  std::size_t *tmpCount = _count;
  _ptr = other._ptr;
  _count = other._count;
  other._ptr = tmpPtr;
  other._count = tmpCount;
}

std::size_t SharedPointer::use_count() const {
  if (_count == nullptr)
    return 0;
  return *_count;
}
