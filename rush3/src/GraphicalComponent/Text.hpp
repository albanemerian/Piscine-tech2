#ifndef TEXTCOMPONENT_HPP_
#define TEXTCOMPONENT_HPP_

#include "ADisplay.hpp"
#include <SFML/Graphics.hpp>
#include <string>

class Text : public ADisplay {
    public:
        Text(int x = 0, int y = 0, int width = 100, int height = 100, const std::string &text = "Default Text", unsigned int fontSize = 20);

        void update(void *newData) override;
        void renderSFML(sf::RenderWindow &window, bool enabled) override;

    private:
        std::string _text;
        sf::Font _font;
        unsigned int _fontSize;
};

#endif /* !TEXTCOMPONENT_HPP_ */
