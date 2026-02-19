#pragma once

#include "ICharacter.hpp"

class Peasant : public ICharacter {
  protected:
    int _health = 100;
    int _power;
    std::string _name;

  public:
    Peasant(const std::string& name, int power);
    ~Peasant();
    const std::string &getName() const;
    int attack();
    int getHp() const;
    int getPower() const;
    int special();
    void damage(int damage);
    void rest();
};
