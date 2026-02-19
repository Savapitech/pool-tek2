#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <sstream>

#include "../IFruit.hpp"
#include "../AFruit.hpp"
#include "../Lemon.hpp"
#include "../Orange.hpp"
#include "../Strawberry.hpp"
#include "../Almond.hpp"
#include "../Grapefruit.hpp"
#include "../BloodOrange.hpp"
#include "../Raspberry.hpp"
#include "../Coconut.hpp"
#include "../FruitBox.hpp"
#include "../FruitUtils.hpp"
#include "../FruitFactory.hpp"
#include "../FruitMixer.hpp"

Test(Lemon, basic_creation) {
    Lemon lemon;
    cr_assert_eq(lemon.getVitamins(), 0);
    cr_assert_str_eq(lemon.getName().c_str(), "lemon");
    cr_assert_eq(lemon.isPeeled(), false);
}

Test(Lemon, peel_action) {
    Lemon lemon;
    cr_assert_eq(lemon.getVitamins(), 0);
    lemon.peel();
    cr_assert_eq(lemon.isPeeled(), true);
    cr_assert_eq(lemon.getVitamins(), 4);
}

Test(Orange, basic_creation) {
    Orange orange;
    cr_assert_eq(orange.getVitamins(), 0);
    cr_assert_str_eq(orange.getName().c_str(), "orange");
    cr_assert_eq(orange.isPeeled(), false);
}

Test(Orange, peel_action) {
    Orange orange;
    orange.peel();
    cr_assert_eq(orange.isPeeled(), true);
    cr_assert_eq(orange.getVitamins(), 7);
}

Test(Strawberry, basic_creation) {
    Strawberry strawberry;
    cr_assert_str_eq(strawberry.getName().c_str(), "strawberry");
    cr_assert_eq(strawberry.isPeeled(), true);
    cr_assert_eq(strawberry.getVitamins(), 6);
}

Test(Almond, basic_creation) {
    Almond almond;
    cr_assert_eq(almond.getVitamins(), 0);
    cr_assert_str_eq(almond.getName().c_str(), "almond");
    cr_assert_eq(almond.isPeeled(), false);
}

Test(Almond, peel_action) {
    Almond almond;
    almond.peel();
    cr_assert_eq(almond.isPeeled(), true);
    cr_assert_eq(almond.getVitamins(), 2);
}

Test(Grapefruit, basic_creation) {
    Grapefruit grapefruit;
    cr_assert_str_eq(grapefruit.getName().c_str(), "grapefruit");
    cr_assert_eq(grapefruit.isPeeled(), false);
}

Test(BloodOrange, basic_creation) {
    BloodOrange bloodOrange;
    cr_assert_str_eq(bloodOrange.getName().c_str(), "blood orange");
    cr_assert_eq(bloodOrange.getVitamins(), 0);
    bloodOrange.peel();
    cr_assert_eq(bloodOrange.getVitamins(), 6);
}

Test(Raspberry, basic_creation) {
    Raspberry raspberry;
    cr_assert_str_eq(raspberry.getName().c_str(), "raspberry");
    cr_assert_eq(raspberry.isPeeled(), true);
    cr_assert_eq(raspberry.getVitamins(), 5);
}

Test(Coconut, basic_creation) {
    Coconut coconut;
    cr_assert_str_eq(coconut.getName().c_str(), "coconut");
    cr_assert_eq(coconut.isPeeled(), false);
}

Test(FruitBox, creation) {
    FruitBox box(5);
    cr_assert_eq(box.getSize(), 5);
    cr_assert_eq(box.nbFruits(), 0);
}

Test(FruitBox, push_fruit) {
    FruitBox box(3);
    IFruit *lemon = new Lemon();
    cr_assert_eq(box.pushFruit(lemon), true);
    cr_assert_eq(box.nbFruits(), 1);
}

Test(FruitBox, push_fruit_full) {
    FruitBox box(2);
    box.pushFruit(new Lemon());
    box.pushFruit(new Orange());
    cr_assert_eq(box.pushFruit(new Strawberry()), false);
    cr_assert_eq(box.nbFruits(), 2);
}

Test(FruitBox, push_same_fruit_twice) {
    FruitBox box(3);
    IFruit *lemon = new Lemon();
    cr_assert_eq(box.pushFruit(lemon), true);
    cr_assert_eq(box.pushFruit(lemon), false);
    cr_assert_eq(box.nbFruits(), 1);
}

