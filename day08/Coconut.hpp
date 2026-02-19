#pragma once

#include "ANut.hpp"

class Coconut : public ANut {
  public:
    Coconut();
    ~Coconut() = default;
    IFruit *clone() const override;
};
