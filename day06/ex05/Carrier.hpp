#pragma once

#include <string>
#include <ostream>
#include "Droid.hpp"

class Carrier {
  std::string _id;
  size_t _energy;
  const size_t _attack;
  const size_t _toughness;
  size_t _speed;
  Droid *_droids[5];

  void updateSpeed();

  public:
    Carrier(const std::string &id);
    Carrier();
    ~Carrier();
    Carrier(const Carrier &) = delete;
    Carrier &operator=(const Carrier &) = delete;
    
    std::string getId() const;
    void setId(const std::string &id);
    size_t getEnergy() const;
    void setEnergy(size_t energy);
    size_t getAttack() const;
    size_t getToughness() const;
    size_t getSpeed() const;
    
    Carrier &operator<<(Droid *&droid);
    Carrier &operator>>(Droid *&droid);
    Droid *&operator[](size_t index);
    Droid * const &operator[](size_t index) const;
    Carrier &operator~();
    bool operator()(int x, int y);
    Carrier &operator<<(size_t &energy);
};

std::ostream &operator<<(std::ostream &os, const Carrier &carrier);
