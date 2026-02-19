#pragma once

#include <string>
#include <ostream>

class Droid {
  std::string _id;
  size_t _energy;
  const size_t _attack;
  const size_t _toughness;
  std::string *_status;

  public:
    Droid();
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
};

bool operator==(const Droid &lhs, const Droid &rhs);
bool operator!=(const Droid &lhs, const Droid &rhs);
std::ostream &operator<<(std::ostream& lhs, const Droid& rhs);
