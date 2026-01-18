#pragma once

#include <string>
#include <iostream>
#include "Student.hpp"

class Assistant {
  int _id;
  bool _working;

  public:
    Assistant(int id);
    ~Assistant();

    void giveDrink(Student* student, std::string drink);
    std::string readDrink(std::string studentName);
    void helpStudent(Student* student);
    void timeCheck();

    int getId() const;
};
