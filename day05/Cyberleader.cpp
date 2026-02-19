#include <iostream>

#include "Cyberleader.hpp"

Mondas::Cyberleader::Cyberleader(Mondas::Human &human) : _human(human) {
  this->_name = leet_convert(this->_human.getName());
  std::cout << this->_name << ": Master unit activated." << std::endl;
}

Mondas::Cyberleader::~Cyberleader() {
  std::cout << this->_name << ": Master unit deactivated." << std::endl;
}

void Mondas::Cyberleader::upgrade(Mondas::Cyberman::Inhibitor &inhibitor) {
  if (this->_human.getInhibitor() == nullptr || !this->_human.getInhibitor()->get()) {
    std::cout << this->_name << ": Pain, pain, pain..." << std::endl;
    return;
  }
  if (inhibitor.get())
    std::cout << this->_name << ": Inhibitor already activated." << std::endl;
  else {
    inhibitor.set(true);
    std::cout << this->_name << ": Activating inhibitor." << std::endl;
  }
}

void Mondas::Cyberleader::upgrade(Mondas::Human &human) {
  if (this->_human.getInhibitor() == nullptr || !this->_human.getInhibitor()->get()) {
    std::cout << this->_name << ": Pain, pain, pain..." << std::endl;
    return;
  }
  std::cout << this->_name << ": Upgrading human '" << human.getName() << "'." << std::endl;
  human.setIq(human.getIq() * 2);
  std::cout << "IQ of unit doubled, increased to " << human.getIq() << "." << std::endl;
  if (human.getInhibitor() == nullptr)
    std::cout << "No inhibitor installed." << std::endl;
  else
    this->upgrade(*human.getInhibitor());
}


void Mondas::Cyberleader::upgrade(Mondas::Cyberman &cyberman) {
  if (this->_human.getInhibitor() == nullptr || !this->_human.getInhibitor()->get()) {
    std::cout << this->_name << ": Pain, pain, pain..." << std::endl;
    return;
  }
  std::cout << this->_name << ": Upgrading unit '" << cyberman.getName() << "'." << std::endl;
  this->upgrade(cyberman.getHuman());
}

std::string Mondas::Cyberleader::getName() {
  return this->_name;
}