Test(FruitBox, pop_fruit) {
    FruitBox box(3);
    IFruit *lemon = new Lemon();
    box.pushFruit(lemon);
    IFruit *popped = box.popFruit();
    cr_assert_eq(popped, lemon);
    cr_assert_eq(box.nbFruits(), 0);
    delete popped;
}

Test(FruitBox, pop_empty) {
    FruitBox box(3);
    IFruit *popped = box.popFruit();
    cr_assert_null(popped);
}

Test(FruitBox, fifo_order) {
    FruitBox box(3);
    IFruit *lemon = new Lemon();
    IFruit *orange = new Orange();
    box.pushFruit(lemon);
    box.pushFruit(orange);
    cr_assert_eq(box.popFruit(), lemon);
    cr_assert_eq(box.popFruit(), orange);
    delete lemon;
    delete orange;
}

Test(FruitUtils, sort_lemons) {
    FruitBox unsorted(10);
    FruitBox lemons(5);
    FruitBox citruses(5);
    FruitBox berries(5);
    
    unsorted.pushFruit(new Lemon());
    unsorted.pushFruit(new Lemon());
    
    FruitUtils::sort(unsorted, lemons, citruses, berries);
    
    cr_assert_eq(lemons.nbFruits(), 2);
    cr_assert_eq(citruses.nbFruits(), 0);
    cr_assert_eq(berries.nbFruits(), 0);
    cr_assert_eq(unsorted.nbFruits(), 0);
}

Test(FruitUtils, sort_mixed) {
    FruitBox unsorted(10);
    FruitBox lemons(5);
    FruitBox citruses(5);
    FruitBox berries(5);
    
    unsorted.pushFruit(new Lemon());
    unsorted.pushFruit(new Orange());
    unsorted.pushFruit(new Strawberry());
    unsorted.pushFruit(new Almond());
    
    FruitUtils::sort(unsorted, lemons, citruses, berries);
    
    cr_assert_eq(lemons.nbFruits(), 1);
    cr_assert_eq(citruses.nbFruits(), 1);
    cr_assert_eq(berries.nbFruits(), 1);
    cr_assert_eq(unsorted.nbFruits(), 1);
}

Test(FruitUtils, pack_basic) {
    IFruit *fruits[4];
    fruits[0] = new Lemon();
    fruits[1] = new Orange();
    fruits[2] = new Strawberry();
    fruits[3] = nullptr;
    
    FruitBox **boxes = FruitUtils::pack(fruits, 2);
    
    cr_assert_not_null(boxes);
    cr_assert_not_null(boxes[0]);
    cr_assert_not_null(boxes[1]);
    cr_assert_null(boxes[2]);
    cr_assert_eq(boxes[0]->nbFruits(), 2);
    cr_assert_eq(boxes[1]->nbFruits(), 1);
    
    delete boxes[0];
    delete boxes[1];
    delete[] boxes;
}

Test(FruitUtils, pack_null) {
    FruitBox **boxes = FruitUtils::pack(nullptr, 2);
    cr_assert_null(boxes);
}

Test(FruitUtils, unpack_basic) {
    FruitBox *boxes[3];
    boxes[0] = new FruitBox(5);
    boxes[1] = new FruitBox(5);
    boxes[2] = nullptr;
    
    boxes[0]->pushFruit(new Lemon());
    boxes[0]->pushFruit(new Orange());
    boxes[1]->pushFruit(new Strawberry());
    
    IFruit **fruits = FruitUtils::unpack(boxes);
    
    cr_assert_not_null(fruits);
    cr_assert_not_null(fruits[0]);
    cr_assert_not_null(fruits[1]);
    cr_assert_not_null(fruits[2]);
    cr_assert_null(fruits[3]);
    
    cr_assert_eq(boxes[0]->nbFruits(), 0);
    cr_assert_eq(boxes[1]->nbFruits(), 0);
    
    delete fruits[0];
    delete fruits[1];
    delete fruits[2];
    delete[] fruits;
    delete boxes[0];
    delete boxes[1];
}

Test(FruitFactory, register_and_create) {
    FruitFactory factory;
    factory.registerFruit(new Lemon());
    
    IFruit *fruit = factory.createFruit("lemon");
    cr_assert_not_null(fruit);
    cr_assert_str_eq(fruit->getName().c_str(), "lemon");
    delete fruit;
}

Test(FruitFactory, create_nonexistent) {
    FruitFactory factory;
    IFruit *fruit = factory.createFruit("banana");
    cr_assert_null(fruit);
}

