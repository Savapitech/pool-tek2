#include "FruitMixer.hpp"

FruitMixer::FruitMixer() : _blade(nullptr) {
}

void FruitMixer::setBlade(IBlade *blade) {
  _blade = blade;
}

unsigned int FruitMixer::mixFruits(FruitBox &box) const {
  if (_blade == nullptr) {
    std::cout << "mixer has no blade" << std::endl;
    return 0;
  }
  
  unsigned int totalVitamins = 0;
  unsigned int nbFruits = box.nbFruits();
  FruitBox tempBox(nbFruits);
  
  for (unsigned int i = 0; i < nbFruits; i++) {
    IFruit *fruit = box.popFruit();
    
    if (fruit->isPeeled()) {
      totalVitamins += (*_blade)(*fruit);
      delete fruit;
    } else {
      tempBox.pushFruit(fruit);
    }
  }
  
  while (tempBox.nbFruits() > 0) {
    box.pushFruit(tempBox.popFruit());
  }
  
  return totalVitamins;
}
