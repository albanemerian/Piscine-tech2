/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD09-albane.merian
** File description:
** Peasant
*/

#include "Peasant.hpp"
#include <iostream>

Peasant::Peasant(const std::string &name, int power) : name(name), power(power)
{
    this->hp = 100;
    std::cout << name << " goes for an adventure." << std::endl;
}


Peasant::~Peasant()
{
    // printf("in peasant destructor\n");
    std::cout << name << " is back to his crops." << std::endl;
    // delete this;
}




//get functions
int Peasant::getPower() const
{
    return power;
}

int Peasant::getHp() const
{
    return hp;
}

const std::string &Peasant::getName() const
{
    return name;
}



//set functiosn
void Peasant::setPower(int power)
{
    if (power >= 0) {
        this->power = (power <= 100) ? power : 100;   // Cap power at 100
    }
}

void Peasant::setHp(int hp)
{
    if (hp <= 100 && power >= 0)
        this->hp = hp;  // test for negative hp
}

void Peasant::setName(std::string name)
{
    this->name = name;
}


//actions fucntions

int Peasant::attack()
{
    if (getHp() <= 0) {
        std::cout << getName() << " is out of combat." << std::endl;
        return 0;
    }
    if (getPower() < 10) {
        std::cout << getName() << " is out of power." << std::endl;
        return 0;
    } else {
        setPower(getPower() - 10);
        std::cout << getName() << " tosses a stone." << std::endl;
        return 5;
    }
}

int Peasant::special()
{
    if (getHp() <= 0) {
        std::cout << getName() << " is out of combat." << std::endl;
        return 0;
    }
    if (getPower() < 0) {
        std::cout << getName() << " is out of power." << std::endl;
        return 0;
    } else {
        // setPower(getPower() - 10);
        std::cout << getName() << " doesn't know any special move." << std::endl;
        return 0;
    }
}

void Peasant::rest()
{
    if (getHp() <= 0) {
        std::cout << getName() << " is out of combat." << std::endl;
        return;
    }
    std::cout << getName() << " takes a nap." << std::endl;
    setPower(getPower() + 30);
}

void Peasant::damage(int damage)
{
    setHp(getHp() - damage);
    if (getHp() <= 0) {
        std::cout << getName() << " is out of combat." << std::endl;
        setHp(0);
    } else {
        std::cout << getName() << " takes " << damage << " damage." << std::endl;
    }
}



void Peasant::drink(const IPotion& potion)
{
    int type = potion.getType();
    
    if (type == 1) {
        if (getHp() >= 50)
            setHp(100);
        else
            setHp(getHp() + 50);
    } else if (type == 2) {
        if (getPower() >= 50)
            setPower(100);
        else
            setPower(getPower() + 50);
    } else if (type == 3) {
        if (getHp() <= 50 || getHp() <= 0)
            setHp(0);
        else 
            setHp(getHp() - 50);
    }
    std::cout << name << " drinks a mysterious potion." << std::endl;
}

void Peasant::drink(const PowerPotion& potion)
{
    potion.drink(*this);
}

void Peasant::drink(const HealthPotion& potion)
{
    potion.drink(*this);
}

void Peasant::drink(const PoisonPotion& potion)
{
    potion.drink(*this);
}
