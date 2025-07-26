/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGRUSH3-albane.merian
** File description:
** Text
*/

#include "Text.hpp"
#include <iostream>
#include <ncurses.h>
#include "Text.hpp"
#include <iostream>
#include <sstream>
#include <vector>

Text::Text(int x, int y, int width, int height, const std::string &text, unsigned int fontSize)
    : ADisplay(x, y, width, height), _text(text), _fontSize(fontSize)
{
    if (_font.loadFromFile("./assets/fonts/Arial.ttf")) {
        return;
    } else {
        std::cout << "Error: Could not load font 'Arial.ttf'" << std::endl;
    }
}

void Text::update(void *newData)
{
    _text = *static_cast<std::string *>(newData);
}

void Text::renderSFML(sf::RenderWindow &window, bool enabled)
{
    if (!enabled)
        return;

    std::istringstream stream(_text);
    std::string word;
    std::string line;
    std::vector<std::string> lines;

    sf::Text measure;
    measure.setFont(_font);
    measure.setCharacterSize(_fontSize);

    while (stream >> word) {
        std::string temp = line.empty() ? word : line + " " + word;
        measure.setString(temp);
        if (measure.getLocalBounds().width > static_cast<float>(_width)) {
            if (line.empty()) {
                lines.push_back(word);
            } else {
                lines.push_back(line);
                line = word;
            }
        } else {
            line = temp;
        }
    }
    if (!line.empty())
        lines.push_back(line);

    float offsetY = 0.f;
    for (const auto &ln : lines) {
        sf::Text textDrawing;
        textDrawing.setFont(_font);
        textDrawing.setString(ln);
        textDrawing.setCharacterSize(_fontSize);
        textDrawing.setFillColor(sf::Color::White);
        textDrawing.setPosition(static_cast<float>(_x), static_cast<float>(_y) + offsetY);
        window.draw(textDrawing);

        offsetY += textDrawing.getLocalBounds().height + 5.f;
    }
}
