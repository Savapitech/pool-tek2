#include <iostream>

#include "VirtualMachine.hpp"

int main(int argc, char **argv) {
  if (argc > 1 &&
      (std::string(argv[1]) == "-h" || std::string(argv[1]) == "--help")) {
    std::cout << "usage: bistroMatic [options]\noptions:\n-h, --help Show this "
                 "help\n-b, --bonus Add any flag you want for bonuses!"
              << std::endl;
    return 0;
  }

  VirtualMachine vm;
  std::string line;

  try {
    while (std::getline(std::cin, line)) {
      vm.executeInstruction(line);
      if (vm.shouldStop())
        break;
    }
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 84;
  }
  return 0;
}
