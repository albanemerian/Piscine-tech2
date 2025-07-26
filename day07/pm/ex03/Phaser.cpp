/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD07pm-albane.merian
** File description:
** Phaser
*/


#include "Sounds.hpp"
#include "Phaser.hpp"

Phaser::Phaser(int maxAmmo, AmmoType type) : maxAmmo(maxAmmo), currentAmmo(maxAmmo), defaultType(type) {
    magazine.resize(maxAmmo, type);
}

Phaser::~Phaser() {}

void Phaser::fire()
{
    if (currentAmmo == Empty) {
        std::cout << "Clip empty, please reload" << std::endl;
    } else {
        AmmoType ammo = magazine.back();
        magazine.pop_back();
        currentAmmo--;
        switch (ammo) {
            case REGULAR:
                std::cout << Sounds::Regular << std::endl;
                break;
            case PLASMA:
                std::cout << Sounds::Plasma << std::endl;
                break;
            case ROCKET:
                std::cout << Sounds::Rocket << std::endl;
                break;
        }
    }
}

void Phaser::ejectClip()
{
    magazine.clear();
    currentAmmo = Empty;
}

void Phaser::changeType(AmmoType newType)
{
    defaultType = newType;
    std::string typeStr;
    switch (newType) {
        case REGULAR:
            typeStr = "regular";
            break;
        case PLASMA:
            typeStr = "plasma";
            break;
        case ROCKET:
            typeStr = "rocket";
            break;
    }
    std::cout << "Switching ammo to type: " << typeStr << std::endl;
}

void Phaser::reload() {
    std::cout << "Reloading..." << std::endl;
    magazine.resize(maxAmmo, defaultType);
    currentAmmo = maxAmmo;
}

void Phaser::addAmmo(AmmoType type)
{
    if (currentAmmo == maxAmmo) {
        std::cout << "Clip full" << std::endl;
    } else {
        magazine.push_back(type);
        currentAmmo++;
    }
}

int Phaser::getCurrentAmmos() const
{
    return currentAmmo;
}

