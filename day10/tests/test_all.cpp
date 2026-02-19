#include <cmath>
#include <criterion/criterion.h>
#include <sstream>
#include <string>

#include "../Algorithm.hpp"
#include "../Array.hpp"
#include "../Command.hpp"
#include "../Matrix.hpp"
#include "../SharedPointer.hpp"
#include "../Shell.hpp"
#include "../Stack.hpp"
#include "../UniquePointer.hpp"

Test(algorithm, swap_int) {
  int a = 42;
  int b = 21;

  ::swap(a, b);

  cr_assert_eq(a, 21);
  cr_assert_eq(b, 42);
}

Test(algorithm, swap_string) {
  std::string a = "hello";
  std::string b = "world";

  ::swap(a, b);

  cr_assert_str_eq(a.c_str(), "world");
  cr_assert_str_eq(b.c_str(), "hello");
}

Test(algorithm, min_int) {
  cr_assert_eq(::min(42, 21), 21);
  cr_assert_eq(::min(21, 42), 21);
  cr_assert_eq(::min(42, 42), 42);
}

Test(algorithm, min_string) {
  std::string result1 = ::min(std::string("abc"), std::string("def"));
  cr_assert_str_eq(result1.c_str(), "abc");
  std::string result2 = ::min(std::string("def"), std::string("abc"));
  cr_assert_str_eq(result2.c_str(), "abc");
}

Test(algorithm, max_int) {
  cr_assert_eq(::max(42, 21), 42);
  cr_assert_eq(::max(21, 42), 42);
  cr_assert_eq(::max(42, 42), 42);
}

Test(algorithm, max_string) {
  std::string result1 = ::max(std::string("abc"), std::string("def"));
  cr_assert_str_eq(result1.c_str(), "def");
  std::string result2 = ::max(std::string("def"), std::string("abc"));
  cr_assert_str_eq(result2.c_str(), "def");
}

Test(algorithm, clamp_int_below_min) { cr_assert_eq(::clamp(0, 21, 42), 21); }

Test(algorithm, clamp_int_above_max) { cr_assert_eq(::clamp(100, 21, 42), 42); }

Test(algorithm, clamp_int_in_range) { cr_assert_eq(::clamp(30, 21, 42), 30); }

Test(algorithm, clamp_string) {
  std::string result1 =
      ::clamp(std::string("def"), std::string("abc"), std::string("ghi"));
  cr_assert_str_eq(result1.c_str(), "def");
  std::string result2 =
      ::clamp(std::string("aaa"), std::string("abc"), std::string("ghi"));
  cr_assert_str_eq(result2.c_str(), "abc");
  std::string result3 =
      ::clamp(std::string("zzz"), std::string("abc"), std::string("ghi"));
  cr_assert_str_eq(result3.c_str(), "ghi");
}

Test(array, constructor_and_size) {
  Array<int, 5> arr;
  cr_assert_eq(arr.size(), 5);
}

Test(array, access_and_modify) {
  Array<int, 3> arr;

  arr[0] = 10;
  arr[1] = 20;
  arr[2] = 30;

  cr_assert_eq(arr[0], 10);
  cr_assert_eq(arr[1], 20);
  cr_assert_eq(arr[2], 30);
}

Test(array, out_of_range_exception) {
  Array<int, 3> arr;

  bool caught = false;
  try {
    arr[3] = 42;
  } catch (const std::out_of_range &e) {
    caught = true;
    cr_assert_str_eq(e.what(), "Out of range");
  }
  cr_assert(caught);
}

Test(array, const_access) {
  Array<int, 3> arr;
  arr[0] = 42;

  const Array<int, 3> &const_arr = arr;
  cr_assert_eq(const_arr[0], 42);
}

Test(array, forEach) {
  Array<int, 3> arr;
  arr[0] = 1;
  arr[1] = 2;
  arr[2] = 3;

  int sum = 0;
  arr.forEach([&sum](const int &val) { sum += val; });

  cr_assert_eq(sum, 6);
}

