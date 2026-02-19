#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iomanip>

#include "../src/VirtualMachine.hpp"
#include "../src/BistroException.hpp"

Test (division, division_i8_i8, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int8(20)";
    std::string line2 = "push int8(14)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("1\n");
}

Test (division, division_i8_i8_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int8(20)";
    std::string line2 = "push int8(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_i8_i16, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int8(20)";
    std::string line2 = "push int16(14)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("1\n");
}

Test (division, division_i8_i16_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int8(20)";
    std::string line2 = "push int16(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_i8_i32, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int8(20)";
    std::string line2 = "push int32(14)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("1\n");
}

Test (division, division_i8_i32_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int8(20)";
    std::string line2 = "push int32(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_i8_i64, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int8(20)";
    std::string line2 = "push int64(14)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("1\n");
}

Test (division, division_i8_i64_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int8(20)";
    std::string line2 = "push int64(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_i8_f32, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int8(20)";
    std::string line2 = "push float32(15)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("1.3333333\n");
}

Test (division, division_i8_f32_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int8(20)";
    std::string line2 = "push float32(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_i8_f64, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int8(20)";
    std::string line2 = "push float64(15)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("1.333333333333333\n");
}

Test (division, division_i8_f64_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int8(20)";
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

Test (division, division_i16_i8, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int16(20)";
    std::string line2 = "push int8(14)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("1\n");
}

Test (division, division_i16_i8_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int16(20)";
    std::string line2 = "push int8(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_i16_i16, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int16(20)";
    std::string line2 = "push int16(14)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("1\n");
}

Test (division, division_i16_i16_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int16(20)";
    std::string line2 = "push int16(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_i16_i32, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int16(20)";
    std::string line2 = "push int32(14)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("1\n");
}

Test (division, division_i16_i32_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int16(20)";
    std::string line2 = "push int32(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_i16_i64, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int16(20)";
    std::string line2 = "push int64(14)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("1\n");
}

Test (division, division_i16_i64_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int16(20)";
    std::string line2 = "push int64(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_i16_f32, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int16(20)";
    std::string line2 = "push float32(15)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("1.3333333\n");
}

Test (division, division_i16_f32_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int16(20)";
    std::string line2 = "push float32(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_i16_f64, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int16(20)";
    std::string line2 = "push float64(15)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("1.333333333333333\n");
}

Test (division, division_i16_f64_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int16(20)";
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

Test (division, division_i32_i8, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int32(20)";
    std::string line2 = "push int8(14)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("1\n");
}

Test (division, division_i32_i8_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int32(20)";
    std::string line2 = "push int8(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_i32_i16, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int32(20)";
    std::string line2 = "push int16(14)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("1\n");
}

Test (division, division_i32_i16_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int32(20)";
    std::string line2 = "push int16(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_i32_i32, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int32(20)";
    std::string line2 = "push int32(14)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("1\n");
}

Test (division, division_i32_i32_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int32(20)";
    std::string line2 = "push int32(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_i32_i64, .init = cr_redirect_stdout)
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

Test (division, division_i32_i64_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int32(20)";
    std::string line2 = "push int64(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_i32_f32, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int32(20)";
    std::string line2 = "push float32(15)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("1.3333333\n");
}

Test (division, division_i32_f32_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int32(20)";
    std::string line2 = "push float32(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_i32_f64, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int32(20)";
    std::string line2 = "push float64(15)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("1.333333333333333\n");
}

Test (division, division_i32_f64_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int32(20)";
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

Test (division, division_i64_i8, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int64(20)";
    std::string line2 = "push int8(14)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("1\n");
}

Test (division, division_i64_i8_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int64(20)";
    std::string line2 = "push int8(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_i64_i16, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int64(20)";
    std::string line2 = "push int16(14)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("1\n");
}

Test (division, division_i64_i16_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int64(20)";
    std::string line2 = "push int16(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_i64_i32, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int64(20)";
    std::string line2 = "push int32(14)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("1\n");
}

Test (division, division_i64_i32_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int64(20)";
    std::string line2 = "push int32(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_i64_i64, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int64(20)";
    std::string line2 = "push int64(14)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("1\n");
}

Test (division, division_i64_i64_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int64(20)";
    std::string line2 = "push int64(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_i64_f32, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int64(20)";
    std::string line2 = "push float32(15)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("1.3333333\n");
}

Test (division, division_i64_f32_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int64(20)";
    std::string line2 = "push float32(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_i64_f64, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int64(20)";
    std::string line2 = "push float64(15)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("1.333333333333333\n");
}

Test (division, division_i64_f64_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int64(20)";
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

Test (division, division_f32_i8, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push float32(20)";
    std::string line2 = "push int8(14)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("1.4285714\n");
}

Test (division, division_f32_i8_zero)
{
    VirtualMachine vm;
    std::string line1 = "push float32(20)";
    std::string line2 = "push int8(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_f32_i16, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push float32(20)";
    std::string line2 = "push int16(14)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("1.4285714\n");
}

Test (division, division_f32_i16_zero)
{
    VirtualMachine vm;
    std::string line1 = "push float32(20)";
    std::string line2 = "push int16(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_f32_i32, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push float32(20)";
    std::string line2 = "push int32(14)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("1.4285714\n");
}

Test (division, division_f32_i32_zero)
{
    VirtualMachine vm;
    std::string line1 = "push float32(20)";
    std::string line2 = "push int32(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_f32_i64, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push float32(20)";
    std::string line2 = "push int64(14)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("1.4285714\n");
}

Test (division, division_f32_i64_zero)
{
    VirtualMachine vm;
    std::string line1 = "push float32(20)";
    std::string line2 = "push int64(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_f32_f32, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push float32(20)";
    std::string line2 = "push float32(15)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("1.3333333\n");
}

Test (division, division_f32_f32_zero)
{
    VirtualMachine vm;
    std::string line1 = "push float32(20)";
    std::string line2 = "push float32(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_f32_f64, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push float32(20)";
    std::string line2 = "push float64(15)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("1.333333333333333\n");
}

Test (division, division_f32_f64_zero)
{
    VirtualMachine vm;
    std::string line1 = "push float32(20)";
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

Test (division, division_f64_i8, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push float64(20)";
    std::string line2 = "push int8(14)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("1.428571428571429\n");
}

Test (division, division_f64_i8_zero)
{
    VirtualMachine vm;
    std::string line1 = "push float64(20)";
    std::string line2 = "push int8(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_f64_i16, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push float64(20)";
    std::string line2 = "push int16(14)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("1.428571428571429\n");
}

Test (division, division_f64_i16_zero)
{
    VirtualMachine vm;
    std::string line1 = "push float64(20)";
    std::string line2 = "push int16(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_f64_i32, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push float64(20)";
    std::string line2 = "push int32(14)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("1.428571428571429\n");
}

Test (division, division_f64_i32_zero)
{
    VirtualMachine vm;
    std::string line1 = "push float64(20)";
    std::string line2 = "push int32(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_f64_i64, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push float64(20)";
    std::string line2 = "push int64(14)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("1.428571428571429\n");
}

Test (division, division_f64_i64_zero)
{
    VirtualMachine vm;
    std::string line1 = "push float64(20)";
    std::string line2 = "push int64(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_f64_f32, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push float64(20)";
    std::string line2 = "push float32(15)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("1.333333333333333\n");
}

Test (division, division_f64_f32_zero)
{
    VirtualMachine vm;
    std::string line1 = "push float64(20)";
    std::string line2 = "push float32(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_f64_f64, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push float64(20)";
    std::string line2 = "push float64(15)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("1.333333333333333\n");
}

Test (division, division_f64_f64_zero)
{
    VirtualMachine vm;
    std::string line1 = "push float64(20)";
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

Test (division, division_negative_i8_i8, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int8(-20)";
    std::string line2 = "push int8(14)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("-1\n");
}

Test (division, division_negative_i8_i8_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int8(-20)";
    std::string line2 = "push int8(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_negative_i8_i16, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int8(-20)";
    std::string line2 = "push int16(14)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("-1\n");
}

Test (division, division_negative_i8_i16_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int8(-20)";
    std::string line2 = "push int16(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_negative_i8_i32, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int8(-20)";
    std::string line2 = "push int32(14)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("-1\n");
}

Test (division, division_negative_i8_i32_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int8(-20)";
    std::string line2 = "push int32(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_negative_i8_i64, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int8(-20)";
    std::string line2 = "push int64(14)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("-1\n");
}

Test (division, division_negative_i8_i64_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int8(-20)";
    std::string line2 = "push int64(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_negative_i8_f32, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int8(-20)";
    std::string line2 = "push float32(15)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("-1.3333333\n");
}

Test (division, division_negative_i8_f32_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int8(-20)";
    std::string line2 = "push float32(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_negative_i8_f64, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int8(-20)";
    std::string line2 = "push float64(15)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("-1.333333333333333\n");
}

Test (division, division_negative_i8_f64_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int8(-20)";
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

Test (division, division_negative_i16_i8, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int16(-20)";
    std::string line2 = "push int8(14)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("-1\n");
}

Test (division, division_negative_i16_i8_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int16(-20)";
    std::string line2 = "push int8(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_negative_i16_i16, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int16(-20)";
    std::string line2 = "push int16(14)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("-1\n");
}

Test (division, division_negative_i16_i16_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int16(-20)";
    std::string line2 = "push int16(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_negative_i16_i32, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int16(-20)";
    std::string line2 = "push int32(14)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("-1\n");
}

Test (division, division_negative_i16_i32_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int16(-20)";
    std::string line2 = "push int32(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_negative_i16_i64, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int16(-20)";
    std::string line2 = "push int64(14)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("-1\n");
}

Test (division, division_negative_i16_i64_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int16(-20)";
    std::string line2 = "push int64(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_negative_i16_f32, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int16(-20)";
    std::string line2 = "push float32(15)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("-1.3333333\n");
}

Test (division, division_negative_i16_f32_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int16(-20)";
    std::string line2 = "push float32(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_negative_i16_f64, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int16(-20)";
    std::string line2 = "push float64(15)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("-1.333333333333333\n");
}

Test (division, division_negative_i16_f64_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int16(-20)";
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

Test (division, division_negative_i32_i8, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int32(-20)";
    std::string line2 = "push int8(14)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("-1\n");
}

Test (division, division_negative_i32_i8_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int32(-20)";
    std::string line2 = "push int8(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_negative_i32_i16, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int32(-20)";
    std::string line2 = "push int16(14)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("-1\n");
}

Test (division, division_negative_i32_i16_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int32(-20)";
    std::string line2 = "push int16(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_negative_i32_i32, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int32(-20)";
    std::string line2 = "push int32(14)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("-1\n");
}

Test (division, division_negative_i32_i32_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int32(-20)";
    std::string line2 = "push int32(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_negative_i32_i64, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int32(-20)";
    std::string line2 = "push int64(14)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("-1\n");
}

Test (division, division_negative_i32_i64_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int32(-20)";
    std::string line2 = "push int64(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_negative_i32_f32, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int32(-20)";
    std::string line2 = "push float32(15)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("-1.3333333\n");
}

Test (division, division_negative_i32_f32_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int32(-20)";
    std::string line2 = "push float32(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_negative_i32_f64, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int32(-20)";
    std::string line2 = "push float64(15)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("-1.333333333333333\n");
}

Test (division, division_negative_i32_f64_zero)
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

Test (division, division_negative_i64_i8, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int64(-20)";
    std::string line2 = "push int8(14)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("-1\n");
}

Test (division, division_negative_i64_i8_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int64(-20)";
    std::string line2 = "push int8(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_negative_i64_i16, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int64(-20)";
    std::string line2 = "push int16(14)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("-1\n");
}

Test (division, division_negative_i64_i16_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int64(-20)";
    std::string line2 = "push int16(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_negative_i64_i32, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int64(-20)";
    std::string line2 = "push int32(14)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("-1\n");
}

Test (division, division_negative_i64_i32_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int64(-20)";
    std::string line2 = "push int32(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_negative_i64_i64, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int64(-20)";
    std::string line2 = "push int64(14)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("-1\n");
}

Test (division, division_negative_i64_i64_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int64(-20)";
    std::string line2 = "push int64(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_negative_i64_f32, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int64(-20)";
    std::string line2 = "push float32(15)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("-1.3333333\n");
}

Test (division, division_negative_i64_f32_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int64(-20)";
    std::string line2 = "push float32(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_negative_i64_f64, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push int64(-20)";
    std::string line2 = "push float64(15)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("-1.333333333333333\n");
}

Test (division, division_negative_i64_f64_zero)
{
    VirtualMachine vm;
    std::string line1 = "push int64(-20)";
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

Test (division, division_negative_f32_i8, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push float32(-20)";
    std::string line2 = "push int8(14)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("-1.4285714\n");
}

Test (division, division_negative_f32_i8_zero)
{
    VirtualMachine vm;
    std::string line1 = "push float32(-20)";
    std::string line2 = "push int8(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_negative_f32_i16, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push float32(-20)";
    std::string line2 = "push int16(14)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("-1.4285714\n");
}

Test (division, division_negative_f32_i16_zero)
{
    VirtualMachine vm;
    std::string line1 = "push float32(-20)";
    std::string line2 = "push int16(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_negative_f32_i32, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push float32(-20)";
    std::string line2 = "push int32(14)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("-1.4285714\n");
}

Test (division, division_negative_f32_i32_zero)
{
    VirtualMachine vm;
    std::string line1 = "push float32(-20)";
    std::string line2 = "push int32(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_negative_f32_i64, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push float32(-20)";
    std::string line2 = "push int64(14)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("-1.4285714\n");
}

Test (division, division_negative_f32_i64_zero)
{
    VirtualMachine vm;
    std::string line1 = "push float32(-20)";
    std::string line2 = "push int64(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_negative_f32_f32, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push float32(-20)";
    std::string line2 = "push float32(15)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("-1.3333333\n");
}

Test (division, division_negative_f32_f32_zero)
{
    VirtualMachine vm;
    std::string line1 = "push float32(-20)";
    std::string line2 = "push float32(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_negative_f32_f64, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push float32(-20)";
    std::string line2 = "push float64(15)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("-1.333333333333333\n");
}

Test (division, division_negative_f32_f64_zero)
{
    VirtualMachine vm;
    std::string line1 = "push float32(-20)";
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

Test (division, division_negative_f64_i8, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push float64(-20)";
    std::string line2 = "push int8(14)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("-1.428571428571429\n");
}

Test (division, division_negative_f64_i8_zero)
{
    VirtualMachine vm;
    std::string line1 = "push float64(-20)";
    std::string line2 = "push int8(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_negative_f64_i16, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push float64(-20)";
    std::string line2 = "push int16(14)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("-1.428571428571429\n");
}

Test (division, division_negative_f64_i16_zero)
{
    VirtualMachine vm;
    std::string line1 = "push float64(-20)";
    std::string line2 = "push int16(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_negative_f64_i32, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push float64(-20)";
    std::string line2 = "push int32(14)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("-1.428571428571429\n");
}

Test (division, division_negative_f64_i32_zero)
{
    VirtualMachine vm;
    std::string line1 = "push float64(-20)";
    std::string line2 = "push int32(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_negative_f64_i64, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push float64(-20)";
    std::string line2 = "push int64(14)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("-1.428571428571429\n");
}

Test (division, division_negative_f64_i64_zero)
{
    VirtualMachine vm;
    std::string line1 = "push float64(-20)";
    std::string line2 = "push int64(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_negative_f64_f32, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push float64(-20)";
    std::string line2 = "push float32(15)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("-1.333333333333333\n");
}

Test (division, division_negative_f64_f32_zero)
{
    VirtualMachine vm;
    std::string line1 = "push float64(-20)";
    std::string line2 = "push float32(0)";
    std::string div = "div";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    try {
      vm.executeInstruction(div);
    } catch(const std::exception &e) {
      cr_assert_str_eq(e.what(), "error: division by zero.");
    }
}

Test (division, division_negative_f64_f64, .init = cr_redirect_stdout)
{
    VirtualMachine vm;
    std::string line1 = "push float64(-20)";
    std::string line2 = "push float64(15)";
    std::string div = "div";
    std::string display = "display";
    vm.executeInstruction(line1);
    vm.executeInstruction(line2);
    vm.executeInstruction(div);
    vm.executeInstruction(display);
    cr_assert_stdout_eq_str("-1.333333333333333\n");
}

Test (division, division_negative_f64_f64_zero)
{
    VirtualMachine vm;
    std::string line1 = "push float64(-20)";
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