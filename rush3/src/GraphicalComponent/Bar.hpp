/*
** EPITECH PROJECT, 2025
** rush_3 [WSL: Ubuntu]
** File description:
** Bar
*/

#ifndef BAR_HPP_
    #define BAR_HPP_

#include "ADisplay.hpp"
#include <SFML/Graphics.hpp>

class Bar : public ADisplay {
    public:
        Bar(int x, int y, int width, int height, sf::Color color);
        ~Bar();

        void update(void *newData) override;
        void renderSFML(sf::RenderWindow &window, bool enabled) override;
    private:
        sf::Color _color;
        unsigned int _power;
};

#endif
