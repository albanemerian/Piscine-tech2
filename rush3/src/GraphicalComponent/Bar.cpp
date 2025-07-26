/*
** EPITECH PROJECT, 2025
** rush_3 [WSL: Ubuntu]
** File description:
** Bar
*/

#include "Bar.hpp"
#include <iostream>

Bar::Bar(int x, int y, int width, int height, sf::Color color) :
ADisplay(x, y, width, height), _color(color)
{
}

Bar::~Bar()
{
}

void Bar::update(void *newData)
{
    _power = *static_cast<unsigned int *>(newData);
    _width = _power * 300 / 100;
    _color = _power >= 40 ? sf::Color(0, 255, 0) : (_power > 10 ? sf::Color(200, 180, 0) : sf::Color(255, 0, 0));
}

void Bar::renderSFML(sf::RenderWindow &window, bool enabled)
{
    if (!enabled)
        return;
    sf::RectangleShape bar;

    bar.setSize(sf::Vector2f(_width, _height));
    bar.setPosition(sf::Vector2f(_x, _y));
    bar.setFillColor(_color);
    window.draw(bar);
}
