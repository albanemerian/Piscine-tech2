/*
** EPITECH PROJECT, 2025
** rush_3 [WSL: Ubuntu]
** File description:
** Module
*/

#ifndef MODULE_HPP_
#define MODULE_HPP_

#include "IModule.hpp"
#include "../GraphicalComponent/IDisplay.hpp"

#include <vector>

class AModule : public IModule {
    public:
        AModule(int xpos = 0, int ypos = 0);
        ~AModule();

        void renderSFML( sf::RenderWindow &window ) const override;
        void renderNCURSE(std::vector<WINDOW*>& boxe);
        void update() override {};
        void events() override {};
        bool isEnable() const override  { return _enable; }
        void setEnable(bool enable) { _enable = enable; }
        void addComponent(IDisplay *component) override {_components.push_back(component); }
        void clearComponents() override { _components.clear(); }
        sf::Vector2i getSize() override {return {400, 100} ;};
        sf::Vector2i getPosition() const { return pos; }
        void setPosition(int x, int y);

    protected:
        sf::Vector2i pos = {0, 0};
        bool _enable;
        std::vector<IDisplay *> _components;
};

#endif /* !MODULE_HPP_ */
