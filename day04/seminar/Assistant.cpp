#include "Assistant.hpp"
#include <fstream>
#include <cstdio>
#include <iostream>

Assistant::Assistant(int id) : _id(id), _working(false)
{
  std::cout << "Assistant " << _id << ": 'morning everyone *sip coffee*" << std::endl;
}

Assistant::~Assistant()
{
  std::cout << "Assistant " << _id << ": see you tomorrow at 9.00 *sip coffee*" << std::endl;
}

int Assistant::getId() const { return _id; }

void Assistant::giveDrink(Student* student, std::string drink)
{
  std::cout << "Assistant " << _id << ": drink this, " << student->getName() << " *sip coffee*" << std::endl;
  student->drink(drink);
}

std::string Assistant::readDrink(std::string studentName)
{
  std::string filename = studentName + ".drink";
  std::ifstream file(filename);
  std::string drinkName;

  if (file.is_open()) {
    std::getline(file, drinkName);
    file.close();
    std::remove(filename.c_str());
    std::cout << "Assistant " << _id << ": " << studentName << " needs a " << drinkName << " *sip coffee*" << std::endl;
    return drinkName;
  }
  return "";
}

void Assistant::helpStudent(Student* student)
{
  std::string drink = readDrink(student->getName());
  if (!drink.empty())
    giveDrink(student, drink);
  else
    std::cout << "Assistant " << _id << ": " << student->getName() << " seems fine *sip coffee*" << std::endl;
}

void Assistant::timeCheck()
{
  _working = !_working;
  if (_working)
    std::cout << "Assistant " << _id << ": Time to teach some serious business *sip coffee*" << std::endl;
  else
    std::cout << "Assistant " << _id << ": Enough teaching for today *sip coffee*" << std::endl;
}
