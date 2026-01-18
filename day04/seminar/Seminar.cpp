#include <algorithm>
#include <iostream>

#include "Seminar.hpp"

void Seminar::addDean(Dean* dean)
{
  if (!_deans.empty()) {
    std::cout << "Seminar: There can only be one Dean of Studies." << std::endl;
    return;
  }
  _deans.push_back(dean);
  std::cout << "Seminar: Dean " << dean->getName() << " is here." << std::endl;
}

void Seminar::addAssistant(Assistant* assistant)
{
  for (auto* a : _assistants) {
    if (a->getId() == assistant->getId()) {
      std::cout << "Seminar: Assistant " << assistant->getId() << " is already registered." << std::endl;
      return;
    }
  }
  if (_assistants.size() >= 2) {
    std::cout << "Seminar: There is only room for two Teaching Assistants." << std::endl;
    return;
  }
  _assistants.push_back(assistant);
  std::cout << "Seminar: Assistant " << assistant->getId() << " joined the pedagogical team." << std::endl;
}

void Seminar::addStudent(Student* student)
{
  for (auto* s : _students) {
    if (s->getName() == student->getName()) {
      std::cout << "Seminar: Student " << student->getName() << " is already registered." << std::endl;
      return;
    }
  }
  if (_students.size() >= 5) {
    std::cout << "Seminar: There is only room for five Students." << std::endl;
    return;
  }
  _students.push_back(student);
  std::cout << "Seminar: Student " << student->getName() << " joined the seminar." << std::endl;
}

void Seminar::run()
{
  if (_deans.empty() || _assistants.empty() || _students.empty()) {
    std::cout << "Seminar: A C++ seminar needs at least one Dean of Studies, one Assistant and one Student." << std::endl;
    return;
  }

  std::cout << "Seminar: Begining 6th day of seminar." << std::endl;

  std::cout << "Dean of Studies: " << _deans[0]->getName() << std::endl;
  std::cout << "Teaching assistants: ";
  for (size_t i = 0; i < _assistants.size(); ++i)
    std::cout << _assistants[i]->getId() << (i == _assistants.size() - 1 ? "" : ", ");
  std::cout << std::endl;
  std::cout << "Students: ";
  for (size_t i = 0; i < _students.size(); ++i)
    std::cout << _students[i]->getName() << (i == _students.size() - 1 ? "" : ", ");
  std::cout << std::endl;

  _deans[0]->timeCheck();
  for (auto* a : _assistants) a->timeCheck();

  size_t assistant_idx = 0;
  for (int i = 0; i < 5; ++i) { 
    for (auto* s : _students) {
      _deans[0]->teachStudent(s, "I'm learning C++!");
      _assistants[assistant_idx]->helpStudent(s);
      assistant_idx = (assistant_idx + 1) % _assistants.size();
    }
  }

  _deans[0]->timeCheck();
  for (auto* a : _assistants) a->timeCheck();
}
