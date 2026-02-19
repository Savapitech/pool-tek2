#include "DroidFactory.hpp"
#include <iostream>
#include <cmath>

DroidFactory::DroidFactory(size_t ratio) : _iron(0), _silicon(0), _exp(0), _ratio(ratio) {
}

DroidFactory::DroidFactory(const DroidFactory &other) : _iron(other._iron), _silicon(other._silicon), _exp(other._exp), _ratio(other._ratio) {
}

DroidFactory &DroidFactory::operator=(const DroidFactory &other) {
  if (this != &other) {
    _iron = other._iron;
    _silicon = other._silicon;
    _exp = other._exp;
    _ratio = other._ratio;
  }
  return *this;
}

DroidFactory::~DroidFactory() {
}

size_t DroidFactory::getIron() const {
  return _iron;
}

size_t DroidFactory::getSilicon() const {
  return _silicon;
}

size_t DroidFactory::getExp() const {
  return _exp;
}

size_t DroidFactory::getRatio() const {
  return _ratio;
}

DroidFactory &DroidFactory::operator<<(Supply &supply) {
  if (supply == Supply::Iron) {
    _iron += supply.getAmount();
  } else if (supply == Supply::Silicon) {
    _silicon += supply.getAmount();
  } else if (supply == Supply::Wreck) {
    for (size_t i = 0; i < supply.getAmount(); i++) {
      Droid *droid = *supply;
      if (droid != nullptr) {
        _iron += 80;
        _silicon += 30;
        
        if (droid->getBattleData()->getExp() > _exp) {
          size_t diff = droid->getBattleData()->getExp() - _exp;
          _exp += diff / _ratio;
        }
      }
      ++supply;
    }
  }
  !supply;
  return *this;
}

DroidFactory &DroidFactory::operator>>(Droid *&droid) {
  if (_iron >= 100 && _silicon >= 50) {
    _iron -= 100;
    _silicon -= 50;
    
    droid = new Droid("");
    size_t exp_to_give = _exp - (_exp / _ratio);
    droid->getBattleData()->setExp(exp_to_give);
  } else
    droid = nullptr;
  return *this;
}

DroidFactory &DroidFactory::operator++() {
  _ratio++;
  return *this;
}

DroidFactory DroidFactory::operator++(int) {
  DroidFactory tmp(*this);
  _ratio++;
  return tmp;
}

DroidFactory &DroidFactory::operator--() {
  if (_ratio > 1)
    _ratio--;
  return *this;
}

DroidFactory DroidFactory::operator--(int) {
  DroidFactory tmp(*this);
  if (_ratio > 1)
    _ratio--;
  return tmp;
}

std::ostream &operator<<(std::ostream &os, const DroidFactory &factory) {
  os << "DroidFactory status report :" << std::endl;
  os << "Iron : " << factory.getIron() << std::endl;
  os << "Silicon : " << factory.getSilicon() << std::endl;
  os << "Exp : " << factory.getExp() << std::endl;
  os << "End of status report.";
  return os;
}

DroidFactory &operator>>(Supply &supply, DroidFactory &factory) {
  factory << supply;
  return factory;
}
