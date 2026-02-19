#include "FruitBox.hpp"
#include "IFruit.hpp"

FruitBox::FruitBox(unsigned int size) {
  this->_size = size;
}

FruitBox::~FruitBox() {
  for (auto fruit : this->_queue)
    delete fruit;
}

bool FruitBox::pushFruit(IFruit *fruit) {
  if (this->_queue.size() >= this->_size)
    return false;
  for (auto qfruit : this->_queue)
    if (fruit == qfruit)
      return false;
  this->_queue.push_back(fruit);
  return true;
}

IFruit *FruitBox::popFruit() {
  if (this->_queue.empty())
    return nullptr;
  
  IFruit *front = this->_queue.front();
  this->_queue.pop_front();
  return front;
}

unsigned int FruitBox::getSize() const {
  return this->_size;
}

unsigned int FruitBox::nbFruits() const {
  return this->_queue.size();
}

std::deque <IFruit *> FruitBox::getQueue() const {
  return this->_queue;
}

std::ostream &operator<<(std::ostream &os, const FruitBox &rhs) {
  os << "[";
  const auto &queue = rhs.getQueue();
  for (size_t i = 0; i < queue.size(); i++)
    os << *queue[i] << (i < queue.size() - 1 ? ", " : "");
  os << "]";
  return os;
}
