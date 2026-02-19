#include <iostream>

#include "Enchanter.hpp"

Enchanter::Enchanter(const std::string &name, int power) : Peasant(name, power) {
  std::cout << this->getName() << " learns magic from his spellbook." << std::endl;
}

Enchanter::~Enchanter() {
  std::cout << this->getName() << " closes his spellbook." << std::endl;
}

int Enchanter::attack() {
  if (!this->_health) {
    std::cout << this->getName() << " is out of combat." << std::endl;
    return 0;
  }
  std::cout << this->getName() << " doesn't know how to fight." << std::endl;
  return 0;
}

int Enchanter::special() {
  if (!this->_health) {
    std::cout << this->getName() << " is out of combat." << std::endl;
    return 0;
  } else if (this->_power - 50 < 0) {
    std::cout << this->getName() << " is out of power." << std::endl;
    return 0;
  }
  this->_power -= 50;
  std::cout << this->getName() << " casts a fireball." << std::endl;
  return 99;
}

void Enchanter::rest() {
  if (!this->_health) {
    std::cout << this->getName() << " is out of combat." << std::endl;
    return;
  }
  std::cout << this->getName() << " meditates." << std::endl;
  _power = 100;
}
