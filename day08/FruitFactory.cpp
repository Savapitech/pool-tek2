#include "FruitFactory.hpp"

FruitFactory::~FruitFactory() {
  for (auto &pair : _fruits) {
    delete pair.second;
  }
}

void FruitFactory::registerFruit(IFruit *fruit) {
  if (fruit == nullptr)
    return;
  
  std::string name = fruit->getName();
  
  if (_fruits.find(name) != _fruits.end()) {
    delete _fruits[name];
  }
  
  _fruits[name] = fruit;
}

void FruitFactory::unregisterFruit(const std::string &name) {
  auto it = _fruits.find(name);
  
  if (it != _fruits.end()) {
    delete it->second;
    _fruits.erase(it);
  }
}

IFruit *FruitFactory::createFruit(const std::string &name) const {
  auto it = _fruits.find(name);
  
  if (it != _fruits.end()) {
    return it->second->clone();
  }
  
  return nullptr;
}
