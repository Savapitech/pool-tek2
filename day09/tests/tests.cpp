#include "../DirectoryLister.hpp"
#include "../List.hpp"
#include "../SafeDirectoryLister.hpp"
#include "../SharedPointer.hpp"
#include "../UniquePointer.hpp"
#include "TestObject.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <fstream>
#include <sstream>

void redirect_all_stdout(void) {
  cr_redirect_stdout();
  cr_redirect_stderr();
}

static void touch_obj(IObject *obj) {
  if (obj)
    obj->touch();
}

Test(DirectoryLister, basic_constructor, .timeout = 5) {
  DirectoryLister dl;
  cr_assert_eq(dl.get(), "");
}

Test(DirectoryLister, constructor_with_path, .timeout = 5) {
  DirectoryLister dl("./tests/test00", false);
  std::string file = dl.get();
  cr_assert_neq(file, "");
}

Test(DirectoryLister, open_invalid_path, .init = redirect_all_stdout,
     .timeout = 5) {
  DirectoryLister dl;
  bool result = dl.open("invalid_path_xyz", false);
  cr_assert_eq(result, false);
}

Test(DirectoryLister, open_valid_path, .timeout = 5) {
  DirectoryLister dl;
  bool result = dl.open("./tests/test00", false);
  cr_assert_eq(result, true);
}

Test(DirectoryLister, get_without_open, .timeout = 5) {
  DirectoryLister dl;
  cr_assert_eq(dl.get(), "");
}

Test(DirectoryLister, get_files_no_hidden, .timeout = 5) {
  DirectoryLister dl("./tests/test00", false);
  std::vector<std::string> files;

  for (std::string file = dl.get(); !file.empty(); file = dl.get()) {
    files.push_back(file);
    cr_assert_neq(file[0], '.');
  }
  cr_assert_geq(files.size(), 1);
}

Test(DirectoryLister, get_files_with_hidden, .timeout = 5) {
  DirectoryLister dl("./tests/test00", true);
  std::vector<std::string> files;
  bool found_hidden = false;

  for (std::string file = dl.get(); !file.empty(); file = dl.get()) {
    files.push_back(file);
    if (file[0] == '.')
      found_hidden = true;
  }
  cr_assert(found_hidden);
}

Test(DirectoryLister, reopen_directory, .timeout = 5) {
  DirectoryLister dl("./tests/test00", false);
  std::string first = dl.get();

  dl.open("./tests/test00", false);
  std::string second = dl.get();

  cr_assert_neq(first, "");
  cr_assert_neq(second, "");
}

Test(DirectoryLister, close_on_invalid_open, .init = redirect_all_stdout,
     .timeout = 5) {
  DirectoryLister dl("./tests/test00", false);
  dl.open("invalid_path", false);
  cr_assert_eq(dl.get(), "");
}

Test(SafeDirectoryLister, basic_constructor, .timeout = 5) {
  SafeDirectoryLister dl;
  try {
    dl.get();
    cr_assert_fail("Should have thrown NoMoreFileException");
  } catch (const IDirectoryLister::NoMoreFileException &e) {
    cr_assert_str_eq(e.what(), "End of stream");
  }
}

Test(SafeDirectoryLister, constructor_with_valid_path, .timeout = 5) {
  SafeDirectoryLister dl("./tests/test00", false);
  std::string file = dl.get();
  cr_assert_neq(file, "");
}

Test(SafeDirectoryLister, constructor_with_invalid_path, .timeout = 5) {
  try {
    SafeDirectoryLister dl("invalid_path_xyz", false);
    cr_assert_fail("Should have thrown OpenFailureException");
  } catch (const IDirectoryLister::OpenFailureException &e) {
    cr_assert_neq(e.what(), nullptr);
  }
}

Test(SafeDirectoryLister, open_invalid_path_throws, .timeout = 5) {
  SafeDirectoryLister dl;
  try {
    dl.open("invalid_path_xyz", false);
    cr_assert_fail("Should have thrown OpenFailureException");
  } catch (const IDirectoryLister::OpenFailureException &e) {
    cr_assert_neq(e.what(), nullptr);
  }
}

Test(SafeDirectoryLister, get_throws_on_end, .timeout = 5) {
  SafeDirectoryLister dl("./tests/test00", false);

  try {
    while (true) {
      dl.get();
    }
  } catch (const IDirectoryLister::NoMoreFileException &e) {
    cr_assert_str_eq(e.what(), "End of stream");
  }
}