Test(array, convert) {
  Array<int, 3> arr;
  arr[0] = 10;
  arr[1] = 20;
  arr[2] = 30;

  auto floatArr = arr.convert<float>(
      [](const int &val) { return static_cast<float>(val) / 10.0f; });

  cr_assert_float_eq(floatArr[0], 1.0f, 0.001f);
  cr_assert_float_eq(floatArr[1], 2.0f, 0.001f);
  cr_assert_float_eq(floatArr[2], 3.0f, 0.001f);
}

Test(array, output_operator) {
  Array<int, 3> arr;
  arr[0] = 21;
  arr[1] = 42;
  arr[2] = 84;

  std::ostringstream oss;
  oss << arr;
  std::string result = oss.str();

  cr_assert_str_eq(result.c_str(), "[21, 42, 84]");
}

Test(array, output_operator_single) {
  Array<int, 1> arr;
  arr[0] = 42;

  std::ostringstream oss;
  oss << arr;
  std::string result = oss.str();

  cr_assert_str_eq(result.c_str(), "[42]");
}

Test(array, string_array) {
  Array<std::string, 3> arr;
  arr[0] = "hello";
  arr[1] = "world";
  arr[2] = "!";

  cr_assert_str_eq(arr[0].c_str(), "hello");
  cr_assert_str_eq(arr[1].c_str(), "world");
  cr_assert_str_eq(arr[2].c_str(), "!");
}

Test(stack, push_and_top) {
  Stack stack;
  stack.push(42.5);
  cr_assert_float_eq(stack.top(), 42.5, 0.001);
}

Test(stack, push_and_pop) {
  Stack stack;
  stack.push(10.5);
  stack.push(20.5);

  double val1 = stack.pop();
  cr_assert_float_eq(val1, 20.5, 0.001);
  double val2 = stack.pop();
  cr_assert_float_eq(val2, 10.5, 0.001);
}

Test(stack, pop_empty_throws) {
  Stack stack;

  bool caught = false;
  try {
    stack.pop();
  } catch (const Stack::Error &e) {
    caught = true;
    cr_assert_str_eq(e.what(), "Empty stack");
  }
  cr_assert(caught);
}

Test(stack, top_empty_throws) {
  Stack stack;

  bool caught = false;
  try {
    stack.top();
  } catch (const Stack::Error &e) {
    caught = true;
    cr_assert_str_eq(e.what(), "Empty stack");
  }
  cr_assert(caught);
}

Test(stack, add_operation) {
  Stack stack;
  stack.push(10.0);
  stack.push(20.0);
  stack.add();

  cr_assert_float_eq(stack.top(), 30.0, 0.001);
}

Test(stack, sub_operation) {
  Stack stack;
  stack.push(30.0);
  stack.push(10.0);
  stack.sub();

  cr_assert_float_eq(stack.top(), 20.0, 0.001);
}

Test(stack, mul_operation) {
  Stack stack;
  stack.push(5.0);
  stack.push(6.0);
  stack.mul();

  cr_assert_float_eq(stack.top(), 30.0, 0.001);
}

Test(stack, div_operation) {
  Stack stack;
  stack.push(4.0);
  stack.push(20.0);
  stack.div();

  cr_assert_float_eq(stack.top(), 5.0, 0.001);
}

Test(stack, add_not_enough_operands) {
  Stack stack;
  stack.push(5.0);

  bool caught = false;
  try {
    stack.add();
  } catch (const Stack::Error &e) {
    caught = true;
    cr_assert_str_eq(e.what(), "Not enough operands");
  }
  cr_assert(caught);
  cr_assert_float_eq(stack.top(), 5.0, 0.001);
}

Test(stack, sub_not_enough_operands) {
  Stack stack;

  bool caught = false;
  try {
    stack.sub();
  } catch (const Stack::Error &e) {
    caught = true;
    cr_assert_str_eq(e.what(), "Not enough operands");
  }
  cr_assert(caught);
}

Test(stack, mul_not_enough_operands) {
  Stack stack;
  stack.push(5.0);

  bool caught = false;
  try {
    stack.mul();
  } catch (const Stack::Error &e) {
    caught = true;
    cr_assert_str_eq(e.what(), "Not enough operands");
  }
  cr_assert(caught);
  cr_assert_float_eq(stack.top(), 5.0, 0.001);
}

