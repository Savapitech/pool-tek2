#include "Raspberry.hpp"

Raspberry::Raspberry() : ABerry("raspberry", 5) {
}

IFruit *Raspberry::clone() const {
  return new Raspberry();
}