Test(SafeDirectoryLister, open_always_returns_true, .timeout = 5) {
  SafeDirectoryLister dl;
  bool result = dl.open("./tests/test00", false);
  cr_assert_eq(result, true);
}

Test(SafeDirectoryLister, exception_hierarchy, .timeout = 5) {
  try {
    SafeDirectoryLister dl("invalid_path", false);
    cr_assert_fail();
  } catch (const std::exception &e) {
    cr_assert_neq(e.what(), nullptr);
  }
}

Test(UniquePointer, default_constructor, .init = redirect_all_stdout,
     .timeout = 5) {
  UniquePointer ptr;
}

Test(UniquePointer, constructor_with_object, .init = redirect_all_stdout,
     .timeout = 5) {
  UniquePointer ptr(new TestObject("test"));
}

Test(UniquePointer, destructor_deletes_object, .init = redirect_all_stdout,
     .timeout = 5) {
  {
    UniquePointer ptr(new TestObject("test"));
  }
}

Test(UniquePointer, arrow_operator, .init = redirect_all_stdout, .timeout = 5) {
  UniquePointer ptr(new TestObject("test"));
  ptr->touch();
}

Test(UniquePointer, dereference_operator, .init = redirect_all_stdout,
     .timeout = 5) {
  UniquePointer ptr(new TestObject("test"));
  (*ptr).touch();
}

Test(UniquePointer, assignment_operator, .init = redirect_all_stdout,
     .timeout = 5) {
  UniquePointer ptr;
  ptr = new TestObject("test");
}

Test(UniquePointer, assignment_deletes_old, .init = redirect_all_stdout,
     .timeout = 5) {
  UniquePointer ptr(new TestObject("first"));
  ptr = new TestObject("second");
}

Test(UniquePointer, reset_without_param, .init = redirect_all_stdout,
     .timeout = 5) {
  UniquePointer ptr(new TestObject("test"));
  ptr.reset();
}

Test(UniquePointer, reset_with_param, .init = redirect_all_stdout,
     .timeout = 5) {
  UniquePointer ptr(new TestObject("first"));
  ptr.reset(new TestObject("second"));
}

Test(UniquePointer, swap, .init = redirect_all_stdout, .timeout = 5) {
  UniquePointer ptr1(new TestObject("first"));
  UniquePointer ptr2(new TestObject("second"));
  ptr1.swap(ptr2);
  ptr1->touch();
  ptr2->touch();
}

Test(List, default_constructor, .timeout = 5) {
  List list;
  cr_assert(list.empty());
  cr_assert_eq(list.size(), 0);
}

Test(List, pushBack, .init = redirect_all_stdout, .timeout = 5) {
  List list;
  list.pushBack(new TestObject("test"));
  cr_assert_not(list.empty());
  cr_assert_eq(list.size(), 1);
}

Test(List, pushFront, .init = redirect_all_stdout, .timeout = 5) {
  List list;
  list.pushFront(new TestObject("test"));
  cr_assert_not(list.empty());
  cr_assert_eq(list.size(), 1);
}

Test(List, front, .init = redirect_all_stdout, .timeout = 5) {
  List list;
  TestObject *obj = new TestObject("test");
  list.pushBack(obj);
  cr_assert_eq(list.front(), obj);
}

Test(List, back, .init = redirect_all_stdout, .timeout = 5) {
  List list;
  TestObject *obj = new TestObject("test");
  list.pushBack(obj);
  cr_assert_eq(list.back(), obj);
}

Test(List, front_modifiable, .init = redirect_all_stdout, .timeout = 5) {
  List list;
  list.pushBack(nullptr);
  list.front() = new TestObject("new");
  cr_assert_neq(list.front(), nullptr);
}

Test(List, back_modifiable, .init = redirect_all_stdout, .timeout = 5) {
  List list;
  list.pushBack(nullptr);
  list.back() = new TestObject("new");
  cr_assert_neq(list.back(), nullptr);
}

Test(List, popFront, .init = redirect_all_stdout, .timeout = 5) {
  List list;
  list.pushBack(new TestObject("test"));
  list.popFront();
  cr_assert(list.empty());
}

Test(List, popBack, .init = redirect_all_stdout, .timeout = 5) {
  List list;
  list.pushBack(new TestObject("test"));
  list.popBack();
  cr_assert(list.empty());
}