Test(stack, div_not_enough_operands) {
  Stack stack;

  bool caught = false;
  try {
    stack.div();
  } catch (const Stack::Error &e) {
    caught = true;
    cr_assert_str_eq(e.what(), "Not enough operands");
  }
  cr_assert(caught);
}

Test(stack, complex_operations) {
  Stack stack;
  stack.push(42.21);
  stack.push(84.42);
  stack.push(21.12);
  stack.add();
  stack.div();

  cr_assert_float_eq(stack.top(), 2.50036, 0.001);
}

static int command_call_count = 0;

void command_setup() { command_call_count = 0; }

Test(command, register_and_execute, .init = command_setup) {
  Command cmd;

  cmd.registerCommand("test", []() { command_call_count++; });
  cmd.executeCommand("test");

  cr_assert_eq(command_call_count, 1);
}

Test(command, register_multiple_commands, .init = command_setup) {
  Command cmd;

  cmd.registerCommand("cmd1", []() { command_call_count += 1; });
  cmd.registerCommand("cmd2", []() { command_call_count += 10; });

  cmd.executeCommand("cmd1");
  cmd.executeCommand("cmd2");

  cr_assert_eq(command_call_count, 11);
}

Test(command, duplicate_registration_throws, .init = command_setup) {
  Command cmd;

  cmd.registerCommand("test", []() {});

  bool caught = false;
  try {
    cmd.registerCommand("test", []() {});
  } catch (const Command::Error &e) {
    caught = true;
    cr_assert_str_eq(e.what(), "Already registered command");
  }
  cr_assert(caught);
}

Test(command, unknown_command_throws, .init = command_setup) {
  Command cmd;

  bool caught = false;
  try {
    cmd.executeCommand("unknown");
  } catch (const Command::Error &e) {
    caught = true;
    cr_assert_str_eq(e.what(), "Unknow command");
  }
  cr_assert(caught);
}

Test(command, execute_with_state, .init = command_setup) {
  Command cmd;
  int value = 0;

  cmd.registerCommand("increment", [&value]() { value++; });
  cmd.registerCommand("double", [&value]() { value *= 2; });

  cmd.executeCommand("increment");
  cr_assert_eq(value, 1);

  cmd.executeCommand("double");
  cr_assert_eq(value, 2);

  cmd.executeCommand("increment");
  cr_assert_eq(value, 3);
}

static int unique_destruction_count = 0;

class UniqueTestClass {
public:
  int value;
  UniqueTestClass(int v) : value(v) {}
  ~UniqueTestClass() { unique_destruction_count++; }
  int getValue() const { return value; }
};

void unique_setup() { unique_destruction_count = 0; }

Test(unique_pointer, constructor_with_pointer, .init = unique_setup) {
  UniquePointer<UniqueTestClass> ptr(new UniqueTestClass(42));
  cr_assert_not_null(ptr.get());
  cr_assert_eq(ptr.get()->value, 42);
}

Test(unique_pointer, constructor_nullptr, .init = unique_setup) {
  UniquePointer<UniqueTestClass> ptr(nullptr);
  cr_assert_null(ptr.get());
}

Test(unique_pointer, default_constructor, .init = unique_setup) {
  UniquePointer<UniqueTestClass> ptr;
  cr_assert_null(ptr.get());
}

Test(unique_pointer, destructor_deletes, .init = unique_setup) {
  {
    UniquePointer<UniqueTestClass> ptr(new UniqueTestClass(42));
  }
  cr_assert_eq(unique_destruction_count, 1);
}

Test(unique_pointer, reset_method, .init = unique_setup) {
  UniquePointer<UniqueTestClass> ptr(new UniqueTestClass(42));
  ptr.reset();
  cr_assert_null(ptr.get());
  cr_assert_eq(unique_destruction_count, 1);
}

Test(unique_pointer, assignment_operator, .init = unique_setup) {
  UniquePointer<UniqueTestClass> ptr(new UniqueTestClass(42));
  ptr = new UniqueTestClass(84);

  cr_assert_eq(unique_destruction_count, 1);
  cr_assert_eq(ptr.get()->value, 84);
}

