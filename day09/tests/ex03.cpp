
void touch(IObject *object) {
  if (object != nullptr)
    object->touch();
}

int main(void) {
  try {
    List list;

    list.pushBack(new TestObject("Kermit"));
    list.pushBack(new TestObject("Miss Piggy"));
    list.pushFront(nullptr);
    list.front() = new TestObject("Fozzie");
    list.pushBack(nullptr);
    list.forEach(touch);
    list.clear();
    list.popBack();
    list.pushFront(new TestObject("Gonzo"));
  } catch (const List::InvalidOperationException &e) {
    std::cout << "Invalid operation on a list" << std::endl;
  }
  return 0;
}
