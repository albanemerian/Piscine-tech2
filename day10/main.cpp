/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD10-albane.merian
** File description:
** main
*/

#include <iostream>
#include "Orange.hpp"
#include "Strawberry.hpp"
#include "Lemon.hpp"
#include "Almond.hpp"
#include "IFruit.hpp"
#include "AFruit.hpp"
#include "ABerry.hpp"
#include "ACitrus.hpp"
#include "ANut.hpp"
#include "FruitBox.hpp"
#include "Grapefruit.hpp"
#include "BloodOrange.hpp"
#include "Raspberry.hpp"
#include "Coconut.hpp"
#include "FruitUtils.hpp"
#include "FruitFactory.hpp"
#include "FruitMixer.hpp"
#include "Steelblade.hpp"
#include "Hack.hpp"
#include "IFruitMixer.hpp"
// #include "SteelBlade.hpp"


int main_0(void)
{
    Orange o;
    Strawberry s;
    const Almond a;
    IFruit& f = o;

    std::cout << o.getName() << ": " << o.getVitamins() << " vitamins" << std::endl;
    std::cout << s << std::endl;
    std::cout << a << std::endl;

    o.peel();
    std::cout << f << std::endl;

    return 0;
}


// int main(void)
// {
//     Orange o;
//     Strawberry s;
//     const Almond a;
//     IFruit& f = o;
//     IFruit& fruit = s;

//     std::cout << "AFruit: " << (dynamic_cast<AFruit*>(fruit) != nullptr) << std::endl;
//     std::cout << "ABerry: " << (dynamic_cast<ABerry*>(fruit) != nullptr) << std::endl;
//     std::cout << "ACitrus: " << (dynamic_cast<ACitrus*>(fruit) != nullptr) << std::endl;
//     std::cout << "ANut: " << (dynamic_cast<ANut*>(fruit) != nullptr) << std::endl;
//     std::cout << o.getName() << ": " << o.getVitamins() << " vitamins" << std::endl;
//     std::cout << s << std::endl;
//     std::cout << a << std::endl;

//     o.peel();
//     std::cout << f << std::endl;

//     return 0;
// // }

int furit_1(void)
{
    Strawberry s;
    IFruit& fruit = s;

    s.peel();
    std::cout << s << std::endl;
    std::cout << "getVitamins: " << s.getVitamins() << std::endl;
    std::cout << "getName: " << s.getName() << std::endl;
    std::cout << "isPeeled: " << std::boolalpha << s.isPeeled() << std::endl;

    std::cout << fruit << std::endl;
    std::cout << "getVitamins: " << fruit.getVitamins() << std::endl;
    std::cout << "getName: " << fruit.getName() << std::endl;
    std::cout << "isPeeled: " << std::boolalpha << fruit.isPeeled() << std::endl;

    std::cout << "AFruit: " << (dynamic_cast<AFruit*>(&fruit) != nullptr) << std::endl;
    std::cout << "ABerry: " << (dynamic_cast<ABerry*>(&fruit) != nullptr) << std::endl;
    std::cout << "ACitrus: " << (dynamic_cast<ACitrus*>(&fruit) != nullptr) << std::endl;
    std::cout << "ANut: " << (dynamic_cast<ANut*>(&fruit) != nullptr) << std::endl;

    return 0;
}


int fruit_box(void)
{
    FruitBox box(3);
    const FruitBox& cref = box;
 
    box.pushFruit(new Lemon);
    box.pushFruit(new Orange);
    box.pushFruit(new Almond);
    std::cout << cref << std::endl;

    IFruit* tmp = new Strawberry;
    std::cout << box.pushFruit(tmp) << std::endl;
    std::cout << cref << std::endl;
    delete tmp;
    tmp = box.popFruit();
    std::cout << cref << std::endl;
    std::cout << tmp->getName() << std::endl;
    delete tmp;
    std::cout << cref << std::endl;
    return 0;
}
 