Test(List, clear, .init = redirect_all_stdout, .timeout = 5) {
  List list;
  list.pushBack(new TestObject("test1"));
  list.pushBack(new TestObject("test2"));
  list.clear();
  cr_assert(list.empty());
}

Test(List, forEach, .init = redirect_all_stdout, .timeout = 5) {
  List list;
  TestObject *obj1 = new TestObject("test1");
  TestObject *obj2 = new TestObject("test2");
  list.pushBack(obj1);
  list.pushBack(obj2);

  list.forEach(touch_obj);
  fflush(stdout);
}

Test(List, front_on_empty_throws, .timeout = 5) {
  List list;
  try {
    list.front();
    cr_assert_fail("Should throw");
  } catch (const List::InvalidOperationException &e) {
    cr_assert_neq(e.what(), nullptr);
  }
}

Test(List, back_on_empty_throws, .timeout = 5) {
  List list;
  try {
    list.back();
    cr_assert_fail("Should throw");
  } catch (const List::InvalidOperationException &e) {
    cr_assert_neq(e.what(), nullptr);
  }
}

Test(List, popFront_on_empty_throws, .timeout = 5) {
  List list;
  try {
    list.popFront();
    cr_assert_fail("Should throw");
  } catch (const List::InvalidOperationException &e) {
    cr_assert_neq(e.what(), nullptr);
  }
}

Test(List, popBack_on_empty_throws, .timeout = 5) {
  List list;
  try {
    list.popBack();
    cr_assert_fail("Should throw");
  } catch (const List::InvalidOperationException &e) {
    cr_assert_neq(e.what(), nullptr);
  }
}

Test(List, multiple_operations, .init = redirect_all_stdout, .timeout = 5) {
  List list;
  list.pushBack(new TestObject("1"));
  list.pushFront(new TestObject("2"));
  list.pushBack(new TestObject("3"));
  cr_assert_eq(list.size(), 3);
  list.popFront();
  cr_assert_eq(list.size(), 2);
}

Test(List, nullptr_handling, .timeout = 5) {
  List list;
  list.pushBack(nullptr);
  cr_assert_eq(list.front(), nullptr);
  list.popBack();
  cr_assert(list.empty());
}

Test(SharedPointer, default_constructor, .timeout = 5) {
  SharedPointer ptr;
  cr_assert_eq(ptr.use_count(), 0);
}

Test(SharedPointer, constructor_with_object, .init = redirect_all_stdout,
     .timeout = 5) {
  SharedPointer ptr(new TestObject("test"));
  cr_assert_eq(ptr.use_count(), 1);
}

Test(SharedPointer, copy_constructor, .init = redirect_all_stdout,
     .timeout = 5) {
  SharedPointer ptr1(new TestObject("test"));
  SharedPointer ptr2(ptr1);
  cr_assert_eq(ptr1.use_count(), 2);
  cr_assert_eq(ptr2.use_count(), 2);
}

Test(SharedPointer, copy_assignment, .init = redirect_all_stdout,
     .timeout = 5) {
  SharedPointer ptr1(new TestObject("test"));
  SharedPointer ptr2;
  ptr2 = ptr1;
  cr_assert_eq(ptr1.use_count(), 2);
  cr_assert_eq(ptr2.use_count(), 2);
}

Test(SharedPointer, arrow_operator, .init = redirect_all_stdout, .timeout = 5) {
  SharedPointer ptr(new TestObject("test"));
  ptr->touch();
}

Test(SharedPointer, dereference_operator, .init = redirect_all_stdout,
     .timeout = 5) {
  SharedPointer ptr(new TestObject("test"));
  (*ptr).touch();
}

Test(SharedPointer, reset, .init = redirect_all_stdout, .timeout = 5) {
  SharedPointer ptr(new TestObject("test"));
  ptr.reset();
  cr_assert_eq(ptr.use_count(), 0);
}

Test(SharedPointer, reset_with_param, .init = redirect_all_stdout,
     .timeout = 5) {
  SharedPointer ptr(new TestObject("first"));
  ptr.reset(new TestObject("second"));
  cr_assert_eq(ptr.use_count(), 1);
}

