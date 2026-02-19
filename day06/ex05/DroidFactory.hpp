#pragma once

#include <cstddef>
#include <ostream>
#include "Droid.hpp"
#include "Supply.hpp"

class DroidFactory {
  private:
    size_t _iron;
    size_t _silicon;
    size_t _exp;
    size_t _ratio;

  public:
    explicit DroidFactory(size_t ratio = 2);
    DroidFactory(const DroidFactory &other);
    DroidFactory &operator=(const DroidFactory &other);
    ~DroidFactory();

    size_t getIron() const;
    size_t getSilicon() const;
    size_t getExp() const;
    size_t getRatio() const;

    DroidFactory &operator<<(Supply &supply);
    DroidFactory &operator>>(Droid *&droid);
    DroidFactory &operator++();
    DroidFactory operator++(int);
    DroidFactory &operator--();
    DroidFactory operator--(int);
};

std::ostream &operator<<(std::ostream &os, const DroidFactory &factory);
DroidFactory &operator>>(Supply &supply, DroidFactory &factory);
