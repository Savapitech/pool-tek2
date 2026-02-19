#pragma once

#include <string>

#include "Cyberman.hpp"

namespace Mondas {
  class Human {
    std::string _name;
    unsigned int _iq;
    Mondas::Cyberman::Inhibitor *_inhibitor;
    
    public:
      Human(std::string name, Mondas::Cyberman::Inhibitor *inhibitor);
      Human(std::string name, unsigned int iq = 192, Mondas::Cyberman::Inhibitor *inhibitor = nullptr);
      ~Human();
      std::string getName() const;
      unsigned int getIq() const;
      void setIq(unsigned int newIq);
      void think() const;
      void setInhibitor(Mondas::Cyberman::Inhibitor *inhibitor);
      Mondas::Cyberman::Inhibitor *getInhibitor();
  };
}
