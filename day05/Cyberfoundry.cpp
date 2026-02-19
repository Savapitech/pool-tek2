#include <iostream>

#include "Cyberfoundry.hpp"

Mondas::Cyberfoundry::Cyberfoundry(unsigned int &energy) : _energy(energy) {
  std::cout << "A new Cyberfoundry has opened." << std::endl;
}

Mondas::Cyberfoundry::~Cyberfoundry() {
  std::cout << "A Cyberfoundry has closed." << std::endl;
}

Mondas::Cyberman* Mondas::Cyberfoundry::buildCyberman(Mondas::Human &human) {
  if (this->_energy < human.getIq() + 50) {
    std::cout << "Not enough energy to build a new Cyberman." << std::endl;
    return nullptr;
  }
  std::cout << "Building a new Cyberman from '" << human.getName() << "'." << std::endl;
  this->_energy -= human.getIq() + 50;
  return new Mondas::Cyberman(human);
}

Mondas::Cyberleader* Mondas::Cyberfoundry::buildCyberleader(Mondas::Human &human) {
  if (this->_energy < 150 + human.getIq() * 2) {
    std::cout << "Not enough energy to build a new Cyberleader." << std::endl;
    return nullptr;
  }
  std::cout << "Building a new Cyberleader from '" << human.getName() << "'." << std::endl;
  this->_energy -= 150 + human.getIq() * 2;
  return new Mondas::Cyberleader(human);
}

void Mondas::Cyberfoundry::recycle(Mondas::Cyberman *&cyberman) {
  if (cyberman == nullptr) {
    std::cout << "Nothing to recycle." << std::endl;
    return;
  }
  std::cout << "Recycling Cyberman '" << cyberman->getName() << "'." << std::endl;
  delete(cyberman);
  cyberman = nullptr;
  this->_energy += 50;
}

void Mondas::Cyberfoundry::recycle(Mondas::Cyberleader *&cyberleader) {
  if (cyberleader == nullptr) {
    std::cout << "Nothing to recycle." << std::endl;
    return;
  }
  std::cout << "Recycling Cyberleader '" << cyberleader->getName() << "'." << std::endl;
  delete(cyberleader);
  cyberleader = nullptr;
  this->_energy += 150;
}
