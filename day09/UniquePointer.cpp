#include "UniquePointer.hpp"

UniquePointer::UniquePointer() : _ptr(nullptr) {}

UniquePointer::UniquePointer(IObject *ptr) : _ptr(ptr) {}

UniquePointer::UniquePointer(UniquePointer &&other) noexcept
    : _ptr(other._ptr) {
  other._ptr = nullptr;
}

UniquePointer &UniquePointer::operator=(UniquePointer &&other) noexcept {
  if (this != &other) {
    if (_ptr != nullptr)
      delete _ptr;
    _ptr = other._ptr;
    other._ptr = nullptr;
  }
  return *this;
}

UniquePointer::~UniquePointer() {
  if (_ptr != nullptr)
    delete _ptr;
}

IObject *UniquePointer::operator->() const { return _ptr; }

IObject &UniquePointer::operator*() const { return *_ptr; }

UniquePointer &UniquePointer::operator=(IObject *ptr) {
  if (_ptr != nullptr)
    delete _ptr;
  _ptr = ptr;
  return *this;
}

void UniquePointer::reset(IObject *ptr) {
  if (_ptr != nullptr)
    delete _ptr;
  _ptr = ptr;
}

void UniquePointer::swap(UniquePointer &other) {
  IObject *tmp = _ptr;
  _ptr = other._ptr;
  other._ptr = tmp;
}
