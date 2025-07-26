/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGRUSH3-albane.merian
** File description:
** IModule
*/

#ifndef IMODULE_HPP_
#define IMODULE_HPP_

#include <SFML/Graphics.hpp>
#include <ncurses.h>
#include "../GraphicalComponent/IDisplay.hpp"

class IModule {
    public:
        ~IModule() = default;

        virtual void update() = 0;
        virtual void events() = 0;
        virtual void renderSFML( sf::RenderWindow &window ) const = 0;
        virtual void renderNCURSE(std::vector<WINDOW*> &boxe) = 0;
        virtual void addComponent(IDisplay *component) = 0;
        virtual void clearComponents() = 0;
        virtual sf::Vector2i getSize() = 0;

        virtual bool isEnable() const = 0;


    protected:
    private:
};

#endif /* !IMODULE_HPP_ */
