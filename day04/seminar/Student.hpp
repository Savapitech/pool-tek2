#pragma once
#include <iostream>
#include <string>

class Student {
  std::string _name;
  int _energy;

  public:
    Student(std::string name);
    ~Student();

    bool learn(std::string text);
    void drink(std::string drinkName);
    std::string getName() const;
};
