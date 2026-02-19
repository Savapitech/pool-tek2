#pragma once

#include "ABerry.hpp"

class Strawberry : public ABerry {
  public:
    Strawberry();
    ~Strawberry() = default;
    IFruit *clone() const override;
};
