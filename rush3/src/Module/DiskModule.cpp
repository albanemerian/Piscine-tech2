/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGRUSH3-albane.merian
** File description:
** DiskModule
*/

#include "DiskModule.hpp"
#include <iostream>
#include <fstream>
#include <sys/statvfs.h>

DiskModule::DiskModule()
{
    getOsType();
    setModule();
}

DiskModule::DiskModule(int x, int y)
    : AModule(x, y)
{
    getOsType();
    setModule();

    _background = new Box(pos.x, pos.y, 400, 200, "Disk");
    addComponent(_background);

    _diskText = new Text(pos.x + 50, pos.y + 20, 280, 100, "Disk: " + std::to_string(_usedDisk) + " / " + std::to_string(_totalDisk) + " MB", 25);
    addComponent(_diskText);

    _swapText = new Text(pos.x + 50, pos.y + 100, 280, 100, "Swap: " + std::to_string(_totalSwap - _freeSwap) + " / " + std::to_string(_totalSwap) + " MB", 25);
    addComponent(_swapText);

}

DiskModule::~DiskModule()
{
}

unsigned long DiskModule::getSwapTotal() const
{
    return _totalSwap;
}

unsigned long DiskModule::getSwapFree() const
{
    return _freeSwap;
}

unsigned long DiskModule::getDiskTotal() const
{
    return _totalDisk;
}

unsigned long DiskModule::getDiskUsed() const
{
    return _usedDisk;
}

unsigned long DiskModule::getDiskFree() const
{
    return _freeDisk;
}



void DiskModule::setDisk()
{
    std::string path = "/";
    struct statvfs stat;
    if (statvfs(path.c_str(), &stat) == 0) {
        _totalDisk = stat.f_blocks * stat.f_frsize;
        _freeDisk = stat.f_bavail * stat.f_frsize;
        _usedDisk = _totalDisk - _freeDisk;
    } else {
        std::cout << "Error: Could not retrieve disk stats for " << path << std::endl;
    }
    return;
}

void DiskModule::setSwap()
{
    std::ifstream meminfo("/proc/meminfo");
    if (!meminfo) {
        std::cout << "Error: Could not open /proc/meminfo" << std::endl;
        exit(0);
    }

    std::string key;
    unsigned long value;
    std::string unit;

    while (meminfo >> key >> value >> unit) {
        if (key == "SwapTotal:") {
            _totalSwap = value;
        } else if (key == "SwapFree:") {
            _freeSwap = value;
        }
    }

    meminfo.close();
}

void DiskModule::setModule()
{
    setDisk();
    setSwap();
    return;
}

void DiskModule::update()
{
    setModule();

    // int swapUsed = _totalSwap - _freeSwap;
    // int diskUsed = _usedDisk;

    std::string disk = "Disk: " + std::to_string(_usedDisk) + " / " + std::to_string(_totalDisk) + " MB";
    std::string swap = "Swap: " + std::to_string(_totalSwap - _freeSwap) + " / " + std::to_string(_totalSwap) + " MB";
    _diskText->update(&disk);
    _swapText->update(&swap);
    return;
}

void DiskModule::updates()
{
    setModule();
}

void DiskModule::renderNCURSE(std::vector<WINDOW*>& boxe)
{
    updates();
    int boxHeight = 6;
    int boxWidth = 60;
    float startY = 29.5;
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
    mvwprintw(boxWin, 0, 2, " DISK / SWAP ");
    wattroff(boxWin, COLOR_PAIR(1));

    int diskUsage = (_usedDisk * 25) / _totalDisk;
    mvwprintw(boxWin, 2, 2, "Disk: ");
    for (int i = 0; i < diskUsage; i++) {
        int color = (i < 20) ? 1 : (i < 35 ? 2 : 3);
        wattron(boxWin, COLOR_PAIR(color));
        mvwprintw(boxWin, 2, 9 + i, "=");
        wattroff(boxWin, COLOR_PAIR(color));
    }
    int i = diskUsage;
    for (; i < 25; i++) {
        mvwprintw(boxWin, 2, 9 + i, "-");
    }
    mvwprintw(boxWin, 2, 9 + i + 1, "%lu / %lu GB", _usedDisk / (1024 * 1024 * 1024), _totalDisk/ (1024 * 1024 * 1024));

    int _usedSwap = _totalSwap - _freeSwap;
    int swapUsage = (_usedSwap * 25) / _totalSwap;
    mvwprintw(boxWin, 3, 2, "Swap: ");
    for (int i = 0; i < swapUsage; i++) {
        int color = (i < 20) ? 1 : (i < 35 ? 2 : 3);
        wattron(boxWin, COLOR_PAIR(color));
        mvwprintw(boxWin, 3, 9 + i, "=");
        wattroff(boxWin, COLOR_PAIR(color));
    }
    i = swapUsage;
    for (; i < 25; i++) {
        mvwprintw(boxWin, 3, 9 + i, "-");
    }
    mvwprintw(boxWin, 3, 9 + i + 1, "%ld%%", (_usedSwap * 100) / _totalSwap);
    boxe.push_back(boxWin);
    wrefresh(boxWin);
    return;
}
