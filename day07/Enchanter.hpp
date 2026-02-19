#pragma once

#include "Peasant.hpp"

class Enchanter : virtual public Peasant {
  public:
    Enchanter(const std::string &name, int power);
    ~Enchanter();
    int attack();
    int special();
    void rest();
};
