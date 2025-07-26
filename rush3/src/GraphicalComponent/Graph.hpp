/*
** EPITECH PROJECT, 2025
** rush_3 [WSL: Ubuntu]
** File description:
** Graph
*/

#ifndef GRAPH_HPP_
#define GRAPH_HPP_

#include "ADisplay.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

class Graph : public ADisplay {
    public:
        Graph( int x = 0, int y = 0, int width = 100, int height = 100, int maxData = 1000, int minData = 0, int nDataDisplayed = 10 );

        void update(void *newData) override;
        void renderSFML( sf::RenderWindow &window, bool enabled ) override;

    protected:
    private:
        int _maxData;
        int _minData;
        size_t _nDataDisplayed;
        std::vector<int> _data;
};

#endif /* !GRAPH_HPP_ */
