#include "../FruitUtils.hpp"
#include "../Lemon.hpp"
#include "../Grapefruit.hpp"
#include "../BloodOrange.hpp"
#include "../Strawberry.hpp"
#include "../Coconut.hpp"
#include "../Almond.hpp"

int main(void)
{
    FruitUtils utils;
    FruitBox box(7);
    const FruitBox& cref = box;
    FruitBox lemons(5);
    FruitBox citruses(5);
    FruitBox berries(5);
    FruitBox empty(1);
    FruitBox empty2(0);

    box.pushFruit(new Lemon());
    box.pushFruit(new Grapefruit());
    box.pushFruit(new BloodOrange());
    box.pushFruit(new Coconut());
    box.pushFruit(new Strawberry());
    box.pushFruit(new Lemon());
    box.pushFruit(new Almond());
    std::cout << "cref 1: " << cref << std::endl;

    utils.sort(box, lemons, citruses, berries);
    std::cout << "cref 2: " << cref << std::endl << std::endl;
    std::cout << "lemons: " << lemons << std::endl << std::endl;
    std::cout << "citruses: " << citruses << std::endl << std::endl;
    std::cout << "berries: " << berries << std::endl << std::endl;
    std::cout << "empty: " << empty << std::endl << std::endl;
    std::cout << "empty2: " << empty2 << std::endl << std::endl;
    return 0;
}
