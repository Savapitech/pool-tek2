#include <iostream>

#include "Peasant.hpp"

Peasant::Peasant(const std::string &name, int power) : _name(name) {
  if (power > 100)
    this->_power = 100;
  else
    this->_power = power;
  std::cout << this->_name << " goes for an adventure." << std::endl;
}

Peasant::~Peasant() {
  std::cout << this->_name << " is back to his crops." << std::endl;
}

int Peasant::getHp() const {
  return this->_health;
}

int Peasant::getPower() const {
  return this->_power;
}

const std::string &Peasant::getName() const {
  return this->_name;
}


int Peasant::attack() {
  if (!this->_health) {
    std::cout << this->getName() << " is out of combat." << std::endl;
    return 0;
  } else if (this->_power - 10 < 0) {
    std::cout << this->getName() << " is out of power." << std::endl;
    return 0;
  }
  std::cout << this->getName() << " tosses a stone." << std::endl;
  this->_power -= 10;
  return 5;
}

int Peasant::special() {
  if (!this->_health) {
    std::cout << this->getName() << " is out of combat." << std::endl;
    return 0;
  }
  std::cout << this->getName() << " doesn't know any special move." << std::endl;
  return 0;
}

void Peasant::rest() {
  if (!this->_health) {
    std::cout << this->getName() << " is out of combat." << std::endl;
    return;
  }
  std::cout << this->getName() << " takes a nap." << std::endl;
  if (this->_power + 30 >= 100)
    this->_power = 100;
  else
    this->_power += 30;
}

void Peasant::damage(int damage) {
    this->_health -= damage;
    if (this->_health > 0)
        std::cout << this->_name << " takes " << damage << " damage." << std::endl;
    if (this->_health <= 0) {
        std::cout << this->_name << " is out of combat." << std::endl;
        this->_health = 0;
        return;
    }
}
