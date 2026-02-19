#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iomanip>

#include "../src/VirtualMachine.hpp"
#include "../src/BistroException.hpp"
void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Operand, operator_add, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int32(20); it push an int32 number";
    std::string line2 = "push int64(14)";
    std::string add = "add";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(add);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("34\n");
}

Test(Operand, operator_add_empty)
{
  VirtualMachine vm;
    std::string line1 = "push int32(-20)";
    std::string div = "add";
    vm.executeInstruction(line1);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: requires at least 2 values on stack.");
    }
  
}

Test(Operand, operator_add_negative, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int32(-20)";
    std::string line2 = "push float64(1.03)";
    std::string add = "add";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(add);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("-18.969999999999999\n");
}

Test(Operand, operator_sub, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int32(20)";
    std::string line2 = "push int64(14)";
    std::string sub = "sub";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(sub);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("6\n");
}

Test(Operand, operator_sub_negative, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int32(-20)";
    std::string line2 = "push float64(1.03)";
    std::string sub = "sub";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(sub);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("-21.030000000000001\n");
}

Test(Operand, operator_mul, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int32(20)";
    std::string line2 = "push int64(14)";
    std::string mul = "mul";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(mul);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("280\n");
}

Test(Operand, operator_mul_negative, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int32(-20)";
    std::string line2 = "push float64(1.03)";
    std::string mul = "mul";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(mul);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("-20.600000000000001\n");
}

Test(Operand, operator_mul_zero, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int32(0)";
    std::string line2 = "push float64(1.03)";
    std::string mul = "mul";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(mul);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("0.000000000000000\n");
}

Test(Operand, operator_div, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int32(20)";
    std::string line2 = "push int64(14)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("1\n");
}

Test(Operand, operator_div_negative, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int32(-20)";
    std::string line2 = "push float64(1.03)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("-19.417475728155338\n");
}

Test(Operand, operator_div_by_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int32(-20)";
    std::string line2 = "push float64(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test(Operand, operator_div_zero, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push float64(0)";
    std::string line2 = "push int32(20)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("0.000000000000000\n");
}

Test(Operand, operator_div_negative_zero, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push float64(-0)";
    std::string line2 = "push int32(20)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("-0.000000000000000\n");
}

Test(Operand, operator_mod, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int32(20)";
    std::string line2 = "push int64(14)";
    std::string mod = "mod";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(mod);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("6\n");
}

Test(Operand, operator_mod_negative, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int32(-20)";
    std::string line2 = "push float64(1.03)";
    std::string mod = "mod";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(mod);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("-0.429999999999999\n");
}

Test(Operand, operator_mod_by_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int32(-20)";
    std::string line2 = "push float64(0)";
    std::string mod = "mod";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(mod);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: modulo by zero.");
    }
}

Test(Operand, operator_mod_zero, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push float64(0)";
    std::string line2 = "push int32(20)";
    std::string mod = "mod";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(mod);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("0.000000000000000\n");
}

Test(Operand, operator_mod_negative_zero, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push float64(-0)";
    std::string line2 = "push int32(20)";
    std::string mod = "mod";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(mod);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("-0.000000000000000\n");
}

Test(Operand, inst_pop, .init = cr_redirect_stdout)
{
  VirtualMachine vm;
  std::string line1 = "push int32(20)";
  std::string line2 = "push float16(0)";
  std::string pop = "pop";
  std::string display = "display";
  vm.executeInstruction(line1);
  vm.executeInstruction(line2);
  vm.executeInstruction(pop);
  vm.executeInstruction(display);
  cr_assert_stdout_eq_str("20\n");
}

Test(Operand, inst_pop_empty)
{
    VirtualMachine vm;
    std::string mod = "pop";
    try {
      vm.executeInstruction(mod);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: pop on empty stack.");
    }
}

Test(Operand, inst_clear)
{
    VirtualMachine vm;

  std::string line1 = "push int32(20)";
  std::string line2 = "push float16(0)";
  std::string clear = "clear";
  std::string display = "display";

    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(clear);
    try {
      vm.executeInstruction(display);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: display on empty stack.");
    }
}