int utils_funcc(void)
{
    // Create boxes for sorting
    // FruitUtils utils;
    FruitBox unsorted(15);    // Big box for unsorted fruits
    FruitBox lemon(5);        // Box for lemons
    FruitBox citrus(5);       // Box for other citrus
    FruitBox berry(5);        // Box for berries

    // Add various fruits to unsorted box
    unsorted.pushFruit(new Lemon());        // Should go to lemon box
    unsorted.pushFruit(new Orange());       // Should go to citrus box
    unsorted.pushFruit(new Grapefruit());   // Should go to citrus box
    unsorted.pushFruit(new BloodOrange());  // Should go to citrus box
    unsorted.pushFruit(new Strawberry());   // Should go to berry box
    unsorted.pushFruit(new Raspberry());    // Should go to berry box
    unsorted.pushFruit(new Almond());       // Should stay in unsorted (nut)
    unsorted.pushFruit(new Coconut());      // Should stay in unsorted (nut)

    // Print initial state
    std::cout << "Initial unsorted box:" << std::endl;
    std::cout << unsorted << std::endl;

    // Sort the fruits
    FruitUtils::sort(unsorted, lemon, citrus, berry);

    // Print final states
    std::cout << "\nAfter sorting:" << std::endl;
    std::cout << "Lemon box:" << std::endl;
    std::cout << lemon << std::endl;
    std::cout << "Citrus box:" << std::endl;
    std::cout << citrus << std::endl;
    std::cout << "Berry box:" << std::endl;
    std::cout << berry << std::endl;
    std::cout << "Remaining unsorted:" << std::endl;
    std::cout << unsorted << std::endl;

    return 0;
}

int tes_pakc(void)
{
    // Test case 1: Testing pack with exact division
    IFruit *fruits1[] = {
        new Lemon(),
        new Orange(),
        new Grapefruit(),
        new BloodOrange(),
        new Strawberry(),
        new Raspberry(),
        new Lemon(),
        new Orange(),
        new Grapefruit(),
        new BloodOrange(),
        new Strawberry(),
        new Raspberry(),
        new Lemon(),
        new Orange(),
        new Grapefruit(),
        new BloodOrange(),
        new Strawberry(),
        new Raspberry(),
        new Lemon(),
        new Orange(),
        new Grapefruit(),
        new BloodOrange(),
        new Strawberry(),
        new Raspberry(),
        new Lemon(),
        nullptr
    };
    
    std::cout << "Test Case 1: 6 fruits with box size 2" << std::endl;
    std::cout << "Expected: 3 boxes with 2 fruits each" << std::endl;
    FruitBox **boxes1 = FruitUtils::pack(fruits1, 6);
    
    for (int i = 0; boxes1[i] != nullptr; i++) {
        std::cout << "Box " << i << ": " << *boxes1[i] << std::endl;
    }
    std::cout << "\nTesting unpack:" << std::endl;
    IFruit **unpacked_fruits = FruitUtils::unpack(boxes1);
    
    std::cout << "Unpacked fruits:" << std::endl;
    for (int i = 0; unpacked_fruits[i] != nullptr; i++) {
        std::cout << "Fruit " << i << ": " << *unpacked_fruits[i] << std::endl;
    }

    // Verify boxes are empty
    std::cout << "\nVerifying boxes are empty:" << std::endl;
    for (int i = 0; boxes1[i] != nullptr; i++) {
        std::cout << "Box " << i << ": " << *boxes1[i] << std::endl;
    }

    // Cleanup boxes1
    for (int i = 0; boxes1[i] != nullptr; i++) {
        delete boxes1[i];
    }
    delete[] boxes1;

    // Test case 2: Testing pack with uneven division
    IFruit *fruits2[] = {
        new Lemon(),
        new Orange(),
        new Grapefruit(),
        new BloodOrange(),
        new Strawberry(),
        nullptr
    };

    std::cout << "\nTest Case 2: 5 fruits with box size 3" << std::endl;
    std::cout << "Expected: 6 boxes - first with 3 fruits, second with 2 fruits" << std::endl;
    FruitBox **boxes2 = FruitUtils::pack(fruits2, 6);
    
    for (int i = 0; boxes2[i] != nullptr; i++) {
        std::cout << "Box " << i << ": " << *boxes2[i] << std::endl;
    }

    // Cleanup boxes2
    for (int i = 0; boxes2[i] != nullptr; i++) {
        delete boxes2[i];
    }
    delete[] boxes2;

    IFruit *fruits3[] = {
        new Lemon(),
        nullptr
    };

    std::cout << "\nTest Case 3: 5 fruits with box size 2" << std::endl;
    std::cout << "Expected: 3 boxes - first with 2 fruits, second with 1 fruits" << std::endl;
    FruitBox **boxes3 = FruitUtils::pack(fruits3, 1);
    
    for (int i = 0; boxes3[i] != nullptr; i++) {
        std::cout << "Box " << i << ": " << *boxes3[i] << std::endl;
    }

    for (int i = 0; boxes3[i] != nullptr; i++) {
        printf("in the delete loop\n");
        delete boxes3[i];
    }
    printf("hererererere\n");
    delete[] boxes3;

    IFruit *fruits4[] = {
        new Lemon(),
        nullptr
    };

    std::cout << "\nTest Case 4: 5 fruits with box size 1" << std::endl;
    FruitBox **boxes4 = FruitUtils::pack(fruits4, 1);
    
    for (int i = 0; boxes4[i] != nullptr; i++) {
        std::cout << "Box " << i << ": " << *boxes4[i] << std::endl;
    }

    for (int i = 0; boxes4[i] != nullptr; i++) {
        printf("in the delete loop\n");
        delete boxes4[i];
    }
    printf("hererererere\n");
    delete[] boxes4;
    return 0;
}


