/*
** EPITECH PROJECT, 2025
** rush_3 [WSL: Ubuntu]
** File description:
** Dial Implementation
*/

#include "Dial.hpp"
#include <cmath>

Dial::Dial(int x, int y, int width, int height, int minValue, int maxValue, bool showBg, float needleThickness, sf::Color needleColor1, sf::Color needleColor2)
    : ADisplay(x, y, width, height),
    _minValue(minValue), _maxValue(maxValue), _value(minValue),
    _showBg(showBg), _needleThickness(needleThickness), _needleColor1(needleColor1), _needleColor2(needleColor2)
{
}

void Dial::update(void *newData)
{
    _value = *static_cast<int *>(newData);
    if (_value < _minValue)
        _value = _minValue;
    if (_value > _maxValue)
        _value = _maxValue;
}

void Dial::renderSFML(sf::RenderWindow &window, bool enabled)
{
    if (!enabled)
        return;
    float radius = _width / 2.f;
    sf::Vector2f center(_x + radius, _y + radius);

    if (_showBg) {
        const int segments = 32;
        sf::VertexArray background(sf::TriangleFan, segments + 2);

        sf::CircleShape circle(radius + 10);
        circle.setOrigin(radius + 10, radius + 10);
        circle.setPosition(center);
        circle.setFillColor(_needleColor1);
        window.draw(circle);

        background[0].position = center;
        background[0].color = sf::Color(100, 100, 100, 255);

        for (int i = 0; i <= segments; ++i) {
            float angle = (i * 2 * M_PI) / segments;
            background[i + 1].position = sf::Vector2f(
                center.x + radius * cos(angle),
                center.y + radius * sin(angle)
            );
            background[i + 1].color = sf::Color(50, 50, 50, 255);
        }

        window.draw(background);
    }

    sf::CircleShape border(radius);
    border.setPosition(_x, _y);
    border.setFillColor(sf::Color::Transparent);
    border.setOutlineThickness(2);
    border.setOutlineColor(sf::Color::Black);
    window.draw(border);

    float proportion = (_value - _minValue) / static_cast<float>(_maxValue - _minValue);
    float angleDeg = -90 + proportion * 360;
    float angleRad = angleDeg * M_PI / 180.f;

    float needleLength = radius * 0.9f;
    float needleWidth = radius * _needleThickness;
    float perpAngle = angleRad + M_PI/2;

    sf::VertexArray needle(sf::Triangles, 3);

    needle[0].position = sf::Vector2f(
        center.x + needleLength * cos(angleRad),
        center.y + needleLength * sin(angleRad)
    );
    needle[0].color = _needleColor2;

    needle[1].position = sf::Vector2f(
        center.x + needleWidth * cos(perpAngle),
        center.y + needleWidth * sin(perpAngle)
    );
    needle[1].color = _needleColor1;

    needle[2].position = sf::Vector2f(
        center.x - needleWidth * cos(perpAngle),
        center.y - needleWidth * sin(perpAngle)
    );
    needle[2].color = _needleColor1;

    window.draw(needle);


    float centerCircleRadius = needleWidth * 1.0f;
    sf::CircleShape centerCircle(centerCircleRadius);
    centerCircle.setFillColor(sf::Color(50, 50, 50));
    centerCircle.setOrigin(centerCircleRadius, centerCircleRadius);
    centerCircle.setPosition(center);
    window.draw(centerCircle);
}
