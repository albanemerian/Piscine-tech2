/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGRUSH3-albane.merian
** File description:
** BatteryModule
*/

#include "BatteryModule.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

BatteryModule::BatteryModule(int posx, int posy)
    : AModule(posx, posy)
{
    getOsType();
    setModule();

    _background = new Box(posx, posy, 400, 100, "Battery");
    addComponent(_background);

    _bar = new Bar(posx + 20, posy + 55, 300, 20, sf::Color(50, 50, 50));
    addComponent(_bar);

    _power = new Bar(posx + 20, posy + 55, (getBattery() * 300 / 100), 20, (getBattery() >= 40 ? sf::Color(0, 255, 0) : getBattery() >= 10 ? sf::Color(180, 200, 0) : sf::Color(255, 0, 0)));
    addComponent(_power);

    _name = new Text(posx + 20, posy + 15, 100, 100, "Battery", 20);
    addComponent(_name);

    _level = new Text(posx + 340, posy + 53, 100, 100, std::to_string(getBattery()) + "%", 20);
    addComponent(_level);
}

BatteryModule::~BatteryModule()
{
}

unsigned int BatteryModule::getBattery() const
{
    return _battery;
}

void BatteryModule::setModule()
{
    std::ifstream batteryInfo("/sys/class/power_supply/BAT0/capacity");
    std::string battery;
    if (!batteryInfo) {
        std::ifstream batteryInfo("/sys/class/power_supply/BAT1/capacity");
        if (!batteryInfo) {
            std::cout << "Error battery file not found" << std::endl;
            exit(0);
        }
    }
    batteryInfo >> battery;
    _battery = std::stoi(battery);
    std::ifstream tempFile2("/sys/class/power_supply/BAT0/status");
    if (tempFile2) {
        std::string status;
        tempFile2 >> status;
        tempFile2.close();
        _status = status;
    } else {
        _status = "Unknown";
    }
    return;
}

void BatteryModule::renderNCURSE(std::vector<WINDOW*> &boxe)
{
    update();

    int boxHeight = 6;
    int boxWidth = 60;
    int startY = 35.5;
    int startX = 0;

    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_WHITE, COLOR_BLACK);

    WINDOW* boxWin = newwin(boxHeight, boxWidth, startY, startX);
    if (boxWin == nullptr) {
        printw("Failed to create window\n");
        return;
    }
    box(boxWin, 0, 0);
    wattron(boxWin, COLOR_PAIR(1));
    mvwprintw(boxWin, 0, 2, " BATTERY ");
    wattroff(boxWin, COLOR_PAIR(1));
    int barStartY = 2;
    int barStartX = 2;
    mvwprintw(boxWin, barStartY, barStartX, "[");

    for (unsigned int i = 0; i < _battery / 2; i++) {
        int color = (i < 30) ? 1 : ((i < 45) ? 2 : 3);
        wattron(boxWin, COLOR_PAIR(color));
        mvwprintw(boxWin, barStartY, barStartX + 1 + i, "=");
        wattroff(boxWin, COLOR_PAIR(color));
    }
    for (int i = _battery / 2; i < 50; i++) {
        mvwprintw(boxWin, barStartY, barStartX + 1 + i, "-");
    }
    mvwprintw(boxWin, barStartY, barStartX + 50 + 1, "]");
    mvwprintw(boxWin, 3, 2, "Charge: %d%%   Status  %s", _battery, _status.c_str());

    boxe.push_back(boxWin);
    wrefresh(boxWin);
}

void BatteryModule::update()
{
    setModule();

    _power->update(&_battery);
    std::string res = std::to_string(_battery) + "%";
    _level->update(&res);
}
