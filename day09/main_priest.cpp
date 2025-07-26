#include "Peasant.hpp"
#include <iostream>

void displayStats(Peasant &peasant)
{
    std::cout << "> Peasant " << peasant.getName() << ": " << peasant.getHp()
              << " HP, " << peasant.getPower() << " PP." << std::endl;
}

void printAttack(Peasant &peasant)
{
    std::cout << "> Peasant " << peasant.getName() << ": attack." << std::endl;
    int damage = peasant.attack();
    std::cout << "> Peasant " << peasant.getName() << ": attack does " << damage << " damages." << std::endl;
}

void printSpecial(Peasant &peasant)
{
    std::cout << "> Peasant " << peasant.getName() << ": special." << std::endl;
    int damage = peasant.special();
    std::cout << "> Peasant " << peasant.getName() << ": special does " << damage << " damages." << std::endl;
}

void printRest(Peasant &peasant)
{
    std::cout << "> Peasant " << peasant.getName() << ": rest." << std::endl;
    peasant.rest();
}

// int main()
// {
//     Peasant nau("Nau", 21);
//     displayStats(nau);

//     // Test attacks until out of power (3 times)
//     for (int i = 0; i < 3; i++) {
//         printAttack(nau);
//         displayStats(nau);
//     }

//     // Test special move
//     printSpecial(nau);
//     displayStats(nau);

//     // Test rest multiple times
//     for (int i = 0; i < 5; i++) {
//         printRest(nau);
//         displayStats(nau);
//     }

//     // One more attack
//     printAttack(nau);
//     displayStats(nau);

//     // Take damage until death
//     std::cout << "> Peasant " << nau.getName() << ": 21 damage." << std::endl;
//     nau.damage(21);
//     displayStats(nau);

//     std::cout << "> Peasant " << nau.getName() << ": 42 damage." << std::endl;
//     nau.damage(42);
//     displayStats(nau);

//     std::cout << "> Peasant " << nau.getName() << ": 84 damage." << std::endl;
//     nau.damage(84);
//     displayStats(nau);

//     // Try actions while dead
//     printAttack(nau);
//     displayStats(nau);

//     printSpecial(nau);
//     displayStats(nau);

//     printRest(nau);
//     displayStats(nau);

//     return 0;
// }

