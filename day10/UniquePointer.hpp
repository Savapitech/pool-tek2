#pragma once

template <typename Type> class UniquePointer {
private:
  Type *_ptr;

public:
  UniquePointer(Type *ptr = nullptr) : _ptr(ptr) {}
  ~UniquePointer() { delete _ptr; }
  UniquePointer(const UniquePointer &) = delete;
  UniquePointer &operator=(const UniquePointer &) = delete;

  UniquePointer &operator=(Type *ptr) {
    delete _ptr;
    _ptr = ptr;
    return *this;
  }
  void reset() {
    delete _ptr;
    _ptr = nullptr;
  }

  Type *get() { return _ptr; }
  Type *operator->() { return _ptr; }
  const Type *operator->() const { return _ptr; }
};