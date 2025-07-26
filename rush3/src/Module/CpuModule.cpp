/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGRUSH3-albane.merian
** File description:
** cpuModule
*/

#include "CpuModule.hpp"
#include <iostream>
#include <thread>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <list>
#include <unistd.h>
#include <cstdio>

CpuModule::CpuModule(int x, int y) : AModule(x, y)
{
    setModule();
    CpuModule::LinkedList cpuList = this->getList();
    int i = 0;

    if (cpuList.empty()) {
        std::cout << "Error: Could not retrieve CPU info" << std::endl;
        return;
    }

    std::string cpuModel = cpuList.front()._model;
    std::string cpuFreq = cpuList.front()._freq;


    _cpuName = new Text(pos.x + 60, pos.y + 10, 280, 100, cpuModel, 25);
    addComponent(_cpuName);

    for (auto &cpuInfo : cpuList) {

        sf::Vector2i currentPos = {pos.x, pos.y + (100 * (i + 1))};

        Text *cpuTitle = new Text(currentPos.x + 15, currentPos.y + 10, 280, 100, "CPU " + std::to_string(i) + ":");
        _coreTitle.push_back(cpuTitle);
        addComponent(cpuTitle);

        Text *cpuFreq = new Text(currentPos.x + 15, currentPos.y + 40, 280, 100, cpuInfo._freq.c_str(), 25);
        _coreFreq.push_back(cpuFreq);
        addComponent(cpuFreq);

        Graph *cpuGraph = new Graph(currentPos.x + 305, currentPos.y + 5, 90, 90, 10000, 0, 15);
        _coreGraph.push_back(cpuGraph);
        addComponent(cpuGraph);

        i++;
    }

    _globalBackground = new Box(pos.x, pos.y, 400, 110 + 100 * i, "CPU");
    addComponent(_globalBackground);

}

unsigned int CpuModule::getNbCpu()
{
    unsigned int n = std::thread::hardware_concurrency();
    _nbCpu = n;
    return 0;
}

void CpuModule::LinuxModule()
{
    _nbCpu = sysconf(_SC_NPROCESSORS_ONLN);
    std::ifstream cpuInfo("/proc/cpuinfo");
    if (!cpuInfo) {
        std::cout << "Error: Could not open /proc/cpuinfo" << std::endl;
        exit(0);
    }
    std::string line;
    LinkedCpuModule cpuData;

    while (std::getline(cpuInfo, line)) {
        if (line.find("model name") != std::string::npos) {
            size_t pos = line.find(":");
            if (pos != std::string::npos) {
                std::string model = line.substr(pos + 2);
                cpuData._modeleCPU.push_back(model);
                cpuData._model = model;
            }
        }
        if (line.find("cpu MHz") != std::string::npos) {
            size_t pos = line.find(":");
            if (pos != std::string::npos) {
                std::string freq = line.substr(pos + 2) + " MHz";
                cpuData._freqCPU.push_back(freq);
                cpuData._freq = freq;
            }
        }
        if (line.empty()) {
            _listCpu.push_back(cpuData);
            cpuData = LinkedCpuModule();
        }
    }
    cpuInfo.close();
}

void CpuModule::setModule()
{
    this->_listCpu.clear();
    LinuxModule();
}

void CpuModule::update()
{
    setModule();

    int i = 0;
    int globalFreq = 0;
    CpuModule::LinkedList listCpu = this->getList();
    std::string cpuName;

    for (auto &cpuInfo : listCpu) {
        int freqValue = std::stoi(cpuInfo._freq);
        _coreGraph.at(i)->update(&freqValue);
        _coreFreq.at(i)->update(&cpuInfo._freq);
        globalFreq += freqValue;
        i++;
        cpuName = cpuInfo._model;
    }
    globalFreq /= _nbCpu;
    std::string globalFreqStr = cpuName + ": " + std::to_string(globalFreq) + " MHz";
    _cpuName->update(&globalFreqStr);
}

void CpuModule::renderNCURSE(std::vector<WINDOW*> &boxe)
{
    update();
    int boxHeight = 10;  // Height to fit all content plus borders
    int boxWidth = 60;
    int startY = 3 * 6 + 1;
    int startX = 0;

    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    WINDOW* boxWin = newwin(boxHeight, boxWidth, startY, startX);
    if (boxWin == nullptr) {
        printw("Failed to create window\n");
        return;
    }
    int win_height = getmaxy(boxWin) - 2;
    scrollok(boxWin, TRUE);
    keypad(boxWin, TRUE);
    box(boxWin, 0, 0);
    wattron(boxWin, COLOR_PAIR(1));
    mvwprintw(boxWin, 0, 2, " CPU [%d/%u]", _scroll_pos + 1, _nbCpu);
    wattroff(boxWin, COLOR_PAIR(1));

    for (int i = 1; i < getmaxy(boxWin) - 1; i++)
        mvwhline(boxWin, i, 1, ' ', getmaxx(boxWin) - 2);

    _scroll_pos++;
    if (_scroll_pos >= _listCpu.size())
        _scroll_pos = 0;

    int i = 0;
    for (const auto& cpuInfo : _listCpu) {
        int pos = (_scroll_pos + i) % _listCpu.size();
        auto it = std::next(_listCpu.begin(), pos);
        mvwprintw(boxWin, i + 1, 2, "Core %d - %s", pos, it->_freq.c_str());
        i++;
        if (i >= win_height) break;  // Stop printing if window height is reached
    }

    // Redraw box and title
    box(boxWin, 0, 0);
    wattron(boxWin, COLOR_PAIR(1));
    mvwprintw(boxWin, 0, 2, " CPU [%d/%zu] ", _scroll_pos + 1, _listCpu.size());
    wattroff(boxWin, COLOR_PAIR(1));
    wrefresh(boxWin);

    boxe.push_back(boxWin);
}