Test(unique_pointer, arrow_operator, .init = unique_setup) {
  UniquePointer<UniqueTestClass> ptr(new UniqueTestClass(42));
  cr_assert_eq(ptr->value, 42);
  cr_assert_eq(ptr->getValue(), 42);
}

Test(unique_pointer, const_arrow_operator, .init = unique_setup) {
  UniquePointer<UniqueTestClass> ptr(new UniqueTestClass(42));
  const UniquePointer<UniqueTestClass> &const_ptr = ptr;
  cr_assert_eq(const_ptr->value, 42);
}

Test(unique_pointer, get_method, .init = unique_setup) {
  UniquePointer<UniqueTestClass> ptr(new UniqueTestClass(42));
  UniqueTestClass *raw = ptr.get();
  cr_assert_not_null(raw);
  cr_assert_eq(raw->value, 42);
}

static int shared_destruction_count = 0;

class SharedTestClass {
public:
  int value;
  SharedTestClass(int v) : value(v) {}
  ~SharedTestClass() { shared_destruction_count++; }
  int getValue() const { return value; }
};

void shared_setup() { shared_destruction_count = 0; }

Test(shared_pointer, constructor_with_pointer, .init = shared_setup) {
  SharedPointer<SharedTestClass> ptr(new SharedTestClass(42));
  cr_assert_not_null(ptr.get());
  cr_assert_eq(ptr.get()->value, 42);
}

Test(shared_pointer, copy_constructor, .init = shared_setup) {
  SharedPointer<SharedTestClass> ptr1(new SharedTestClass(42));
  SharedPointer<SharedTestClass> ptr2(ptr1);

  cr_assert_eq(ptr1.get(), ptr2.get());
  cr_assert_eq(ptr1->value, 42);
  cr_assert_eq(ptr2->value, 42);
}

Test(shared_pointer, copy_assignment, .init = shared_setup) {
  SharedPointer<SharedTestClass> ptr1(new SharedTestClass(42));
  SharedPointer<SharedTestClass> ptr2;

  ptr2 = ptr1;

  cr_assert_eq(ptr1.get(), ptr2.get());
  cr_assert_eq(ptr1->value, 42);
  cr_assert_eq(ptr2->value, 42);
}

Test(shared_pointer, destructor_with_copy, .init = shared_setup) {
  SharedPointer<SharedTestClass> ptr1(new SharedTestClass(42));
  {
    SharedPointer<SharedTestClass> ptr2(ptr1);
    cr_assert_eq(shared_destruction_count, 0);
  }
  cr_assert_eq(shared_destruction_count, 0);
}

Test(shared_pointer, destructor_last_reference, .init = shared_setup) {
  {
    SharedPointer<SharedTestClass> ptr(new SharedTestClass(42));
  }
  cr_assert_eq(shared_destruction_count, 1);
}

Test(shared_pointer, reset_method, .init = shared_setup) {
  SharedPointer<SharedTestClass> ptr(new SharedTestClass(42));
  ptr.reset();
  cr_assert_null(ptr.get());
  cr_assert_eq(shared_destruction_count, 1);
}

Test(shared_pointer, reset_with_copy, .init = shared_setup) {
  SharedPointer<SharedTestClass> ptr1(new SharedTestClass(42));
  SharedPointer<SharedTestClass> ptr2(ptr1);

  ptr1.reset();
  cr_assert_null(ptr1.get());
  cr_assert_not_null(ptr2.get());
  cr_assert_eq(shared_destruction_count, 0);
}

Test(shared_pointer, assignment_operator, .init = shared_setup) {
  SharedPointer<SharedTestClass> ptr(new SharedTestClass(42));
  ptr = new SharedTestClass(84);

  cr_assert_eq(shared_destruction_count, 1);
  cr_assert_eq(ptr.get()->value, 84);
}

Test(shared_pointer, arrow_operator, .init = shared_setup) {
  SharedPointer<SharedTestClass> ptr(new SharedTestClass(42));
  cr_assert_eq(ptr->value, 42);
  cr_assert_eq(ptr->getValue(), 42);
}

