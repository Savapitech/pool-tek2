#include "BloodOrange.hpp"

BloodOrange::BloodOrange() : Orange() {
  this->_name = "blood orange";
  this->_vitamins = 6;
}

IFruit *BloodOrange::clone() const {
  return new BloodOrange();
}
