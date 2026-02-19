
void touch(IObject *object) {
  if (object != nullptr)
    object->touch();
}

int main(void) {
  try {
    List list1;

    list1.pushBack(new TestObject("Naruto"));
    list1.pushBack(new TestObject("Sasuke"));
    list1.pushBack(new TestObject("Sakura"));
    list1.pushBack(nullptr);
    list1.pushBack(new TestObject("Serge"));
    for (List::Iterator it = list1.begin(); it != list1.end(); ++it)
      if (*it != nullptr)
        (*it)->touch();
    list1.erase(list1.erase(list1.begin()));
    list1.insert(list1.begin(), new TestObject("Orochimaru"));
    list1.insert(list1.end(), new TestObject("Tsunade"));
    list1.forEach(touch);

    List list2;

    list2.pushFront(new TestObject("Jiraya"));
    list1.erase(list2.begin());
  } catch (const List::Iterator::OutOfRangeException &e) {
    std::cout << "Iterator out of range" << std::endl;
  } catch (const List::InvalidIteratorException &e) {
    std::cout << "Invalid iterator" << std::endl;
  }

  return 0;
}
