#pragma once

#include "ACitrus.hpp"

class Grapefruit : public ACitrus {
  public:
    Grapefruit();
    ~Grapefruit() = default;
    IFruit *clone() const override;
};
