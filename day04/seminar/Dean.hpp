#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "Student.hpp"

class Dean {
  std::string _name;
  bool _working;

  public:
    Dean(std::string name);
    ~Dean();

    void teachStudent(Student* student, std::string lesson);
    void timeCheck();
    std::string getName() const;
};
