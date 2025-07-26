/*
** EPITECH PROJECT, 2025
** rush_3 [WSL: Ubuntu]
** File description:
** Graph
*/

#include "Graph.hpp"
#include <ncurses.h>
#include <iostream>

Graph::Graph( int x, int y, int width, int height, int maxData, int minData, int nDataDisplayed)
    : ADisplay(x, y, width, height), _maxData(maxData), _minData(minData), _nDataDisplayed(nDataDisplayed)
{
}

void Graph::update(void *newData)
{
    _data.push_back(*static_cast<int *>(newData));
    if (_data.size() > _nDataDisplayed)
        _data.erase(_data.begin());
}

void Graph::renderSFML(sf::RenderWindow &window, bool enabled)
{
    if (!enabled)
        return;
    sf::VertexArray background(sf::Quads, 4);
    background[0].position = sf::Vector2f(_x - 5, _y + _height + 5);
    background[1].position = sf::Vector2f(_x + _width + 5, _y + _height + 5);
    background[2].position = sf::Vector2f(_x + _width + 5, _y - 5);
    background[3].position = sf::Vector2f(_x - 5, _y - 5);

    background[0].color = sf::Color(50, 50, 50, 255);
    background[1].color = sf::Color(50, 50, 50, 255);
    background[2].color = sf::Color(100, 100, 100, 255);
    background[3].color = sf::Color(100, 100, 100, 255);

    window.draw(background);

    for (size_t i = 0; i < _data.size(); i++) {
        float barWidth = _width / _nDataDisplayed;
        float barHeight = _height * (_data[i] - _minData) / (_maxData - _minData);
        float barX = _x + (_data.size() - 1 - i) * barWidth;
        float barY = _y + _height - barHeight;

        sf::VertexArray gradientBar(sf::Quads, 4);
        gradientBar[0].position = sf::Vector2f(barX, barY);
        gradientBar[1].position = sf::Vector2f(barX + barWidth, barY);
        gradientBar[2].position = sf::Vector2f(barX + barWidth, barY + barHeight);
        gradientBar[3].position = sf::Vector2f(barX, barY + barHeight);

        gradientBar[0].color = sf::Color(255, 0, 0, 255);
        gradientBar[1].color = sf::Color(255, 0, 0, 255);
        gradientBar[2].color = sf::Color(0, 0, 255, 255);
        gradientBar[3].color = sf::Color(0, 0, 255, 255);

        window.draw(gradientBar);
    }
}
