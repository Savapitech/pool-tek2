#include <iostream>

#include "../DirectoryLister.hpp"

int main(void) {
  DirectoryLister dl("./tests/test00", true);

  for (std::string file = dl.get(); !file.empty(); file = dl.get())
    std::cout << file << std::endl;
  dl.open("invalid path", true);
  if (dl.open("./tests/test00", false) == true)
    for (std::string file = dl.get(); !file.empty(); file = dl.get())
      std::cout << file << std::endl;

  return 0;
}
