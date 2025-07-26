/*
** EPITECH PROJECT, 2025
** rush_3 [WSL: Ubuntu]
** File description:
** ADisplay
*/

#ifndef ADISPLAY_HPP_
#define ADISPLAY_HPP_

#include "IDisplay.hpp"

class ADisplay : public IDisplay {
    public:
        ADisplay( int x = 0, int y = 0, int width = 300, int height = 300)
        : _x(x), _y(y), _width(width), _height(height) {};
        virtual ~ADisplay() = default;

        void setPos(int x, int y) { _x = x; _y = y; }
        int getX() const { return _x; }
        int getY() const { return _y; }
        void events() override {};
        virtual void update(void *newData) override { (void)newData; };
        void renderSFML(sf::RenderWindow &window, bool enabled) override { (void)window; (void)enabled; };

    protected:
        int _x;
        int _y;
        int _width;
        int _height;

    private:
};

#endif /* !ADISPLAY_HPP_ */
