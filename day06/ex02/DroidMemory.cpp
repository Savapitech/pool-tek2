#include "DroidMemory.hpp"

DroidMemory::DroidMemory() : _fingerprint(random()), _exp(0){
}

DroidMemory::DroidMemory(const DroidMemory &droidmemory) : _fingerprint(droidmemory._fingerprint), _exp(droidmemory._exp) {
}

size_t DroidMemory::getExp() const {
  return this->_exp;
}

void DroidMemory::setExp(size_t exp) {
  this->_exp = exp;
}

size_t DroidMemory::getFingerprint() const {
  return this->_fingerprint;
}

void DroidMemory::setFingerprint(size_t fingerprint) {
  this->_fingerprint = fingerprint;
}

DroidMemory &DroidMemory::operator<<(const DroidMemory &rhs) {
  this->_exp += rhs._exp;
  this->_fingerprint ^= rhs._fingerprint;
  return *this;
}

DroidMemory &DroidMemory::operator>>(DroidMemory &rhs) {
  rhs._exp += this->_exp;
  rhs._fingerprint ^= this->_fingerprint;
  return *this;
}

DroidMemory &DroidMemory::operator+=(DroidMemory &rhs) {
  this->_exp += rhs._exp;
  this->_fingerprint ^= rhs._fingerprint;
  return *this;
}

DroidMemory &DroidMemory::operator+=(const size_t exp) {
  this->_exp += exp;
  this->_fingerprint ^= exp;
  return *this;
}

DroidMemory DroidMemory::operator+(DroidMemory &rhs) {
  DroidMemory new_mem;

  new_mem._exp = this->_exp + rhs._exp;
  new_mem._fingerprint = this->_fingerprint ^ rhs._fingerprint;
  return new_mem;
}

DroidMemory DroidMemory::operator+(const size_t exp) {
  DroidMemory new_mem;

  new_mem._exp = this->_exp + exp;
  new_mem._fingerprint = this->_fingerprint ^ exp;
  return new_mem;
}

std::ostream &operator<<(std::ostream& lhs, const DroidMemory& rhs) {
  return lhs << "DroidMemory '" << rhs.getFingerprint() << "', " << rhs.getExp(); 
}

DroidMemory &DroidMemory::operator=(const DroidMemory &copy) {
  this->_exp = copy._exp;
  this->_fingerprint = copy._fingerprint;
  
  return *this;
}

bool operator==(const DroidMemory &lhs, const DroidMemory &rhs) {
  return (lhs.getFingerprint() == rhs.getFingerprint()) && (lhs.getExp() == rhs.getExp());
}

bool operator!=(const DroidMemory &lhs, const DroidMemory &rhs) {
  return !operator==(lhs, rhs);
}

bool operator<(const DroidMemory &lhs, const DroidMemory &rhs) {
  return lhs.getExp() < rhs.getExp();
}

bool operator<(const DroidMemory &lhs, const size_t rhs) {
  return lhs.getExp() < rhs;
}

bool operator<(const size_t lhs, const DroidMemory &rhs) {
  return lhs < rhs.getExp();
}


bool operator>(const DroidMemory &lhs, const DroidMemory &rhs) {
  return lhs.getExp() > rhs.getExp();
}

bool operator>(const DroidMemory &lhs, const size_t rhs) {
  return lhs.getExp() > rhs;
}

bool operator>(const size_t lhs, const DroidMemory &rhs) {
  return lhs > rhs.getExp();
}


bool operator<=(const DroidMemory &lhs, const DroidMemory &rhs) {
  return lhs.getExp() <= rhs.getExp();
}

bool operator<=(const DroidMemory &lhs, const size_t rhs) {
  return lhs.getExp() <= rhs;
}

bool operator<=(const size_t lhs, const DroidMemory &rhs) {
  return lhs <= rhs.getExp();
}

bool operator>=(const DroidMemory &lhs, const DroidMemory &rhs) {
  return lhs.getExp() >= rhs.getExp();
}

bool operator>=(const DroidMemory &lhs, const size_t rhs) {
  return lhs.getExp() >= rhs;
}

bool operator>=(const size_t lhs, const DroidMemory &rhs) {
  return lhs >= rhs.getExp();
}
