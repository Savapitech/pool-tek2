#pragma once

#include "ABerry.hpp"

class Raspberry : public ABerry {
  public:
    Raspberry();
    ~Raspberry() = default;
    IFruit *clone() const override;
};
