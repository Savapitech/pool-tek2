#include "Supply.hpp"
#include <iostream>

Supply::Supply(Types type, size_t amount) : _type(type), _amount(amount), _wrecks(nullptr), _currentIndex(0) {
}

Supply::Supply(Types type, size_t amount, Droid **wrecks) : _type(type), _amount(amount), _wrecks(wrecks), _currentIndex(0) {
}

Supply::~Supply() {
  if (_wrecks != nullptr) {
    for (size_t i = 0; i < _amount; i++)
      if (_wrecks[i] != nullptr)
        delete _wrecks[i];
    delete[] _wrecks;
  }
}

Supply::Types Supply::getType() const {
  return _type;
}

size_t Supply::getAmount() const {
  return _amount;
}

Droid *&Supply::operator*() const {
  static Droid *null_ptr = nullptr;
  if (_wrecks == nullptr || _amount == 0)
    return null_ptr;
  return _wrecks[_currentIndex];
}

Droid *Supply::operator->() const {
  if (_wrecks == nullptr || _amount == 0)
    return nullptr;
  return _wrecks[_currentIndex];
}

Supply &Supply::operator++() {
  if (_wrecks != nullptr && _amount > 0)
    _currentIndex = (_currentIndex + 1) % _amount;
  return *this;
}

Supply &Supply::operator--() {
  if (_wrecks != nullptr && _amount > 0) {
    if (_currentIndex == 0) {
      _currentIndex = _amount - 1;
    } else {
      _currentIndex--;
    }
  }
  return *this;
}

Supply::operator size_t() const {
  return _amount;
}

Supply &Supply::operator!() {
  if (_wrecks != nullptr) {
    for (size_t i = 0; i < _amount; i++) {
      if (_wrecks[i] != nullptr) {
        delete _wrecks[i];
        _wrecks[i] = nullptr;
      }
    }
  }
  _amount = 0;
  return *this;
}

bool Supply::operator==(Types type) const {
  return _type == type;
}

bool Supply::operator!=(Types type) const {
  return _type != type;
}

std::ostream &operator<<(std::ostream &os, const Supply &supply) {
  os << "Supply : " << supply.getAmount() << ", ";
  switch (supply.getType()) {
    case Supply::Iron:
      os << "Iron";
      break;
    case Supply::Silicon:
      os << "Silicon";
      break;
    case Supply::Wreck:
      os << "Wreck";
      if (supply.getAmount() > 0) {
        for (size_t i = 0; i < supply.getAmount(); i++) {
          Supply &tmp = const_cast<Supply&>(supply);
          if (*tmp != nullptr) {
            os << std::endl << *(*tmp);
          }
          ++tmp;
        }
      }
      return os;
  }
  return os;
}
