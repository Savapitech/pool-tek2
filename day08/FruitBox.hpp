#pragma once

#include <deque>

#include "IFruit.hpp"

class FruitBox {
  private:
    unsigned int _size;
    std::deque <IFruit *> _queue;

  public:
    FruitBox(unsigned int size);
    FruitBox(FruitBox &box) = delete;
    ~FruitBox();
    unsigned int getSize() const;
    unsigned int nbFruits() const;
    bool pushFruit(IFruit *fruit);
    IFruit *popFruit();
    std::deque <IFruit *> getQueue() const;
};

std::ostream &operator<<(std::ostream &os, const FruitBox &rhs);
