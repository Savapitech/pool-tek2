#pragma once

template <typename T> void swap(T &a, T &b) {
  T tmp = b;

  b = a;
  a = tmp;
}

template <typename T> T min(const T a, const T b) { return a < b ? a : b; }

template <typename T> T max(const T a, const T b) { return a < b ? b : a; }

template <typename T> T clamp(T value, T min, T max) {
  if (value < min)
    value = min;
  if (max < value)
    value = max;
  return value;
}
