/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGRUSH3-albane.merian
** File description:
** RamModule
*/

#include "RamModule.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <ncurses.h>

RamModule::RamModule(int xpos, int ypos)
    : AModule(xpos, ypos)
{
    getOsType();
    setModule();

    _titleText = Text(pos.x + 15, pos.y + 10, 280, 100, "RAM USAGE:");
    addComponent(&_titleText);

    _ramUsageText = Text(pos.x + 15, pos.y + 40, 280, 100, "0/0MB", 25U);
    addComponent(&_ramUsageText);

    _ramGraph = Graph(pos.x + 305, pos.y + 5, 90, 90, _totalRam, 0, 15);
    addComponent(&_ramGraph);

    _background = Box(pos.x, pos.y, 400, 100, "RAM");
    addComponent(&_background);
}

void RamModule::update()
{
    setModule();
    std::string ramUsage = std::to_string(getUsedRam()) + "/" + std::to_string(getTotalRam()) + " MB";
    _ramUsageText.update(&ramUsage);

    int usedRam = (int)getUsedRam();
    _ramGraph.update(&usedRam);
}

unsigned long RamModule::getTotalRam() const
{
    return _totalRam;
}

unsigned long RamModule::getFreeRam() const
{
    return _totalRam - _usedRam;
}

unsigned long RamModule::getUsedRam() const
{
    return _usedRam;
}

void RamModule::setModule()
{
    std::ifstream meminfo("/proc/meminfo");
    if (!meminfo) {
        std::cout << "Error: Could not open /proc/meminfo" << std::endl;
        exit(84);
    }
    std::string key;
    unsigned long value;
    std::string unit;

    unsigned long memTotal = 0;
    unsigned long memAvailable = 0;

    while (meminfo >> key >> value >> unit) {
        if (key == "MemTotal:") {
            memTotal = value;
        }
        if (key == "MemAvailable:") {
            memAvailable = value;
            break;
        }
    }

    _totalRam = memTotal;
    _usedRam = _totalRam - memAvailable;
    return;
}
void RamModule::updates()
{
    setModule();
}

void RamModule::renderNCURSE(std::vector<WINDOW*> &boxe)
{
    updates();

    int boxHeight = 6;
    int boxWidth = 60;  
    int startY = 2 * 6 + 1;
    int startX = 0;    
    int percent = (_usedRam * 100) / _totalRam;
    int barWidth = 50;

    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);

    WINDOW* boxWin = newwin(boxHeight, boxWidth, startY, startX);
    if (boxWin == nullptr) {
        printw("Failed to create window\n");
        return;
    }

    box(boxWin, 0, 0);
    wattron(boxWin, COLOR_PAIR(1));
    mvwprintw(boxWin, 0, 2, " RAM ");
    wattroff(boxWin, COLOR_PAIR(1));

    mvwprintw(boxWin, 2, 2, "Total RAM: %lu MB  Used: %lu MB  Free: %lu MB",
                _totalRam / 1024, _usedRam / 1024, getFreeRam() / 1024);

    int barStartY = 4;
    int barStartX = 2;
    mvwprintw(boxWin, barStartY, barStartX, "[");

    for (int i = 0; i < percent / 2; i++) {
        int color = (i < 30) ? 1 : ((i < 45) ? 2 : 3);
        wattron(boxWin, COLOR_PAIR(color));
        mvwprintw(boxWin, barStartY, barStartX + 1 + i, "=");
        wattroff(boxWin, COLOR_PAIR(color));
    }
    for (int i = percent / 2; i < barWidth; i++) {
        mvwprintw(boxWin, barStartY, barStartX + 1 + i, "-");
    }

    mvwprintw(boxWin, barStartY, barStartX + barWidth + 1, "] %02d%%", percent);

    boxe.push_back(boxWin);
    wrefresh(boxWin);
}
