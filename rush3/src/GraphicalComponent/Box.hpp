/*
** EPITECH PROJECT, 2025
** rush3
** File description:
** Box
*/

#pragma once

#include <iostream>
#include <ncurses.h>
#include "Text.hpp"
#include "ADisplay.hpp"

class Box : public ADisplay {
  public:
    Box(int x = 0, int y = 0, int width = 400, int height = 100, std::string title = "");
    ~Box();
    void update(void *newData) override;
    void renderSFML(sf::RenderWindow &window, bool enabled) override;

  private:
    std::string _title;
};