Test(shared_pointer, get_method, .init = shared_setup) {
  SharedPointer<SharedTestClass> ptr(new SharedTestClass(42));
  SharedTestClass *raw = ptr.get();
  cr_assert_not_null(raw);
  cr_assert_eq(raw->value, 42);
}

Test(shared_pointer, multiple_references, .init = shared_setup) {
  SharedPointer<SharedTestClass> ptr1(new SharedTestClass(42));
  SharedPointer<SharedTestClass> ptr2(ptr1);
  SharedPointer<SharedTestClass> ptr3;

  ptr3 = ptr2;
  ptr1.reset();

  cr_assert_eq(shared_destruction_count, 0);
  cr_assert_not_null(ptr2.get());
  cr_assert_not_null(ptr3.get());

  ptr2 = new SharedTestClass(84);
  cr_assert_eq(shared_destruction_count, 0);

  ptr3.reset();
  cr_assert_eq(shared_destruction_count, 1);
}

Test(shell, next_and_extract_string) {
  std::istringstream iss("hello world");
  Shell shell(iss);

  shell.next();
  std::string word1 = shell.extract<std::string>();
  std::string word2 = shell.extract<std::string>();

  cr_assert_str_eq(word1.c_str(), "hello");
  cr_assert_str_eq(word2.c_str(), "world");
}

Test(shell, extract_int) {
  std::istringstream iss("42 84");
  Shell shell(iss);

  shell.next();
  int val1 = shell.extract<int>();
  int val2 = shell.extract<int>();

  cr_assert_eq(val1, 42);
  cr_assert_eq(val2, 84);
}

Test(shell, extract_double) {
  std::istringstream iss("3.14 2.71");
  Shell shell(iss);

  shell.next();
  double val1 = shell.extract<double>();
  double val2 = shell.extract<double>();

  cr_assert_float_eq(val1, 3.14, 0.001);
  cr_assert_float_eq(val2, 2.71, 0.001);
}

Test(shell, invalid_conversion_throws_warning) {
  std::istringstream iss("hello");
  Shell shell(iss);

  shell.next();

  bool caught = false;
  try {
    shell.extract<int>();
  } catch (const Shell::Warning &e) {
    caught = true;
    cr_assert_str_eq(e.what(), "Invalid conversion");
  }
  cr_assert(caught);
}

Test(shell, eof_throws_error) {
  std::istringstream iss("");
  Shell shell(iss);

  bool caught = false;
  try {
    shell.next();
  } catch (const Shell::Error &e) {
    caught = true;
    cr_assert_str_eq(e.what(), "End of input");
  }
  cr_assert(caught);
}

Test(shell, multiple_lines) {
  std::istringstream iss("line1\nline2\nline3");
  Shell shell(iss);

  shell.next();
  std::string word1 = shell.extract<std::string>();
  cr_assert_str_eq(word1.c_str(), "line1");

  shell.next();
  std::string word2 = shell.extract<std::string>();
  cr_assert_str_eq(word2.c_str(), "line2");

  shell.next();
  std::string word3 = shell.extract<std::string>();
  cr_assert_str_eq(word3.c_str(), "line3");
}

Test(shell, mixed_types) {
  std::istringstream iss("push 42.5");
  Shell shell(iss);

  shell.next();
  std::string cmd = shell.extract<std::string>();
  double val = shell.extract<double>();

  cr_assert_str_eq(cmd.c_str(), "push");
  cr_assert_float_eq(val, 42.5, 0.001);
}

Test(matrix, constructor_zeros) {
  Matrix<3, 3> mat;

  for (unsigned int i = 0; i < 3; i++) {
    for (unsigned int j = 0; j < 3; j++) {
      cr_assert_float_eq(mat(i, j), 0.0, 0.001);
    }
  }
}

Test(matrix, access_and_modify) {
  Matrix<2, 2> mat;

  mat(0, 0) = 1.0;
  mat(0, 1) = 2.0;
  mat(1, 0) = 3.0;
  mat(1, 1) = 4.0;

  cr_assert_float_eq(mat(0, 0), 1.0, 0.001);
  cr_assert_float_eq(mat(0, 1), 2.0, 0.001);
  cr_assert_float_eq(mat(1, 0), 3.0, 0.001);
  cr_assert_float_eq(mat(1, 1), 4.0, 0.001);
}

