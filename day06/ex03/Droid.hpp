#pragma once

#include <string>
#include <ostream>

#include "DroidMemory.hpp"

class Droid {
  std::string _id;
  size_t _energy;
  const size_t _attack;
  const size_t _toughness;
  std::string *_status;
  DroidMemory *_battledata;

  public:
    Droid(const std::string id);
    Droid(const Droid &droid);
    Droid &operator=(const Droid &copy);
    ~Droid();
    std::string getId() const;
    void setId(const std::string id);
    size_t getEnergy() const;
    void setEnergy(const size_t energy);
    size_t getAttack() const;
    size_t getToughness() const;
    std::string *getStatus() const;
    void setStatus(std::string *status);
    Droid &operator<<(size_t &rhs);
    DroidMemory *getBattleData() const;
    void setBattleData(DroidMemory *battledata);
    bool operator()(const std::string *task, const size_t exp);
};

bool operator==(const Droid &lhs, const Droid &rhs);
bool operator!=(const Droid &lhs, const Droid &rhs);
std::ostream &operator<<(std::ostream& lhs, const Droid& rhs);
