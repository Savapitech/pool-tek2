#pragma once

#include <iostream>
#include <cstddef>

class DroidMemory {
  size_t _fingerprint;
  size_t _exp;

  public:
    DroidMemory();
    DroidMemory(const DroidMemory &droid);
    ~DroidMemory() = default;
    size_t getFingerprint() const;
    void setFingerprint(size_t fingerprint);
    size_t getExp() const;
    void setExp(size_t exp);
    DroidMemory &operator<<(const DroidMemory &rhs);
    DroidMemory &operator>>(DroidMemory &rhs);
    DroidMemory &operator+=(DroidMemory &rhs);
    DroidMemory &operator+=(size_t exp);
    DroidMemory operator+(DroidMemory &rhs);
    DroidMemory operator+(const size_t exp);
    DroidMemory &operator=(const DroidMemory &copy);
};

std::ostream &operator<<(std::ostream& lhs, const DroidMemory& rhs);
