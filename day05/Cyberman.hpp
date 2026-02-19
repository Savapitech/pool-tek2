#pragma once

#include <string>

namespace Mondas {
  class Human;

  class Cyberman {
    Mondas::Human &_human;
    std::string _name;

    public:
      Cyberman(Mondas::Human &human);
      ~Cyberman();
      Mondas::Human &getHuman();
      const Mondas::Human &getHuman() const;
      std::string getName() const;
      void think() const;
      unsigned int getIq() const;

      class Inhibitor {
        bool _activated;

        public:
          Inhibitor();
          ~Inhibitor() = default;
          void set(bool value);
          bool get();
      };
  };
}

std::string leet_convert(const std::string &input);
