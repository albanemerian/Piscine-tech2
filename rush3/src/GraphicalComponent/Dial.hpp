/*
** EPITECH PROJECT, 2025
** rush_3 [WSL: Ubuntu]
** File description:
** Dial
*/

#ifndef DIAL_HPP_
#define DIAL_HPP_

#include "ADisplay.hpp"
#include <SFML/Graphics.hpp>

class Dial : public ADisplay {
    public:
      Dial(int x = 0, int y = 0, int width = 100, int height = 100, int minValue = 0, int maxValue = 60, bool showBg = true, float needleThickness = 0.1f, sf::Color needleColor1 = sf::Color(150, 0, 0), sf::Color needleColor2 = sf::Color::Red);

      void update(void *newData) override;
      void renderSFML(sf::RenderWindow &window, bool enabled) override;

    private:
      int _minValue;
      int _maxValue;
      int _value;
      bool _showBg;
      float _needleThickness;
      sf::Color _needleColor1;
      sf::Color _needleColor2;
};

#endif /* !DIAL_HPP_ */
