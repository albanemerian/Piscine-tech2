/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGRUSH3-albane.merian
** File description:
** ProcModule
*/

#include "ProcModule.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <algorithm>

ProcModule::ProcModule()
{
    getOsType();
    setModule();
}

ProcModule::~ProcModule()
{
}

void ProcModule::update()
{
    setModule();
}

void ProcModule::setModule()
{
    _nbProc = 0;
    _nbProcRunning = 0;
    _nbProcSleeping = 0;
    _nbProcZombie = 0;

    DIR* dir = opendir("/proc");
    if (!dir) {
        std::cout << "Error: could not load /proc" << std::endl;
        exit(84);
    }

    struct dirent* entry;

    while ((entry = readdir(dir)) != nullptr) {
        if (entry->d_type == DT_DIR) {
            std::string dirname = entry->d_name;
            if (dirname.empty() || !std::all_of(dirname.begin(), dirname.end(), ::isdigit))
                continue;

            try {
                int pid = std::stoi(dirname);
                if (pid > 0) {
                    _nbProc++;

                    std::string statusFilePath = "/proc/" + dirname + "/stat";
                    std::ifstream statusFile(statusFilePath);
                    std::string line;

                    if (std::getline(statusFile, line)) {
                        std::istringstream iss(line);
                        std::string state;
                        iss >> state >> state;

                        iss >> state;
                        if (state == "R") _nbProcRunning++;
                        else if (state == "S") _nbProcSleeping++;
                        else if (state == "Z") _nbProcZombie++;
                    }
                }
            } catch (const std::exception& e) {
                continue;
            }
        }
    }

    closedir(dir);
    return;
}


unsigned int ProcModule::getNbProc() const
{
    return _nbProc;
}

unsigned int ProcModule::getNbProcRunning() const
{
    return _nbProcRunning;
}

unsigned int ProcModule::getNbProcSleeping() const
{
    return _nbProcSleeping;
}

unsigned int ProcModule::getNbProcZombie() const
{
    return _nbProcZombie;
}

void ProcModule::renderNCURSE(std::vector<WINDOW*> &boxe)
{
    update();

    int boxHeight = 6;
    int boxWidth = 60;
    int startY = 41;
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
    mvwprintw(boxWin, 0, 2, " PROCESSES ");
    wattroff(boxWin, COLOR_PAIR(1));
    mvwprintw(boxWin, 2, 2, "Total Processes: %d", _nbProc);
    mvwprintw(boxWin, 3, 2, "Running: %d  | Sleeping: %d  | Zombie: %d", _nbProcRunning, _nbProcSleeping, _nbProcZombie);
    boxe.push_back(boxWin);
    wrefresh(boxWin);
}