Test(FruitFactory, unregister) {
    FruitFactory factory;
    factory.registerFruit(new Lemon());
    factory.unregisterFruit("lemon");
    
    IFruit *fruit = factory.createFruit("lemon");
    cr_assert_null(fruit);
}

Test(FruitFactory, replace_fruit) {
    FruitFactory factory;
    factory.registerFruit(new Lemon());
    factory.registerFruit(new Lemon());
    
    IFruit *fruit = factory.createFruit("lemon");
    cr_assert_not_null(fruit);
    delete fruit;
}

Test(FruitClone, lemon_clone) {
    Lemon original;
    original.peel();
    IFruit *clone = original.clone();
    
    cr_assert_not_null(clone);
    cr_assert_str_eq(clone->getName().c_str(), "lemon");
    cr_assert_eq(clone->isPeeled(), false);
    delete clone;
}

Test(FruitClone, orange_clone) {
    Orange original;
    IFruit *clone = original.clone();
    
    cr_assert_not_null(clone);
    cr_assert_str_eq(clone->getName().c_str(), "orange");
    delete clone;
}

Test(FruitMixer, no_blade) {
    FruitBox box(5);
    box.pushFruit(new Orange());
    
    FruitMixer mixer;
    unsigned int vitamins = mixer.mixFruits(box);
    
    cr_assert_eq(vitamins, 0);
    cr_assert_eq(box.nbFruits(), 1);
}

class TestBlade : public IFruitMixer::IBlade {
public:
    unsigned int operator()(const IFruit& fruit) const override {
        return fruit.getVitamins();
    }
};

Test(FruitMixer, mix_peeled_fruits) {
    FruitBox box(5);
    IFruit *orange = new Orange();
    orange->peel();
    box.pushFruit(orange);
    
    FruitMixer mixer;
    TestBlade blade;
    mixer.setBlade(&blade);
    
    unsigned int vitamins = mixer.mixFruits(box);
    cr_assert_eq(vitamins, 7);
    cr_assert_eq(box.nbFruits(), 0);
}

Test(FruitMixer, mix_unpeeled_fruits) {
    FruitBox box(5);
    box.pushFruit(new Orange());
    
    FruitMixer mixer;
    TestBlade blade;
    mixer.setBlade(&blade);
    
    unsigned int vitamins = mixer.mixFruits(box);
    cr_assert_eq(vitamins, 0);
    cr_assert_eq(box.nbFruits(), 1);
}

Test(FruitMixer, mix_mixed_fruits) {
    FruitBox box(5);
    IFruit *orange = new Orange();
    orange->peel();
    box.pushFruit(orange);
    box.pushFruit(new Lemon());
    box.pushFruit(new Strawberry());
    
    FruitMixer mixer;
    TestBlade blade;
    mixer.setBlade(&blade);
    
    unsigned int vitamins = mixer.mixFruits(box);
    cr_assert_eq(vitamins, 13);
    cr_assert_eq(box.nbFruits(), 1);
}

