#include <iostream>

#include "Knight.hpp"

Knight::Knight(const std::string& name, int power) : Peasant(name, power) {
  std::cout << this->getName() << " vows to protect the kingdom." << std::endl;
}

Knight::~Knight() {
  std::cout << this->getName() << " takes off his armor." << std::endl;
}

int Knight::attack() {
  if (!this->_health) {
    std::cout << this->getName() << " is out of combat." << std::endl;
    return 0;
  } else if (this->_power - 10 < 0) {
    std::cout << this->getName() << " is out of power." << std::endl;
    return 0;
  }
  std::cout << this->getName() << " strikes with his sword." << std::endl;
  this->_power -= 10;
  return 20;
}

int Knight::special() {
  if (!this->_health) {
    std::cout << this->getName() << " is out of combat." << std::endl;
    return 0;
  } else if (this->_power - 30 < 0) {
    std::cout << this->getName() << " is out of power." << std::endl;
    return 0;
  }
  this->_power -= 30;
  std::cout << this->getName() << " impales his enemy." << std::endl;
  return 50;
}

void Knight::rest() {
  if (!this->_health) {
    std::cout << this->getName() << " is out of combat." << std::endl;
    return;
  }
  this->_power += 50;
  if (this->_power > 100)
    this->_power = 100;
  std::cout << this->getName() << " eats." << std::endl;
}
