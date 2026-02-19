#pragma once

#include "Human.hpp"

namespace Mondas {
  class Cyberleader {
    Mondas::Human &_human;
    std::string _name;

    public:
      Cyberleader(Mondas::Human &human);
      ~Cyberleader();
      void upgrade(Mondas::Cyberman &cyberman);
      void upgrade(Mondas::Cyberman::Inhibitor &inhibitor);
      void upgrade(Mondas::Human &human);
      std::string getName();
  };
}
