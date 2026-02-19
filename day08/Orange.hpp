#pragma once

#include "ACitrus.hpp"

class Orange : public ACitrus {
  public:
    Orange();
    ~Orange() = default;
    IFruit *clone() const override;
};
