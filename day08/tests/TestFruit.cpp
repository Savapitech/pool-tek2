#include "TestFruit.hpp"

TestFruit::TestFruit(std::string name) :
    AFruit(name, 0, false)
{
    std::cout << name << " lives." << std::endl;
}

TestFruit::~TestFruit()
{
    std::cout << this->_name << " dies." << std::endl;
}

IFruit *TestFruit::clone() const {
    return new TestFruit(this->_name);
}