void redirect_all_std(void) {
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(ex00, basic_output, .init = redirect_all_std) {
    Orange o;
    Strawberry s;
    const Almond a;
    
    std::cout << o.getName() << ": " << o.getVitamins() << " vitamins" << std::endl;
    std::cout << s << std::endl;
    std::cout << a << std::endl;
    
    o.peel();
    std::cout << o << std::endl;
    
    fflush(stdout);
    cr_assert_stdout_eq_str(
        "orange: 0 vitamins\n"
        "{ \"name\": \"strawberry\", \"vitamins\": 6, \"peeled\": true }\n"
        "{ \"name\": \"almond\", \"vitamins\": 0, \"peeled\": false }\n"
        "{ \"name\": \"orange\", \"vitamins\": 7, \"peeled\": true }\n"
    );
}

Test(FruitBox, destructor_cleanup) {
    FruitBox *box = new FruitBox(3);
    box->pushFruit(new Lemon());
    box->pushFruit(new Orange());
    delete box;
    cr_assert(true);
}

Test(FruitBox, const_reference) {
    FruitBox box(2);
    const FruitBox &cref = box;
    
    box.pushFruit(new Lemon());
    
    cr_assert_eq(cref.getSize(), 2);
    cr_assert_eq(cref.nbFruits(), 1);
}

Test(FruitBox, multiple_operations) {
    FruitBox box(5);
    
    for (int i = 0; i < 3; i++) {
        box.pushFruit(new Lemon());
    }
    
    cr_assert_eq(box.nbFruits(), 3);
    
    IFruit *f1 = box.popFruit();
    IFruit *f2 = box.popFruit();
    
    cr_assert_eq(box.nbFruits(), 1);
    
    delete f1;
    delete f2;
}

Test(Fruits, all_fruits_exist) {
    Lemon lemon;
    Orange orange;
    Strawberry strawberry;
    Almond almond;
    Grapefruit grapefruit;
    BloodOrange bloodOrange;
    Coconut coconut;
    Raspberry raspberry;
    
    cr_assert_str_eq(lemon.getName().c_str(), "lemon");
    cr_assert_str_eq(orange.getName().c_str(), "orange");
    cr_assert_str_eq(strawberry.getName().c_str(), "strawberry");
    cr_assert_str_eq(almond.getName().c_str(), "almond");
    cr_assert_str_eq(grapefruit.getName().c_str(), "grapefruit");
    cr_assert_str_eq(bloodOrange.getName().c_str(), "blood orange");
    cr_assert_str_eq(coconut.getName().c_str(), "coconut");
    cr_assert_str_eq(raspberry.getName().c_str(), "raspberry");
}

Test(Fruits, vitamin_values) {
    Lemon lemon;
    Orange orange;
    Strawberry strawberry;
    Almond almond;
    Grapefruit grapefruit;
    BloodOrange bloodOrange;
    Coconut coconut;
    Raspberry raspberry;
    
    lemon.peel();
    orange.peel();
    almond.peel();
    grapefruit.peel();
    bloodOrange.peel();
    coconut.peel();
    
    cr_assert_eq(lemon.getVitamins(), 4);
    cr_assert_eq(orange.getVitamins(), 7);
    cr_assert_eq(strawberry.getVitamins(), 6);
    cr_assert_eq(almond.getVitamins(), 2);
    cr_assert_eq(grapefruit.getVitamins(), 5);
    cr_assert_eq(bloodOrange.getVitamins(), 6);
    cr_assert_eq(coconut.getVitamins(), 4);
    cr_assert_eq(raspberry.getVitamins(), 5);
}

Test(Berries, always_peeled) {
    Strawberry strawberry;
    Raspberry raspberry;
    
    cr_assert_eq(strawberry.isPeeled(), true);
    cr_assert_eq(raspberry.isPeeled(), true);
    
    cr_assert_eq(strawberry.getVitamins(), 6);
    cr_assert_eq(raspberry.getVitamins(), 5);
}

Test(Clone, independence) {
    Lemon original;
    original.peel();
    
    IFruit *cloned = original.clone();
    
    cr_assert_eq(original.isPeeled(), true);
    cr_assert_eq(cloned->isPeeled(), false);
    
    cloned->peel();
    cr_assert_eq(cloned->getVitamins(), 4);
    
    delete cloned;
}

Test(Clone, all_fruits_cloneable) {
    IFruit *fruits[] = {
        new Lemon(),
        new Orange(),
        new Strawberry(),
        new Almond(),
        new Grapefruit(),
        new BloodOrange(),
        new Raspberry(),
        new Coconut()
    };
    
    for (int i = 0; i < 8; i++) {
        IFruit *cloned = fruits[i]->clone();
        cr_assert_not_null(cloned);
        cr_assert_str_eq(cloned->getName().c_str(), fruits[i]->getName().c_str());
        delete cloned;
        delete fruits[i];
    }
}

Test(EdgeCases, fruitbox_getqueue_empty) {
    FruitBox box(5);
    auto queue = box.getQueue();
    cr_assert_eq(queue.size(), 0);
}

Test(EdgeCases, fruitbox_getqueue_filled) {
    FruitBox box(5);
    box.pushFruit(new Lemon());
    box.pushFruit(new Orange());
    auto queue = box.getQueue();
    cr_assert_eq(queue.size(), 2);
}

Test(EdgeCases, fruitutils_pack_empty) {
    IFruit *fruits[1];
    fruits[0] = nullptr;
    
    FruitBox **boxes = FruitUtils::pack(fruits, 5);
    
    cr_assert_not_null(boxes);
    cr_assert_null(boxes[0]);
    
    delete[] boxes;
}

Test(EdgeCases, fruitutils_pack_zero_size) {
    IFruit *fruits[2];
    fruits[0] = new Lemon();
    fruits[1] = nullptr;
    
    FruitBox **boxes = FruitUtils::pack(fruits, 0);
    
    cr_assert_null(boxes);
    delete fruits[0];
}

Test(EdgeCases, fruitutils_unpack_null) {
    IFruit **fruits = FruitUtils::unpack(nullptr);
    cr_assert_null(fruits);
}

Test(EdgeCases, fruitutils_unpack_empty_boxes) {
    FruitBox *boxes[2];
    boxes[0] = new FruitBox(5);
    boxes[1] = nullptr;
    
    IFruit **fruits = FruitUtils::unpack(boxes);
    
    cr_assert_not_null(fruits);
    cr_assert_null(fruits[0]);
    
    delete[] fruits;
    delete boxes[0];
}

Test(EdgeCases, fruitfactory_register_null) {
    FruitFactory factory;
    factory.registerFruit(nullptr);
    cr_assert(true);
}

Test(EdgeCases, fruitfactory_unregister_nonexistent) {
    FruitFactory factory;
    factory.unregisterFruit("nonexistent");
    cr_assert(true);
}

Test(EdgeCases, fruitbox_operations_stress) {
    FruitBox box(100);
    
    for (int i = 0; i < 50; i++) {
        box.pushFruit(new Lemon());
    }
    
    cr_assert_eq(box.nbFruits(), 50);
    
    for (int i = 0; i < 50; i++) {
        IFruit *f = box.popFruit();
        delete f;
    }
    
    cr_assert_eq(box.nbFruits(), 0);
    cr_assert_null(box.popFruit());
}

Test(EdgeCases, fruitutils_sort_overflow) {
    FruitBox unsorted(10);
    FruitBox lemons(2);
    FruitBox citruses(2);
    FruitBox berries(2);
    
    for (int i = 0; i < 5; i++) {
        unsorted.pushFruit(new Lemon());
    }
    for (int i = 0; i < 3; i++) {
        unsorted.pushFruit(new Orange());
    }
    for (int i = 0; i < 2; i++) {
        unsorted.pushFruit(new Strawberry());
    }
    
    FruitUtils::sort(unsorted, lemons, citruses, berries);
    
    cr_assert_eq(lemons.nbFruits(), 2);
    cr_assert_eq(citruses.nbFruits(), 2);
    cr_assert_eq(berries.nbFruits(), 2);
    cr_assert_eq(unsorted.nbFruits(), 4);
}

Test(EdgeCases, multiple_clones) {
    Lemon original;
    
    IFruit *clone1 = original.clone();
    IFruit *clone2 = original.clone();
    IFruit *clone3 = clone1->clone();
    
    cr_assert_not_null(clone1);
    cr_assert_not_null(clone2);
    cr_assert_not_null(clone3);
    
    delete clone1;
    delete clone2;
    delete clone3;
}

Test(EdgeCases, fruitfactory_multiple_operations) {
    FruitFactory factory;
    
    factory.registerFruit(new Lemon());
    factory.registerFruit(new Orange());
    factory.registerFruit(new Strawberry());
    
    IFruit *f1 = factory.createFruit("lemon");
    IFruit *f2 = factory.createFruit("orange");
    IFruit *f3 = factory.createFruit("strawberry");
    
    cr_assert_not_null(f1);
    cr_assert_not_null(f2);
    cr_assert_not_null(f3);
    
    delete f1;
    delete f2;
    delete f3;
    
    factory.unregisterFruit("orange");
    
    IFruit *f4 = factory.createFruit("orange");
    cr_assert_null(f4);
}

Test(Coverage, berry_peel_noop) {
    Strawberry strawberry;
    Raspberry raspberry;
    
    cr_assert_eq(strawberry.isPeeled(), true);
    cr_assert_eq(raspberry.isPeeled(), true);
    
    strawberry.peel();
    raspberry.peel();
    
    cr_assert_eq(strawberry.isPeeled(), true);
    cr_assert_eq(raspberry.isPeeled(), true);
}

Test(Coverage, fruitbox_output_stream) {
    FruitBox box(3);
    std::ostringstream oss;
    
    oss << box;
    cr_assert_str_eq(oss.str().c_str(), "[]");
    
    box.pushFruit(new Lemon());
    oss.str("");
    oss << box;
    cr_assert_neq(oss.str().find("lemon"), std::string::npos);
}

Test(Coverage, fruitbox_output_multiple) {
    FruitBox box(5);
    std::ostringstream oss;
    
    box.pushFruit(new Lemon());
    box.pushFruit(new Orange());
    box.pushFruit(new Strawberry());
    
    oss << box;
    std::string output = oss.str();
    
    cr_assert_neq(output.find("lemon"), std::string::npos);
    cr_assert_neq(output.find("orange"), std::string::npos);
    cr_assert_neq(output.find("strawberry"), std::string::npos);
}
