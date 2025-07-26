/*
** EPITECH PROJECT, 2025
** rush3
** File description:
** Box
*/

#include <cmath>
#include <algorithm>
#include "Box.hpp"
#include "Text.hpp"

Box::Box(int x, int y, int width, int height, std::string title)
    : ADisplay(x, y, width, height), _title(title)
{
}

Box::~Box()
{
}

void Box::update(void *newData)
{
    _title = *static_cast<std::string *>(newData);
}


void Box::renderSFML(sf::RenderWindow &window, bool enabled)
{
    float w;
    float h;
    float r;

    if (enabled) {
        r = std::min(_width, _height) * 0.1f;
        w = _width;
        h = _height;
    } else {
        r = std::min(400, 100) * 0.1f;
        w = 400;
        h = 100;
    }

    const int segments = 10;
    const int totalPoints = segments * 4;
    sf::ConvexShape roundedRect;
    roundedRect.setPointCount(totalPoints);

    int pointIndex = 0;
    float x = _x;
    float y = _y;

    sf::Vector2f tl(x + r, y + r);
    for (int i = 0; i < segments; i++) {
        float angle = 180.f + (90.f * i) / (segments - 1);
        float rad = angle * static_cast<float>(M_PI) / 180.f;
        roundedRect.setPoint(pointIndex++, sf::Vector2f(tl.x + r * cos(rad), tl.y + r * sin(rad)));
    }

    sf::Vector2f tr(x + w - r, y + r);
    for (int i = 0; i < segments; i++) {
        float angle = 270.f + (90.f * i) / (segments - 1);
        float rad = angle * static_cast<float>(M_PI) / 180.f;
        roundedRect.setPoint(pointIndex++, sf::Vector2f(tr.x + r * cos(rad), tr.y + r * sin(rad)));
    }

    sf::Vector2f br(x + w - r, y + h - r);
    for (int i = 0; i < segments; i++) {
        float angle = 0.f + (90.f * i) / (segments - 1);
        float rad = angle * static_cast<float>(M_PI) / 180.f;
        roundedRect.setPoint(pointIndex++, sf::Vector2f(br.x + r * cos(rad), br.y + r * sin(rad)));
    }

    sf::Vector2f bl(x + r, y + h - r);
    for (int i = 0; i < segments; i++) {
        float angle = 90.f + (90.f * i) / (segments - 1);
        float rad = angle * static_cast<float>(M_PI) / 180.f;
        roundedRect.setPoint(pointIndex++, sf::Vector2f(bl.x + r * cos(rad), bl.y + r * sin(rad)));
    }

    roundedRect.setFillColor(sf::Color::Transparent);
    roundedRect.setOutlineThickness(2);
    roundedRect.setOutlineColor(sf::Color::White);

    window.draw(roundedRect);

    if (!enabled) {
        Text(_x + 100, _y + 20, 400, 100, _title, 25).renderSFML(window, true);
    }

}
