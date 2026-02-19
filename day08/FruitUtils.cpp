#include "FruitUtils.hpp"
#include "ABerry.hpp"
#include "ACitrus.hpp"
#include "Lemon.hpp"

void FruitUtils::sort(FruitBox &unsorted, FruitBox &lemon, FruitBox &citrus, FruitBox &berry) {
  IFruit *fruit;

  for (size_t i = unsorted.nbFruits(); i; i--) {
    fruit = unsorted.popFruit();
    if (dynamic_cast<Lemon *>(fruit) != nullptr) {
      if (!lemon.pushFruit(fruit))
        unsorted.pushFruit(fruit);
    } else if (dynamic_cast<ACitrus *>(fruit) != nullptr) {
      if (!citrus.pushFruit(fruit))
        unsorted.pushFruit(fruit);
    } else if (dynamic_cast<ABerry *>(fruit) != nullptr) {
      if (!berry.pushFruit(fruit))
        unsorted.pushFruit(fruit);
    } else
      unsorted.pushFruit(fruit);
  }
}

FruitBox **FruitUtils::pack(IFruit **fruits, unsigned int boxSize) {
  if (fruits == nullptr || boxSize == 0)
    return nullptr;
  
  unsigned int fruitCount = 0;
  while (fruits[fruitCount] != nullptr)
    fruitCount++;
  
  unsigned int boxCount = (fruitCount + boxSize - 1) / boxSize;
  
  FruitBox **boxes = new FruitBox *[boxCount + 1];
  boxes[boxCount] = nullptr;
  
  unsigned int currentFruit = 0;
  for (unsigned int i = 0; i < boxCount; i++) {
    boxes[i] = new FruitBox(boxSize);
    
    for (unsigned int j = 0; j < boxSize && currentFruit < fruitCount; j++) {
      boxes[i]->pushFruit(fruits[currentFruit]);
      currentFruit++;
    }
  }
  
  return boxes;
}

IFruit **FruitUtils::unpack(FruitBox **fruitBoxes) {
  if (fruitBoxes == nullptr)
    return nullptr;
  
  unsigned int totalFruits = 0;
  for (unsigned int i = 0; fruitBoxes[i] != nullptr; i++)
    totalFruits += fruitBoxes[i]->nbFruits();
  
  IFruit **fruits = new IFruit *[totalFruits + 1];
  fruits[totalFruits] = nullptr;
  
  unsigned int currentFruit = 0;
  for (unsigned int i = 0; fruitBoxes[i] != nullptr; i++) {
    while (fruitBoxes[i]->nbFruits() > 0) {
      fruits[currentFruit] = fruitBoxes[i]->popFruit();
      currentFruit++;
    }
  }
  
  return fruits;
}
