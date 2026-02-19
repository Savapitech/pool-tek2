#include "Grapefruit.hpp"

Grapefruit::Grapefruit() : ACitrus("grapefruit", 5) {
}

IFruit *Grapefruit::clone() const {
  return new Grapefruit();
}
