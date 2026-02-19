#pragma once

#include <string>

#include "../AFruit.hpp"

class TestFruit : public AFruit
{
    public:
        TestFruit(std::string name);
        ~TestFruit();
        IFruit *clone() const override;
};

