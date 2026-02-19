#pragma once

#include "FruitBox.hpp"

class FruitUtils {
  public:
    FruitUtils() = default;
    ~FruitUtils() = default;
    static void sort(FruitBox &unsorted, FruitBox &lemon, FruitBox &citrus, FruitBox &berry);
    static FruitBox **pack(IFruit **fruits, unsigned int boxSize);
    static IFruit **unpack(FruitBox **fruitBoxes);
};