Test(Operand, inst_swap, .init = cr_redirect_stdout)
{
  VirtualMachine vm;
  std::string line1 = "push int32(20)";
  std::string line2 = "push float64(0)";
  std::string swap = "swap";
  std::string display = "display";
  vm.executeInstruction(line1);
  vm.executeInstruction(line2);
  vm.executeInstruction(display);
  vm.executeInstruction(swap);
  vm.executeInstruction(display);
  cr_assert_stdout_eq_str("0.000000000000000\n20\n");
}

Test(Operand, inst_swap_empty)
{
  VirtualMachine vm;
  std::string swap = "swap";
  try {
    vm.executeInstruction(swap);
  } catch(const std::exception &e) {
    cr_assert_str_eq(e.what(), "error: swap requires at least 2 values on stack.");
  }
}

Test(Operand, inst_assert, .init = cr_redirect_stdout)
{
  VirtualMachine vm;
  std::string line1 = "push int32(20)";
  std::string line2 = "push float64(0)";
  std::string assert = "assert float64 0";
  std::string display = "display";
  vm.executeInstruction(line1);
  vm.executeInstruction(line2);
  vm.executeInstruction(assert);
  vm.executeInstruction(display);
  cr_assert_stdout_eq_str("0.000000000000000\n");
}

Test(Operand, inst_assert_empty)
{
  VirtualMachine vm;
  std::string assert = "assert int32 20";
  try {
    vm.executeInstruction(assert);
  } catch(const std::exception &e) {
    cr_assert_str_eq(e.what(), "error: assert on empty stack.");
  }
}

Test(Operand, inst_assert_false)
{
  VirtualMachine vm;
  std::string line1 = "push int32(20)";
  std::string assert = "assert int32 10";
  vm.executeInstruction(line1);
  try {
    vm.executeInstruction(assert);
  } catch(const std::exception &e) {
    cr_assert_str_eq(e.what(), "error: assertion failed.");
  }
}

Test(Operand, inst_store_and_load , .init = cr_redirect_stdout)
{
  VirtualMachine vm;
  std::string line1 = "push int32 20";
  std::string store = "store 3";
  std::string display = "display";
  std::string load = "load 3";
  vm.executeInstruction(line1);
  vm.executeInstruction(store);
  try {
    vm.executeInstruction(display);
  } catch(const std::exception &e) {
    cr_assert_str_eq(e.what(), "error: display on empty stack.");
  }
  vm.executeInstruction(load);
  vm.executeInstruction(display);
  cr_assert_stdout_eq_str("20\n");
}

Test(Operand, inst_store_on_another_variable , .init = cr_redirect_stdout)
{
  VirtualMachine vm;
  std::string line1 = "push int32 20";
  std::string line2 = "push int32 50";
  std::string store = "store 3";
  std::string display = "display";
  std::string load = "load 3";
  vm.executeInstruction(line1);
  vm.executeInstruction(line2);
  vm.executeInstruction(store);
  vm.executeInstruction(store);
  vm.executeInstruction(load);
  vm.executeInstruction(display);
  cr_assert_stdout_eq_str("20\n");
}

Test(Operand, inst_store_and_load_invalid)
{
  VirtualMachine vm;
  std::string store1 = "store 20";
  std::string load1 = "load 30";
  std::string store2 = "store 1";
  std::string load2 = "load 3";
  try {
    vm.executeInstruction(store1);
  } catch(const std::exception &e) {
    cr_assert_str_eq(e.what(), "error: invalid register.");
  }
  try {
    vm.executeInstruction(load1);
  } catch(const std::exception &e) {
    cr_assert_str_eq(e.what(), "error: invalid register.");
  }
  try {
    vm.executeInstruction(store2);
  } catch(const std::exception &e) {
    cr_assert_str_eq(e.what(), "error: store on empty stack.");
  }
  try {
    vm.executeInstruction(load2);
  } catch(const std::exception &e) {
    cr_assert_str_eq(e.what(), "error: load on empty register.");
  }
}

Test(Operand, inst_exit)
{
  VirtualMachine vm;
  std::string exit = "exit";
  vm.executeInstruction(exit);
  cr_assert_eq(vm.shouldStop(), true);
}

