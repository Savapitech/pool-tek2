#pragma once

#include <vector>
#include "Dean.hpp"
#include "Assistant.hpp"
#include "Student.hpp"

class Seminar {
  std::vector<Dean*> _deans;
  std::vector<Assistant*> _assistants;
  std::vector<Student*> _students;

  public:
    Seminar() = default;
    ~Seminar() = default;

    void run();
    void addDean(Dean* dean);
    void addAssistant(Assistant* assistant);
    void addStudent(Student* student);
};
