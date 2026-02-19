#include "Strawberry.hpp"
#include "ABerry.hpp"

Strawberry::Strawberry() : ABerry("strawberry", 6) {
}

IFruit *Strawberry::clone() const {
  return new Strawberry();
}
