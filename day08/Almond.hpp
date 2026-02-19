#pragma once

#include "ANut.hpp"

class Almond : public ANut {
  public:
    Almond();
    ~Almond() = default;
    IFruit *clone() const override;
};
