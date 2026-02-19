#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m'

PASSED=0
FAILED=0

test_case() {
  local name="$1"
  local input="$2"
  local expected_output="$3"
  local expected_exit="$4"

  echo -e "${YELLOW}Test: $name${NC}"

  actual_output=$(echo -e "$input" | ./test 2>&1)
  actual_exit=$?

  if [ "$actual_exit" -eq "$expected_exit" ]; then
    if [ -z "$expected_output" ] || echo "$actual_output" | grep -qF -- "$expected_output"; then
      echo -e "${GREEN}PASSED${NC}"
      ((PASSED++))
    else
      echo -e "${RED}FAILED - Output mismatch${NC}"
      echo "Expected: $expected_output"
      echo "Got: $actual_output"
      ((FAILED++))
    fi
  else
    echo -e "${RED}FAILED - Exit code mismatch${NC}"
    echo "Expected exit: $expected_exit, Got: $actual_exit"
    ((FAILED++))
  fi
  echo ""
}

./test --help

# Tests int32(value) format
test_case "Format int32(value)" "push int32(42)\ndisplay\nexit" "42" 0
test_case "Format int16(value)" "push int16(100)\ndisplay\nexit" "100" 0
test_case "Format int8(value)" "push int8(10)\ndisplay\nexit" "10" 0
test_case "Format int64(value)" "push int64(1000)\ndisplay\nexit" "1000" 0
test_case "Big int64" "push int64(9223372036854775807)\ndisplay\nexit" "9223372036854775807" 0
test_case "Big float sub big int" "push int64(9223372036854775807)\npush float64(9223372036854775807)\nsub\ndisplay\nexit" "0.000000000000000" 0

# Tests float format
test_case "Format float32(value)" "push float32(3.14)\ndisplay\nexit" "3.1400000" 0
test_case "Format float64(value)" "push float64(2.718281828)\ndisplay\nexit" "2.718281828" 0

# Tests format (with spaces)
test_case "Format int 32 value" "push int 32 42\ndisplay\nexit" "42" 0
test_case "Format float 64 value" "push float 64 3.14\ndisplay\nexit" "3.14" 0

# Tests operations with new format
test_case "Addition int32()" "push int32(2)\npush int32(3)\nadd\ndisplay\nexit" "5" 0
test_case "Subtraction int32()" "push int32(10)\npush int32(3)\nsub\ndisplay\nexit" "7" 0
test_case "Multiplication int32()" "push int32(4)\npush int32(5)\nmul\ndisplay\nexit" "20" 0
test_case "Division int32()" "push int32(20)\npush int32(4)\ndiv\ndisplay\nexit" "5" 0
test_case "Modulo int32()" "push int32(17)\npush int32(5)\nmod\ndisplay\nexit" "2" 0

# Tests assert
test_case "Assert success int32()" "push int32(42)\nassert int32(42)\ndisplay\nexit" "42" 0
test_case "Assert failed int32()" "push int32(42)\nassert int32(10)" "assertion failed" 84

# Tests errors
test_case "Pop on empty stack" "pop" "pop on empty stack" 84
test_case "Division by zero int32()" "push int32(10)\npush int32(0)\ndiv" "division by zero" 84
test_case "Modulo by zero int32()" "push int32(10)\npush int32(0)\nmod" "modulo by zero" 84
test_case "Load empty register" "load 5" "load on empty register" 84
test_case "Add with 1 value" "push int32(10)\nadd" "requires at least 2 values" 84

# Tests registers
test_case "Store and load" "push int32(100)\nstore 0\nload 0\ndisplay\nexit" "100" 0
test_case "Multiple registers" "push int32(10)\nstore 0\npush int32(20)\nstore 1\nload 0\nload 1\nadd\ndisplay\nexit" "30" 0

# Tests swap
test_case "Swap int32()" "push int32(10)\npush int32(20)\nswap\nsub\ndisplay\nexit" "10" 0

# Tests clear
test_case "Clear" "push int32(10)\npush int32(20)\nclear\npush int32(100)\ndisplay\nexit" "100" 0

# Tests negative values
test_case "Negative value int32()" "push int32(-42)\ndisplay\nexit" "-42" 0
test_case "Negative addition" "push int32(-10)\npush int32(5)\nadd\ndisplay\nexit" "-5" 0

# Tests float precision
test_case "Division float32" "push float32(2.0)\npush float32(3.0)\ndiv\ndisplay\nexit" "0.6666" 0
test_case "Division float64" "push float64(2.0)\npush float64(3.0)\ndiv\ndisplay\nexit" "0.666666" 0

# Tests mix formats
test_case "Mix int32() and int 32" "push int32(10)\npush int 32 20\nadd\ndisplay\nexit" "30" 0
test_case "Mix float formats" "push float32(2.5)\npush float 64 3.5\nadd\ndisplay\nexit" "6.0" 0

# Tests different types (precision)
test_case "int32 + float64" "push int32(10)\npush float64(3.0)\ndiv\ndisplay\nexit" "3.333333" 0

# Tests comments
test_case "Comment only" "; this is a comment\npush int32(42)\ndisplay\nexit" "42" 0
test_case "Comment end of line" "push int32(42) ; comment\ndisplay\nexit" "42" 0

# Tests overflow
test_case "Overflow int8" "push int8(128)" "overflow" 84
test_case "Overflow int8 negative" "push int8(-129)" "overflow" 84

# Tests subject example
test_case "Subject terminal example" "push int32(2)\npush int32(3)\nadd\nassert int32(5)\ndisplay" "5" 0

echo "========================================"
echo -e "${GREEN}Tests passed: $PASSED${NC}"
echo -e "${RED}Tests failed: $FAILED${NC}"
echo "========================================"

if [ $FAILED -eq 0 ]; then
    echo -e "${GREEN}All tests passed!${NC}"
    exit 0
else
    echo -e "${RED}Some tests failed${NC}"
    exit 1
fi
