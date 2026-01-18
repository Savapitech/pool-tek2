#include "Student.hpp"

Student::Student(std::string name) : _name(name), _energy(100)
{
  std::cout << "Student " << _name << ": I'm ready to learn C++." << std::endl;
}

Student::~Student()
{
  std::cout << "Student " << _name << ": Wow, much learning today, very smart, such C++." << std::endl;
}

std::string Student::getName() const
{
  return _name;
}

bool Student::learn(std::string text)
{
  if (_energy >= 42) {
    _energy -= 42;
    std::cout << "Student " << _name << ": " << text << std::endl;
    return true;
  } else {
    size_t pos = 0;
    std::string replace = "shit";
    std::string search = "C++";
    while ((pos = text.find(search, pos)) != std::string::npos) {
      text.replace(pos, search.length(), replace);
      pos += replace.length();
    }
    std::cout << "Student " << _name << ": " << text << std::endl;
    return false;
  }
}

void Student::drink(std::string drinkName)
{
  if (drinkName == "Red Bull") {
    std::cout << "Student " << _name << ": Red Bull gives you wings!" << std::endl;
    _energy += 32;
  } else if (drinkName == "Monster") {
    std::cout << "Student " << _name << ": Unleash The Beast!" << std::endl;
    _energy += 64;
  } else {
    std::cout << "Student " << _name << ": ah, yes... enslaved moisture." << std::endl;
    _energy += 1;
  }
  if (_energy > 100) _energy = 100;
}
