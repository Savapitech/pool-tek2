#include "AFruit.hpp"

AFruit::AFruit(std::string name, unsigned int vitamins, bool ispeeled) {
  this->_ispeeled = ispeeled;
  this->_vitamins = vitamins;
  this->_name = name;
}

unsigned int AFruit::getVitamins() const {
  if (!this->_ispeeled)
    return 0;
  return this->_vitamins;
}

std::string AFruit::getName() const {
  return this->_name;
}

bool AFruit::isPeeled() const {
  return this->_ispeeled;
}

void AFruit::peel() {
  this->_ispeeled = true;
}
