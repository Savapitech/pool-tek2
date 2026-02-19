#pragma once

#include "Array.hpp"
#include <iostream>

template <unsigned int Rows, unsigned int Cols> class Matrix {
private:
  Array<Array<double, Cols>, Rows> _data;

public:
  Matrix() {
    for (unsigned int i = 0; i < Rows; i++)
      for (unsigned int j = 0; j < Cols; j++)
        _data[i][j] = 0.0;
  }

  double operator()(unsigned int row, unsigned int col) const {
    return _data[row][col];
  }

  double &operator()(unsigned int row, unsigned int col) {
    return _data[row][col];
  }

  template <unsigned int OtherCols>
  Matrix<Rows, OtherCols>
  operator*(const Matrix<Cols, OtherCols> &other) const {
    Matrix<Rows, OtherCols> result;

    for (unsigned int i = 0; i < Rows; i++) {
      for (unsigned int j = 0; j < OtherCols; j++) {
        double sum = 0.0;
        for (unsigned int k = 0; k < Cols; k++)
          sum += (*this)(i, k) * other(k, j);
        result(i, j) = sum;
      }
    }

    return result;
  }

  Matrix &operator*=(const Matrix<Cols, Cols> &other) {
    *this = *this * other;
    return *this;
  }
};

template <unsigned int Rows, unsigned int Cols>
std::ostream &operator<<(std::ostream &os, const Matrix<Rows, Cols> &matrix) {
  os << "[";
  for (unsigned int i = 0; i < Rows; i++) {
    if (i > 0)
      os << ", ";
    os << "[";
    for (unsigned int j = 0; j < Cols; j++) {
      if (j > 0)
        os << ", ";
      os << matrix(i, j);
    }
    os << "]";
  }
  os << "]";
  return os;
}
