#include <iostream>

#include "Human.hpp"

Mondas::Human::Human(std::string name, Mondas::Cyberman::Inhibitor *inhibitor) {
  std::cout << name << ": I must save Mondas with my IQ of " << 192 << "." << std::endl;
  this->_name = name;
  this->_iq = 192;
  this->_inhibitor = inhibitor;
}

Mondas::Human::Human(std::string name, unsigned int iq, Mondas::Cyberman::Inhibitor *inhibitor) {
  std::cout << name << ": I must save Mondas with my IQ of " << iq << "." << std::endl;
  this->_name = name;
  this->_iq = iq;
  this->_inhibitor = inhibitor;
}

Mondas::Human::~Human() {
  std::cout << this->_name << ": I failed to save my world..." << std::endl;
}

std::string Mondas::Human::getName() const {
  return this->_name;
}

unsigned int Mondas::Human::getIq() const {
  return this->_iq;
}

void Mondas::Human::setIq(unsigned int newIq) {
  if (newIq < this->_iq)
    return;

  this->_iq = newIq;
  std::cout << this->_name << ": My IQ is now " << this->_iq << "." << std::endl;
}

void Mondas::Human::think() const {
  std::cout << this->_name << ": Think, think, think..." << std::endl;
}

void Mondas::Human::setInhibitor(Mondas::Cyberman::Inhibitor *inhibitor)
{
  if (this->_inhibitor == nullptr)
    this->_inhibitor = inhibitor;
}

Mondas::Cyberman::Inhibitor *Mondas::Human::getInhibitor() {
  return this->_inhibitor;
}