Test(matrix, const_access) {
  Matrix<2, 2> mat;
  mat(0, 0) = 42.0;

  const Matrix<2, 2> &const_mat = mat;
  cr_assert_float_eq(const_mat(0, 0), 42.0, 0.001);
}

Test(matrix, multiplication_square) {
  Matrix<2, 2> mat1;
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(1, 0) = 3.0;
  mat1(1, 1) = 4.0;

  Matrix<2, 2> mat2;
  mat2(0, 0) = 2.0;
  mat2(0, 1) = 0.0;
  mat2(1, 0) = 0.0;
  mat2(1, 1) = 2.0;

  Matrix<2, 2> result = mat1 * mat2;

  cr_assert_float_eq(result(0, 0), 2.0, 0.001);
  cr_assert_float_eq(result(0, 1), 4.0, 0.001);
  cr_assert_float_eq(result(1, 0), 6.0, 0.001);
  cr_assert_float_eq(result(1, 1), 8.0, 0.001);
}

Test(matrix, multiplication_non_square) {
  Matrix<2, 3> mat1;
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(0, 2) = 3.0;
  mat1(1, 0) = 4.0;
  mat1(1, 1) = 5.0;
  mat1(1, 2) = 6.0;

  Matrix<3, 2> mat2;
  mat2(0, 0) = 1.0;
  mat2(0, 1) = 2.0;
  mat2(1, 0) = 3.0;
  mat2(1, 1) = 4.0;
  mat2(2, 0) = 5.0;
  mat2(2, 1) = 6.0;

  Matrix<2, 2> result = mat1 * mat2;

  cr_assert_float_eq(result(0, 0), 22.0, 0.001);
  cr_assert_float_eq(result(0, 1), 28.0, 0.001);
  cr_assert_float_eq(result(1, 0), 49.0, 0.001);
  cr_assert_float_eq(result(1, 1), 64.0, 0.001);
}

Test(matrix, multiplication_assignment) {
  Matrix<2, 2> mat1;
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(1, 0) = 3.0;
  mat1(1, 1) = 4.0;

  Matrix<2, 2> mat2;
  mat2(0, 0) = 2.0;
  mat2(0, 1) = 0.0;
  mat2(1, 0) = 0.0;
  mat2(1, 1) = 2.0;

  mat1 *= mat2;

  cr_assert_float_eq(mat1(0, 0), 2.0, 0.001);
  cr_assert_float_eq(mat1(0, 1), 4.0, 0.001);
  cr_assert_float_eq(mat1(1, 0), 6.0, 0.001);
  cr_assert_float_eq(mat1(1, 1), 8.0, 0.001);
}

Test(matrix, output_operator) {
  Matrix<2, 2> mat;
  mat(0, 0) = 1.0;
  mat(0, 1) = 2.0;
  mat(1, 0) = 3.0;
  mat(1, 1) = 4.0;

  std::ostringstream oss;
  oss << mat;
  std::string result = oss.str();

  cr_assert_str_eq(result.c_str(), "[[1, 2], [3, 4]]");
}

Test(matrix, identity_matrix) {
  Matrix<3, 3> identity;
  identity(0, 0) = identity(1, 1) = identity(2, 2) = 1.0;

  Matrix<3, 3> mat;
  mat(0, 0) = 1.0;
  mat(0, 1) = 2.0;
  mat(0, 2) = 3.0;
  mat(1, 0) = 4.0;
  mat(1, 1) = 5.0;
  mat(1, 2) = 6.0;
  mat(2, 0) = 7.0;
  mat(2, 1) = 8.0;
  mat(2, 2) = 9.0;

  Matrix<3, 3> result = identity * mat;

  for (unsigned int i = 0; i < 3; i++) {
    for (unsigned int j = 0; j < 3; j++) {
      cr_assert_float_eq(result(i, j), mat(i, j), 0.001);
    }
  }
}
