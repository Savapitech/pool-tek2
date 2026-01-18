#include <iostream>
#include <fstream>
#include <string>

void catFile(const std::string &filename)
{
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "MyCat: " << filename << ": No such file or directory" << std::endl;
    exit(84);
  }
  std::string line;
  while (std::getline(file, line))
    std::cout << line << std::endl;
  file.close();
}

void catStdin()
{
  std::string line;
  while (std::getline(std::cin, line))
    std::cout << line << std::endl;
}

int main(int ac, char **av)
{
  if (ac == 1)
    catStdin();
  else
    for (int i = 1; i < ac; i++)
      catFile(av[i]);
  return 0;
}
