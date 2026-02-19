#pragma once

#include <cstddef>
#include <ostream>
#include "Droid.hpp"

class Supply {
  public:
    enum Types {
      Iron = 1,
      Silicon = 2,
      Wreck = 3
    };

  private:
    Types _type;
    size_t _amount;
    Droid **_wrecks;
    size_t _currentIndex;

  public:
    Supply(Types type, size_t amount);
    Supply(Types type, size_t amount, Droid **wrecks);
    ~Supply();
    Supply(const Supply &) = delete;
    Supply &operator=(const Supply &) = delete;

    Types getType() const;
    size_t getAmount() const;
    
    Droid *&operator*() const;
    Droid *operator->() const;
    Supply &operator++();
    Supply &operator--();
    operator size_t() const;
    Supply &operator!();
    bool operator==(Types type) const;
    bool operator!=(Types type) const;
};

std::ostream &operator<<(std::ostream &os, const Supply &supply);
