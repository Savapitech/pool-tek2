#pragma once

#include "AFruit.hpp"

class ACitrus : public AFruit {
  public:
    ~ACitrus() = default;

  protected:
    ACitrus(std::string name, unsigned int vitamins);
};
