#include "Orange.hpp"
#include "ACitrus.hpp"

Orange::Orange() : ACitrus("orange", 7) {
}

IFruit *Orange::clone() const {
  return new Orange();
}
