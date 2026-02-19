#pragma once

#include <cstddef>
#include <functional>
#include <iostream>

template <typename T, std::size_t Size> class Array {
  T _data[Size]{};

public:
  Array() = default;

  T &operator[](std::size_t index) {
    if (index >= Size)
      throw std::out_of_range("Out of range");
    return _data[index];
  }

  const T &operator[](std::size_t index) const {
    if (index >= Size)
      throw std::out_of_range("Out of range");
    return _data[index];
  }

  std::size_t size() const { return Size; }

  void forEach(const std::function<void(const T &)> &task) const {
    for (std::size_t i = 0; i < Size; ++i)
      task(_data[i]);
  }

  template <typename U>
  Array<U, Size> convert(const std::function<U(const T &)> &converter) const {
    Array<U, Size> result;

    for (std::size_t i = 0; i < Size; ++i)
      result[i] = converter(_data[i]);

    return result;
  }
};

template <typename Type, std::size_t Size>
std::ostream &operator<<(std::ostream &os, const Array<Type, Size> &array) {
  os << "[";
  for (std::size_t i = 0; i < Size; ++i)
    os << array[i] << ((i + 1 < Size) ? ", " : "");
  os << "]";
  return os;
}
