#pragma once

#include "IFruit.hpp"
#include <map>
#include <string>

class FruitFactory {
  private:
    std::map<std::string, IFruit *> _fruits;

  public:
    FruitFactory() = default;
    ~FruitFactory();

    void registerFruit(IFruit *fruit);
    void unregisterFruit(const std::string &name);
    IFruit *createFruit(const std::string &name) const;
};