Test(SharedPointer, swap, .init = redirect_all_stdout, .timeout = 5) {
  SharedPointer ptr1(new TestObject("first"));
  SharedPointer ptr2(new TestObject("second"));
  ptr1.swap(ptr2);
  ptr1->touch();
  ptr2->touch();
  fflush(stdout);
}

Test(SharedPointer, destructor_with_shared, .init = redirect_all_stdout,
     .timeout = 5) {
  SharedPointer ptr1(new TestObject("test"));
  {
    SharedPointer ptr2(ptr1);
    cr_assert_eq(ptr1.use_count(), 2);
  }
  cr_assert_eq(ptr1.use_count(), 1);
}

Test(SharedPointer, multiple_copies, .init = redirect_all_stdout,
     .timeout = 5) {
  SharedPointer ptr1(new TestObject("test"));
  SharedPointer ptr2(ptr1);
  SharedPointer ptr3(ptr2);
  SharedPointer ptr4 = ptr3;
  cr_assert_eq(ptr1.use_count(), 4);
}

Test(SharedPointer, assignment_to_new, .init = redirect_all_stdout,
     .timeout = 5) {
  SharedPointer ptr;
  ptr = new TestObject("test");
  cr_assert_eq(ptr.use_count(), 1);
}

Test(ListIterator, begin_end, .init = redirect_all_stdout, .timeout = 5) {
  List list;
  list.pushBack(new TestObject("test"));
  List::Iterator it = list.begin();
  cr_assert_neq(it, list.end());
}

Test(ListIterator, empty_list, .timeout = 5) {
  List list;
  cr_assert_eq(list.begin(), list.end());
}

Test(ListIterator, dereference, .init = redirect_all_stdout, .timeout = 5) {
  List list;
  TestObject *obj = new TestObject("test");
  list.pushBack(obj);
  List::Iterator it = list.begin();
  cr_assert_eq(*it, obj);
}

Test(ListIterator, increment, .init = redirect_all_stdout, .timeout = 5) {
  List list;
  list.pushBack(new TestObject("test1"));
  list.pushBack(new TestObject("test2"));
  List::Iterator it = list.begin();
  ++it;
  cr_assert_neq(it, list.end());
}

Test(ListIterator, iteration, .init = redirect_all_stdout, .timeout = 5) {
  List list;
  list.pushBack(new TestObject("1"));
  list.pushBack(new TestObject("2"));
  list.pushBack(new TestObject("3"));

  int count = 0;
  for (List::Iterator it = list.begin(); it != list.end(); ++it) {
    count++;
  }
  cr_assert_eq(count, 3);
}

Test(ListIterator, erase, .init = redirect_all_stdout, .timeout = 5) {
  List list;
  list.pushBack(new TestObject("1"));
  list.pushBack(new TestObject("2"));
  List::Iterator it = list.erase(list.begin());
  cr_assert_eq(list.size(), 1);
  cr_assert_neq(it, list.end());
}

Test(ListIterator, insert_at_begin, .init = redirect_all_stdout, .timeout = 5) {
  List list;
  list.pushBack(new TestObject("2"));
  list.insert(list.begin(), new TestObject("1"));
  cr_assert_eq(list.size(), 2);
}

Test(ListIterator, insert_at_end, .init = redirect_all_stdout, .timeout = 5) {
  List list;
  list.pushBack(new TestObject("1"));
  list.insert(list.end(), new TestObject("2"));
  cr_assert_eq(list.size(), 2);
}

Test(ListIterator, invalid_iterator_erase, .init = redirect_all_stdout,
     .timeout = 5) {
  List list1;
  List list2;
  list1.pushBack(new TestObject("1"));
  list2.pushBack(new TestObject("2"));

  try {
    list1.erase(list2.begin());
    cr_assert_fail("Should throw");
  } catch (const List::InvalidIteratorException &e) {
    cr_assert_neq(e.what(), nullptr);
  }
}

Test(ListIterator, invalid_iterator_insert, .init = redirect_all_stdout,
     .timeout = 5) {
  List list1;
  List list2;
  list1.pushBack(new TestObject("1"));

  try {
    list1.insert(list2.begin(), new TestObject("2"));
    cr_assert_fail("Should throw");
  } catch (const List::InvalidIteratorException &e) {
    cr_assert_neq(e.what(), nullptr);
  }
}

