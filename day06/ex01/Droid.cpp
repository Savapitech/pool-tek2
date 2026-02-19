#include <iostream>
#include <string>

#include "Droid.hpp"
#include "DroidMemory.hpp"

Droid::Droid(const std::string id) : _energy(50), _attack(25), _toughness(15) {
  this->_id = id;
  this->_status = new std::string("Standing by");
  this->_battledata = new DroidMemory();
  std::cout << "Droid '" << this->_id << "' Activated" << std::endl;
}

Droid::Droid(const Droid &droid) : _energy(droid.getEnergy()), _attack(droid.getAttack()), _toughness(droid.getToughness()) {
  this->_id = droid.getId();
  this->_status = new std::string(*droid.getStatus());
  this->_battledata = new DroidMemory(*(droid.getBattleData()));
  std::cout << "Droid '" << this->_id << "' Activated, Memory Dumped" << std::endl;
}

Droid &Droid::operator=(const Droid &copy) {
  this->_id = copy.getId();
  *this->_status = *copy.getStatus();
  *this->_battledata = *copy.getBattleData();
  this->_energy = copy.getEnergy();
  
  return *this;
}

Droid::~Droid() {
  delete(this->_status);
  delete(this->_battledata);
  std::cout << "Droid '" << this->_id << "' Destroyed" << std::endl;
}

std::string Droid::getId() const {
  return this->_id;
}

void Droid::setId(const std::string id) {
  this->_id = id;
}

size_t Droid::getEnergy() const {
  return this->_energy;
}

void Droid::setEnergy(const size_t energy) {
  size_t tmp = energy;

  if (energy > 100)
    tmp = 100;
  this->_energy = tmp;
}

size_t Droid::getAttack() const {
  return this->_attack;
}

size_t Droid::getToughness() const {
  return this->_toughness;
}

std::string *Droid::getStatus() const {
  return this->_status;
}

void Droid::setStatus(std::string *status) {
  delete this->_status;
  this->_status = status;
}

Droid &Droid::operator<<(size_t &energy)
{
  if (this->_energy + energy >= 100) {
    energy -= (100 - _energy);
    this->_energy = 100;
  } else {
    this->_energy += energy;
    energy = 0;
  }
  return *this;
}

std::ostream &operator<<(std::ostream &os, Droid const &rhs)
{
  size_t tmp = rhs.getEnergy();

  if (tmp > 100)
    tmp = 100;
  os << "Droid '" << rhs.getId() << "', " << *rhs.getStatus() << ", " << tmp;
  return os;
}

bool operator==(const Droid &lhs, const Droid &rhs) {
  return (*(lhs.getStatus()) == *(rhs.getStatus()));
}

bool operator!=(const Droid &lhs, const Droid &rhs) {
  return !operator==(lhs, rhs);
}

DroidMemory *Droid::getBattleData() const {
  return this->_battledata;
}

void Droid::setBattleData(DroidMemory *battledata) {
  delete this->_battledata;
  this->_battledata = battledata;
}
