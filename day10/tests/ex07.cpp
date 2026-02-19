#include <iostream>
#include <cmath>

#include "../Matrix.hpp"

int main(void)
{
    Matrix<3, 1> point;
    Matrix<3, 3> translation;
    Matrix<3, 3> rotation;

    point(0, 0) = 3;
    point(1, 0) = 2;
    point(2, 0) = 1;
    std::cout << "P: " << point << std::endl;

    translation(0, 0) = translation(1, 1) = translation(2, 2) = 1.0;
    translation(0, 2) = 4;
    translation(1, 2) = 2;
    point = translation * point;
    std::cout << "T: " << translation << std::endl;
    std::cout << "P: " << point << std::endl;

    rotation(0, 0) = +std::cos(3.14159265358979323846 / 2);
    rotation(0, 1) = -std::sin(3.14159265358979323846 / 2);
    rotation(1, 0) = +std::sin(3.14159265358979323846 / 2);
    rotation(1, 1) = +std::cos(3.14159265358979323846 / 2);
    rotation(2, 2) = 1;
    point = rotation * point;
    std::cout << "R: " << rotation << std::endl;
    std::cout << "P: " << point << std::endl;

    return 0;
}
