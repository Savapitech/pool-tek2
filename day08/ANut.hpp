#pragma once

#include "AFruit.hpp"

class ANut : public AFruit {
  public:
    ~ANut() = default;

  protected:
    ANut(std::string name, unsigned int vitamins);
};
