#include "Almond.hpp"
#include "ANut.hpp"

Almond::Almond() : ANut("almond", 2) {
}

IFruit *Almond::clone() const {
  return new Almond();
}
