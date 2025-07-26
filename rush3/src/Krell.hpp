/*
** EPITECH PROJECT, 2025
** Krell
** File description:
** Header
*/

#ifndef KRELL_H_
    #define KRELL_H_

#include "Module/AModule.hpp"

#include <iostream>
#include <vector>
#include <SFML/Window.hpp>
#include <ncurses.h>

class Krell {
    public:
        Krell();
        Krell(int width, int height, std::string args = "");

        ~Krell();

        void run();
        void setNcurse(bool ncurse) { _ncurse = ncurse; }
    protected:
        void renderSFML();
        void renderNCURSE();
        void render() { _graphicalMode ? renderSFML() : renderNCURSE(); }
        void events();
        void update();
        void scrollSFML(int yValue, int mult = 20);

    private:
        bool _graphicalMode;
        WINDOW *_win;
        sf::RenderWindow *_window;
        std::vector<AModule *> _modules;
        std::vector<WINDOW *> _boxes;
        sf::Clock _clock = sf::Clock();
        int _updateDelta = 1000;
        bool _ncurse = false;
};

#endif /* !KRELL_H_ */