int test_factory(void)
{
    printf("test factory\n\n");
    FruitFactory factory;

    factory.registerFruit(new Raspberry);
    factory.registerFruit(new BloodOrange);
    factory.registerFruit(new Almond);
    factory.registerFruit(new Coconut);
    factory.registerFruit(new Almond);
    factory.registerFruit(new Coconut);

    factory.unregisterFruit("banana");
    factory.unregisterFruit("coconut");

    IFruit* fruit1 = factory.createFruit("almond");
    IFruit* fruit2 = factory.createFruit("coconut");
    IFruit* fruit3 = factory.createFruit("tomato");

    std::cout << *fruit1 << std::endl;
    std::cout << fruit2 << std::endl;
    std::cout << fruit3 << std::endl;

    delete fruit1;

    return 0;
}



int test_mixer(void)
{
    FruitBox box(5);
    FruitMixer yourMixer;
    IFruitMixer& mixer(yourMixer);
    SteelBlade blade;
    IFruit* fruit;

    fruit = new Orange;
    fruit->peel();
    box.pushFruit(fruit);
    box.pushFruit(new Lemon);
    box.pushFruit(new Strawberry);
    box.pushFruit(new Almond);
    std::cout << box << std::endl;

    unsigned int vitamins = mixer.mixFruits(box);

    std::cout << "result: " << vitamins << std::endl;
    std::cout << box << std::endl;

    mixer.setBlade(&blade);
    vitamins = mixer.mixFruits(box);
    std::cout << "result: " << vitamins << std::endl;
    std::cout << box << std::endl;

    return 0;
}

int main_six(void)
{
    IFruit* fruit = new Strawberry;
    Hack* hack = reinterpret_cast<Hack*>(fruit);

    std::cout << *fruit << std::endl;
    hack->hack(1138);
    std::cout << *fruit << std::endl;
    delete fruit;
    return 0;
}



int main(void)
{
    main_0();
    printf("\n\n");
    furit_1();
    printf("\n\n");
    fruit_box();
    printf("\n\n");
    utils_funcc();
    printf("\n\n");
    tes_pakc();
    printf("\n\n");
    test_factory();
    printf("\n\n");
    test_mixer();
    printf("\n\n");
    main_six();
}
