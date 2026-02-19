
int main(void) {
  SharedPointer ptr1;
  SharedPointer ptr2(new TestObject("O'Neill"));
  SharedPointer ptr3(ptr2);

  ptr1 = ptr3;
  ptr2->touch();
  std::cout << ptr1.use_count() << std::endl;
  ptr1.reset(new TestObject("Carter"));
  std::cout << ptr1.use_count() << std::endl;
  ptr3.swap(ptr1);
  (*ptr3).touch();
  ptr1.reset();
  std::cout << ptr1.use_count() << std::endl;
  ptr2 = new TestObject("Jackson");
  return 0;
}
