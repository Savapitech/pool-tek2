#pragma once

#include "AFruit.hpp"

class ABerry : public AFruit {
  protected:
    ABerry(std::string name, unsigned int vitamins);

  public:
    ~ABerry() = default;
    void peel() override;
};
