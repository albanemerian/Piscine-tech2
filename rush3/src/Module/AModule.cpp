/*
** EPITECH PROJECT, 2025
** rush_3 [WSL: Ubuntu]
** File description:
** AModule
*/

#include "AModule.hpp"

AModule::AModule(int xpos, int ypos)
    : pos(xpos, ypos), _enable(true)
{
}

AModule::~AModule()
{
    for (auto component : _components) {
        delete component;
    }
}

void AModule::renderSFML(sf::RenderWindow &window) const
{
    bool enabled = isEnable();

    for (const auto component : _components) {
        component->renderSFML(window, enabled);
    }
}

void AModule::renderNCURSE(std::vector<WINDOW*> &boxe)
{
    (void)boxe;
}

void AModule::setPosition(int x, int y)
{
    int xDelta = x - pos.x;
    int yDelta = y - pos.y;

    pos.x = x;
    pos.y = y;

    for (auto component : _components) {
        component->setPos(component->getX() + xDelta, component->getY() + yDelta);
    }
}