Test(ListIterator, dereference_end_throws, .timeout = 5) {
  List list;
  try {
    List::Iterator it = list.end();
    *it;
    cr_assert_fail("Should throw");
  } catch (const List::Iterator::OutOfRangeException &e) {
    cr_assert_neq(e.what(), nullptr);
  }
}

Test(ListIterator, increment_end_throws, .timeout = 5) {
  List list;
  try {
    List::Iterator it = list.end();
    ++it;
    cr_assert_fail("Should throw");
  } catch (const List::Iterator::OutOfRangeException &e) {
    cr_assert_neq(e.what(), nullptr);
  }
}

Test(ListIterator, erase_end_throws, .init = redirect_all_stdout,
     .timeout = 5) {
  List list;
  list.pushBack(new TestObject("1"));
  try {
    list.erase(list.end());
    cr_assert_fail("Should throw");
  } catch (const List::InvalidIteratorException &e) {
    cr_assert_neq(e.what(), nullptr);
  }
}

Test(ListIterator, multiple_erase, .init = redirect_all_stdout, .timeout = 5) {
  List list;
  list.pushBack(new TestObject("1"));
  list.pushBack(new TestObject("2"));
  list.pushBack(new TestObject("3"));

  List::Iterator it = list.begin();
  it = list.erase(it);
  it = list.erase(it);
  cr_assert_eq(list.size(), 1);
}

Test(UniquePtrMove, move_constructor, .init = redirect_all_stdout,
     .timeout = 5) {
  UniquePointer ptr1(new TestObject("test"));
  UniquePointer ptr2(std::move(ptr1));
  ptr2->touch();
}

Test(UniquePtrMove, move_assignment, .init = redirect_all_stdout,
     .timeout = 5) {
  UniquePointer ptr1(new TestObject("test"));
  UniquePointer ptr2;
  ptr2 = std::move(ptr1);
  ptr2->touch();
}

Test(UniquePtrMove, move_from_temp, .init = redirect_all_stdout, .timeout = 5) {
  UniquePointer ptr = UniquePointer(new TestObject("test"));
  ptr->touch();
}

Test(UniquePtrMove, return_from_function, .init = redirect_all_stdout,
     .timeout = 5) {
  auto create = []() {
    UniquePointer ptr = new TestObject("test");
    return ptr;
  };

  UniquePointer result = create();
  result->touch();
}

Test(UniquePtrMove, move_deletes_old, .init = redirect_all_stdout,
     .timeout = 5) {
  UniquePointer ptr1(new TestObject("first"));
  UniquePointer ptr2(new TestObject("second"));
  ptr1 = std::move(ptr2);
  fflush(stdout);
}

Test(UniquePtrMove, implicit_conversion, .init = redirect_all_stdout,
     .timeout = 5) {
  UniquePointer ptr = new TestObject("test");
  ptr->touch();
}

Test(SubjectExamples, ex00_example, .init = redirect_all_stdout, .timeout = 5) {
  DirectoryLister dl("./tests/test00", true);

  for (std::string file = dl.get(); !file.empty(); file = dl.get())
    std::cout << file << std::endl;
  dl.open("invalid path", true);
  if (dl.open("./tests/test00", false) == true)
    for (std::string file = dl.get(); !file.empty(); file = dl.get())
      std::cout << file << std::endl;

  fflush(stdout);
  cr_assert_stdout_neq_str("");
}

Test(SubjectExamples, ex02_example, .init = redirect_all_stdout, .timeout = 5) {
  UniquePointer ptr1;
  UniquePointer ptr2(new TestObject("Eccleston"));

  ptr1 = new TestObject("Tennant");
  ptr2 = new TestObject("Smith");
  ptr1->touch();
  (*ptr2).touch();
  {
    UniquePointer ptr4(new TestObject("Whittaker"));
  }
  ptr1.reset(new TestObject("Capaldi"));
  ptr1.swap(ptr2);
  ptr2.reset();
}

Test(SubjectExamples, ex03_example, .init = redirect_all_stdout, .timeout = 5) {
  try {
    List list;

    list.pushBack(new TestObject("Kermit"));
    list.pushBack(new TestObject("Miss Piggy"));
    list.pushFront(nullptr);
    list.front() = new TestObject("Fozzie");
    list.pushBack(nullptr);
    list.forEach(touch_obj);
    list.clear();
    list.popBack();
    list.pushFront(new TestObject("Gonzo"));
  } catch (const List::InvalidOperationException &e) {
    std::cout << "Invalid operation on a list" << std::endl;
  }
}

