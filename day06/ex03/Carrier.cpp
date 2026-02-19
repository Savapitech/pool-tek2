#include "Carrier.hpp"
#include <iostream>
#include <cmath>

Carrier::Carrier(const std::string &id) : _id(id), _energy(300), _attack(100), _toughness(90), _speed(0) {
  for (int i = 0; i < 5; i++) {
    _droids[i] = nullptr;
  }
}

Carrier::Carrier() : _id(""), _energy(300), _attack(100), _toughness(90), _speed(0) {
  for (int i = 0; i < 5; i++) {
    _droids[i] = nullptr;
  }
}

Carrier::~Carrier() {
  for (int i = 0; i < 5; i++) {
    if (_droids[i] != nullptr) {
      delete _droids[i];
    }
  }
}

std::string Carrier::getId() const {
  return _id;
}

void Carrier::setId(const std::string &id) {
  _id = id;
}

size_t Carrier::getEnergy() const {
  return _energy;
}

void Carrier::setEnergy(size_t energy) {
  if (energy > 600)
    energy = 600;
  _energy = energy;
}

size_t Carrier::getAttack() const {
  return _attack;
}

size_t Carrier::getToughness() const {
  return _toughness;
}

size_t Carrier::getSpeed() const {
  return _speed;
}

void Carrier::updateSpeed() {
  size_t count = 0;
  for (int i = 0; i < 5; i++) {
    if (_droids[i] != nullptr) {
      count++;
    }
  }
  if (count == 0) {
    _speed = 0;
  } else {
    _speed = 100 - (count * 10);
  }
}

Carrier &Carrier::operator<<(Droid *&droid) {
  if (droid == nullptr)
    return *this;
  for (int i = 0; i < 5; i++) {
    if (_droids[i] == nullptr) {
      _droids[i] = droid;
      droid = nullptr;
      updateSpeed();
      return *this;
    }
  }
  return *this;
}

Carrier &Carrier::operator>>(Droid *&droid) {
  for (int i = 0; i < 5; i++) {
    if (_droids[i] != nullptr) {
      droid = _droids[i];
      _droids[i] = nullptr;
      updateSpeed();
      return *this;
    }
  }
  return *this;
}

Droid *&Carrier::operator[](size_t index) {
  return _droids[index];
}

Droid * const &Carrier::operator[](size_t index) const {
  return _droids[index];
}

Carrier &Carrier::operator~() {
  updateSpeed();
  return *this;
}

bool Carrier::operator()(int x, int y) {
  size_t nbDroid = 0;
  for (int i = 0; i < 5; i++) {
    if (_droids[i] != nullptr) {
      nbDroid++;
    }
  }
  
  if (_speed == 0)
    return false;
  
  size_t cost = (std::abs(x) + std::abs(y)) * (10 + nbDroid);
  
  if (_energy < cost)
    return false;
  
  _energy -= cost;
  return true;
}

Carrier &Carrier::operator<<(size_t &energy) {
  if (_energy + energy >= 600) {
    energy -= (600 - _energy);
    _energy = 600;
  } else {
    _energy += energy;
    energy = 0;
  }
  return *this;
}

std::ostream &operator<<(std::ostream &os, const Carrier &carrier) {
  os << "Carrier '" << carrier.getId() << "' Droid(s) on-board:" << std::endl;
  for (int i = 0; i < 5; i++) {
    os << "[" << i << "] : ";
    if (carrier[i] != nullptr) {
      os << *carrier[i];
    } else {
      os << "Free";
    }
    os << std::endl;
  }
  os << "Speed : " << carrier.getSpeed() << ", Energy " << carrier.getEnergy();
  return os;
}
