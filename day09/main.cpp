/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD09-albane.merian
** File description:
** main
*/

#include "Peasant.hpp"
#include "Knight.hpp"
#include "Enchanter.hpp"
#include "Priest.hpp"
#include "Paladin.hpp"
#include "ICharacter.hpp"
#include "IPotion.hpp"
#include "PoisonPotion.hpp"
#include "HealthPotion.hpp"
#include "PowerPotion.hpp"
#include <iostream>

void peasant_func(void)
{
    Peasant peasant("Gildas", 42);

    peasant.damage(50);
    peasant.damage(100);
    peasant.damage(200);
    peasant.rest();
}

void knight_func(void)
{
    Knight knight("Arthur", 20);

    knight.attack();
    knight.special();
    knight.rest();
    knight.special();
    knight.damage(50);
}

void enchanter_func(void)
{
    Enchanter enchanter("Merlin", 20);

    enchanter.attack();
    enchanter.special();
    enchanter.rest();
    enchanter.special();
    enchanter.damage(50);
}

void priest_func(void)
{
    Priest priest("Trichelieu", 20);

    priest.attack();
    priest.special();
    priest.rest();
    priest.damage(50);
}

void paladin_func(void)
{
    Paladin paladin("Uther", 99);

    paladin.attack();
    paladin.special();
    paladin.rest();
    paladin.damage(50);
}

void icharacter_func(void)
{
    ICharacter *peasant = new Peasant("Gildas", 42);
    ICharacter *knight = new Knight("Arthur", 20);
    ICharacter *enchanter = new Enchanter("Merlin", 20);
    ICharacter *priest = new Priest("Trichelieu", 20);
    ICharacter *paladin = new Paladin("Uther", 99);

    peasant->attack();
    knight->special();
    enchanter->rest();
    priest->damage(21);
    std::cout << paladin->getName() << ": "
              << paladin->getHp() << " health points, "
              << paladin->getPower() << " power points."
              << std::endl;

    
    delete peasant;
    delete knight;
    delete enchanter;
    delete priest;
    delete paladin;
}


int siw_test(void)
{
    ICharacter *peasant = new Peasant("Gildas", 42);
    PoisonPotion poison_potion;
    HealthPotion health_potion;
    IPotion& potion = health_potion;

    std::cout << peasant->getName() << ": " << peasant->getHp() << "HP, "
              << peasant->getPower() << " PP." << std::endl;
    peasant->drink(poison_potion);
    std::cout << peasant->getName() << ": " << peasant->getHp() << "HP, "
              << peasant->getPower() << " PP." << std::endl;
    // printf("before drink potion\n");
    peasant->drink(potion);
    // printf("after drink potion\n");
    std::cout << peasant->getName() << ": " << peasant->getHp() << "HP, "
              << peasant->getPower() << " PP." << std::endl;

    delete peasant;
    return 0;
}

int main (void)
{
    peasant_func();
    printf("\n");
    knight_func();
    printf("\n");
    enchanter_func();
    printf("\n");
    priest_func();
    printf("\n");
    paladin_func();
    printf("\n");
    icharacter_func();
    printf("\n");
    siw_test();
}

