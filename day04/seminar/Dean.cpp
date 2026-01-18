#include "Dean.hpp"
#include <fstream>
#include <cstdlib>

Dean::Dean(std::string name) : _name(name), _working(false)
{
  std::cout << "Dean " << _name << ": I'm Dean " << _name << "! How do you do, fellow kids?" << std::endl;
}

Dean::~Dean()
{
  std::cout << "Dean " << _name << ": Time to go home." << std::endl;
}

std::string Dean::getName() const { return _name; }

void Dean::teachStudent(Student* student, std::string lesson)
{
  if (!student->learn(lesson)) {
    std::cout << "Dean " << _name << ": All work and no play makes " << student->getName() << " a dull student." << std::endl;

    std::string drinks[] = {"Cristaline", "Monster", "Evian", "Red Bull", "Sierra Springs"};
    std::string selected = drinks[std::rand() % 5];

    std::ofstream file(student->getName() + ".drink");
    file << selected;
    file.close();
  }
}

void Dean::timeCheck()
{
  _working = !_working;
  if (_working)
    std::cout << "Dean " << _name << ": Where is everyone?" << std::endl;
  else
    std::cout << "Dean " << _name << ": Don't forget to close the windows when you leave." << std::endl;
}
