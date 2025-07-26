/*
** EPITECH PROJECT, 2025
** rush_3 [WSL: Ubuntu]
** File description:
** IDisplay
*/

#ifndef IDISPLAY_HPP_
#define IDISPLAY_HPP_

#include <SFML/Graphics.hpp>

class IDisplay
{
    public:
        virtual ~IDisplay() = default;

        virtual void update( void *newData ) = 0;
        virtual void events() = 0;
        virtual void renderSFML( sf::RenderWindow &window, bool enabled) = 0;
        virtual void setPos( int x, int y ) = 0;
        virtual int getX() const = 0;
        virtual int getY() const = 0;

};

#endif /* !IDISPLAY_HPP_ */
