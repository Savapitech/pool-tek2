#include "ABerry.hpp"
#include "AFruit.hpp"

ABerry::ABerry(std::string name, unsigned int vitamins) : AFruit(name, vitamins, true) {
}

void ABerry::peel() {}
