#include "Lemon.hpp"
#include "ACitrus.hpp"

Lemon::Lemon() : ACitrus("lemon", 4) {
}

IFruit *Lemon::clone() const {
  return new Lemon();
}
