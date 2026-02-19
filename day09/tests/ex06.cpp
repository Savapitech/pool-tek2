
UniquePointer createObject(const std::string &name) {
  UniquePointer ptr = new TestObject(name);

  return ptr;
}

int main(void) {
  UniquePointer ptr1 = createObject("Charles de Gaulle");
  UniquePointer ptr2 = createObject("Georges Pompidou");
  // UniquePointer ptr3 = ptr1; <- Does not compile

  {
    UniquePointer tmp(new TestObject("Valery Giscard D'Estaing"));

    // ptr1 = tmp; <- Does not compile
    ptr1 = std::move(tmp);
  }
  ptr2 = UniquePointer(new TestObject("Francois Mitterrand"));
  ptr1.reset(new TestObject("Jacques Chirac"));
  ptr1->touch();
  return 0;
}