Test(Operand, inst_error_parenthese_unclose)
{
  VirtualMachine vm;
  std::string line1 = "push int32(20";
  try {
    vm.executeInstruction(line1);
  } catch(const std::exception &e) {
    cr_assert_str_eq(e.what(), "error: parenthesis was not closed.");
  }
}

Test(Operand, inst_error_wrong_parenthese)
{
  VirtualMachine vm;
  std::string line1 = "push int32(20 )";
  try {
    vm.executeInstruction(line1);
  } catch(const std::exception &e) {
    cr_assert_str_eq(e.what(), "error: extra characters after arguments");
  }
}

Test(Operand, inst_error_wrong_argument)
{
  VirtualMachine vm;
  std::string line1 = "push int32 20het";
  try {
    vm.executeInstruction(line1);
  } catch(const std::exception &e) {
    cr_assert_str_eq(e.what(), "error: value does not match regular expression.");
  }
}

Test(Operand, inst_error_wrong_argument_after_paranthese)
{
  VirtualMachine vm;
  std::string line1 = "push int32(20)et";
  try {
    vm.executeInstruction(line1);
  } catch(const std::exception &e) {
    cr_assert_str_eq(e.what(), "error: extra characters after arguments");
  }
}

Test(Operand, inst_argument, .init = cr_redirect_stdout)
{
  VirtualMachine vm;
  std::string line1 = "push int 32 20";
  std::string display = "display";
  vm.executeInstruction(line1);
  vm.executeInstruction(display);
  cr_assert_stdout_eq_str("20\n");
}

Test(Operand, overflow_i8)
{
  VirtualMachine vm;
  std::string line1 = "push int 8 2000";
  std::string line2 = "push int 8 -2000";
  try {
    vm.executeInstruction(line1);
  } catch(const std::exception &e) {
    cr_assert_str_eq(e.what(), "overflow");
  }
  try {
    vm.executeInstruction(line2);
  } catch(const std::exception &e) {
    cr_assert_str_eq(e.what(), "overflow");
  }
}

Test(Operand, overflow_i16)
{
  VirtualMachine vm;
  std::string line1 = "push int 16 200000";
  std::string line2 = "push int 16 -200000";
  try {
    vm.executeInstruction(line1);
  } catch(const std::exception &e) {
    cr_assert_str_eq(e.what(), "overflow");
  }
  try {
    vm.executeInstruction(line2);
  } catch(const std::exception &e) {
    cr_assert_str_eq(e.what(), "overflow");
  }
}

Test(Operand, overflow_i32)
{
  VirtualMachine vm;
  std::string line1 = "push int 32 20000000000";
  std::string line2 = "push int 32 -20000000000";
  try {
    vm.executeInstruction(line1);
  } catch(const std::exception &e) {
    cr_assert_str_eq(e.what(), "overflow");
  }
  try {
    vm.executeInstruction(line2);
  } catch(const std::exception &e) {
    cr_assert_str_eq(e.what(), "overflow");
  }
}

Test(Operand, overflow_i64)
{
  VirtualMachine vm;
  std::string line1 = "push int 64 9223372036854775808";
  std::string line2 = "push int 64 -9223372036854775809";
  try {
    vm.executeInstruction(line1);
  } catch(const std::exception &e) {
    cr_assert_str_eq(e.what(), "overflow");
  }
  try {
    vm.executeInstruction(line2);
  } catch(const std::exception &e) {
    cr_assert_str_eq(e.what(), "overflow");
  }
}

Test(Operand, empty_inst)
{
  VirtualMachine vm;
  vm.executeInstruction("");
}

Test(Operand, unknow_inst)
{
  VirtualMachine vm;
  try {
    vm.executeInstruction("random instruction");
  } catch(const std::exception &e) {
    cr_assert_str_eq(e.what(), "error: unknown instruction 'random'.");
  }
}

Test(Operand, inst_trim)
{
  cr_assert_eq(trim(""), "");
}

Test(Operand, inst_checlk_trail)
{
  std::istringstream iss("   extra");
  try {
  check_trail(iss);
  } catch(const std::exception &e) {
    cr_assert_str_eq(e.what(), "error: too many arguments in function call.");
  }
}