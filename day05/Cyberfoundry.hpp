#pragma once

#include "Cyberleader.hpp"

namespace Mondas {
  class Cyberfoundry {
    unsigned int &_energy;

    public:
      Cyberfoundry(unsigned int &energy);
      ~Cyberfoundry();
      Mondas::Cyberman* buildCyberman(Mondas::Human &human);
      Mondas::Cyberleader* buildCyberleader(Mondas::Human &human);
      void recycle(Mondas::Cyberman*&);
      void recycle(Mondas::Cyberleader*&);
  };
}
