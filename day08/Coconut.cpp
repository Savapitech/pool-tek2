#include "Coconut.hpp"

Coconut::Coconut() : ANut("coconut", 4) {
}

IFruit *Coconut::clone() const {
  return new Coconut();
}
