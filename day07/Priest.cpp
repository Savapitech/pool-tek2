#include <iostream>

#include "Priest.hpp"

Priest::Priest(const std::string &name, int power) : Peasant::Peasant(name, power), Enchanter(name, power) {
  std::cout << this->getName() << " enters in the order." << std::endl;
}

Priest::~Priest() {
  std::cout << this->getName() << " finds peace." << std::endl;
}

void Priest::rest() {
  if (!this->_health) {
    std::cout << this->getName() << " is out of combat." << std::endl;
    return;
  }
  this->_power = 100;
  this->_health = 100;
  std::cout << this->getName() << " prays." << std::endl;
}
