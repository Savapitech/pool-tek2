#pragma once

#include "Peasant.hpp"

class Knight : virtual public Peasant {
  public:
    Knight(const std::string& name, int power);
    int attack();
    int special();
    void rest();
    ~Knight();
};
