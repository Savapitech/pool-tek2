#pragma once

#include "../IObject.hpp"
#include <iostream>
#include <string>

class TestObject : public IObject {
private:
  std::string _name;

public:
  TestObject(const std::string &name) : _name(name) {
    std::cout << _name << " is alive" << std::endl;
  }

  ~TestObject() override { std::cout << _name << " is dead" << std::endl; }

  void touch() override { std::cout << _name << " is touched" << std::endl; }
};
