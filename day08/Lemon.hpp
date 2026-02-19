#pragma once

#include "ACitrus.hpp"

class Lemon : public ACitrus {
  public:
    Lemon();
    ~Lemon() = default;
    IFruit *clone() const override;
};