Test(SubjectExamples, ex04_example, .init = redirect_all_stdout, .timeout = 5) {
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
}

Test(SubjectExamples, ex05_example, .init = redirect_all_stdout, .timeout = 5) {
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
    list1.forEach(touch_obj);

    List list2;

    list2.pushFront(new TestObject("Jiraya"));
    list1.erase(list2.begin());
  } catch (const List::Iterator::OutOfRangeException &e) {
    std::cout << "Iterator out of range" << std::endl;
  } catch (const List::InvalidIteratorException &e) {
    std::cout << "Invalid iterator" << std::endl;
  }
}

Test(SubjectExamples, ex06_example, .init = redirect_all_stdout, .timeout = 5) {
  auto createObject = [](const std::string &name) {
    UniquePointer ptr = new TestObject(name);
    return ptr;
  };

  UniquePointer ptr1 = createObject("Charles de Gaulle");
  UniquePointer ptr2 = createObject("Georges Pompidou");

  {
    UniquePointer tmp(new TestObject("Valery Giscard D'Estaing"));
    ptr1 = std::move(tmp);
  }
  ptr2 = UniquePointer(new TestObject("Francois Mitterrand"));
  ptr1.reset(new TestObject("Jacques Chirac"));
  ptr1->touch();
}

Test(EdgeCases, directory_lister_empty_after_invalid,
     .init = redirect_all_stdout, .timeout = 5) {
  DirectoryLister dl("./tests/test00", false);
  dl.open("nonexistent", false);
  cr_assert_eq(dl.get(), "");
}

Test(EdgeCases, list_order_preserved, .init = redirect_all_stdout,
     .timeout = 5) {
  List list;
  list.pushBack(new TestObject("1"));
  list.pushBack(new TestObject("2"));
  list.pushBack(new TestObject("3"));

  std::vector<std::string> names;
  for (List::Iterator it = list.begin(); it != list.end(); ++it) {
    if (*it)
      names.push_back("item");
  }
  cr_assert_eq(names.size(), 3);
}

Test(EdgeCases, shared_pointer_self_assignment, .init = redirect_all_stdout,
     .timeout = 5) {
  SharedPointer ptr(new TestObject("test"));
  ptr = ptr;
  cr_assert_eq(ptr.use_count(), 1);
}

Test(EdgeCases, unique_pointer_reset_null, .init = redirect_all_stdout,
     .timeout = 5) {
  UniquePointer ptr(new TestObject("test"));
  ptr.reset(nullptr);
  ptr.reset(nullptr);
}

Test(EdgeCases, list_iterator_empty_after_clear, .init = redirect_all_stdout,
     .timeout = 5) {
  List list;
  list.pushBack(new TestObject("test"));
  list.clear();
  cr_assert_eq(list.begin(), list.end());
}

Test(EdgeCases, shared_pointer_complex_chain, .init = redirect_all_stdout,
     .timeout = 5) {
  SharedPointer ptr1(new TestObject("test"));
  SharedPointer ptr2 = ptr1;
  SharedPointer ptr3 = ptr2;
  ptr1 = ptr3;
  ptr2 = ptr1;
  cr_assert_geq(ptr1.use_count(), 1);
}

Test(EdgeCases, list_const_accessors, .init = redirect_all_stdout,
     .timeout = 5) {
  List list;
  TestObject *obj1 = new TestObject("test1");
  TestObject *obj2 = new TestObject("test2");
  list.pushBack(obj1);
  list.pushBack(obj2);

  const List &const_list = list;
  cr_assert_eq(const_list.front(), obj1);
  cr_assert_eq(const_list.back(), obj2);
}

Test(EdgeCases, shared_pointer_reset_self, .init = redirect_all_stdout,
     .timeout = 5) {
  SharedPointer ptr1(new TestObject("test"));
  SharedPointer ptr2(ptr1);
  ptr1.reset();
  cr_assert_eq(ptr1.use_count(), 0);
  cr_assert_eq(ptr2.use_count(), 1);
}

Test(EdgeCases, safe_directory_lister_reopen, .init = redirect_all_stdout,
     .timeout = 5) {
  SafeDirectoryLister dl("./tests/test00", false);
  dl.get();
  dl.open("./tests/test00", true);
  std::string file = dl.get();
  cr_assert_neq(file, "");
}
