/*
** EPITECH PROJECT, 2025
** rush_3 [WSL: Ubuntu]
** File description:
** Krell
*/

#include <unistd.h>
#include <ncurses.h>
#include "Krell.hpp"
#include "Module/DateTime.hpp"
#include "Module/HostModule.hpp"
#include "Module/RamModule.hpp"
#include "Module/CpuModule.hpp"
#include "Module/DiskModule.hpp"
#include "Module/BatteryModule.hpp"
#include "Module/NetworkModule.hpp"
#include "Module/ProcModule.hpp"

Krell::Krell()
    :   _graphicalMode(false)
{
    initscr();
    noecho();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    curs_set(0);
    _modules.push_back(new DateTime());
    _modules.push_back(new HostModule());
    _modules.push_back(new RamModule());
    _modules.push_back(new CpuModule());
    _modules.push_back(new DiskModule());
    _modules.push_back(new BatteryModule());
    _modules.push_back(new ProcModule());
    _modules.push_back(new NetworkModule());

    _ncurse = true;
}

Krell::Krell(int width, int height, std::string args)
    :   _graphicalMode(true),
        _window(new sf::RenderWindow(sf::VideoMode(width, height), "MyGKrellm"))
{
    int yoffset = 50;
    int xoffset = 50;

    if (args.find("kernel") == std::string::npos) {
        HostModule *hostModule = new HostModule(xoffset, yoffset, true);
        _modules.push_back(hostModule);
        yoffset += 110;
    }

    if (args.find("datetime") == std::string::npos) {
        DateTime *dateTime = new DateTime(xoffset, yoffset);
        yoffset += 110;
        _modules.push_back(dateTime);
    }

    if (args.find("battery") == std::string::npos) {
        BatteryModule *batteryModule = new BatteryModule(xoffset, yoffset);
        yoffset += 110;
        _modules.push_back(batteryModule);
    }

    if (args.find("ram") == std::string::npos) {
        RamModule *ramModule = new RamModule(xoffset, yoffset);
        yoffset += 110;
        _modules.push_back(ramModule);
    }

    if (args.find("disk") == std::string::npos) {
        DiskModule *diskModule = new DiskModule(xoffset, yoffset);
        yoffset += 210;
        _modules.push_back(diskModule);
    }

    if (args.find("cpu") == std::string::npos) {
        CpuModule *cpuModule = new CpuModule(xoffset, yoffset);
        yoffset += 110;
        _modules.push_back(cpuModule);
    }

    _ncurse = false;
    _window->setFramerateLimit(60);
}

Krell::~Krell()
{
    if (_window)
        delete _window;
}

void handleResize(WINDOW*& win, int& height, int& width)
{
    getmaxyx(stdscr, height, width);

    if (win) {
        delwin(win);
    }
    win = newwin(height / 2, width - 2, 1, 1);
    box(win, 0, 0);
    mvwprintw(win, 1, 2, "Resized to: %d x %d", height, width);
    wrefresh(win);
}

void Krell::run()
{
    if (_ncurse == false) {
        while (_window->isOpen()) {
            events();
            update();
            render();
        }
        return;
    }
    nodelay(stdscr, TRUE);
    int ch;
    while ((ch = getch()) != 'q') {
        // clear();
        render();
        usleep(100000);  // Control the refresh rate
    }
    endwin();
    exit(0);
    // int ch;
    // while (1) {
    //     clear();
    //     render();
    //     ch = getch();
    //     if (ch == 'q') {
    //         clear();
    //         endwin();
    //         exit(0);
    //     }

    // }
    // endwin();
    // exit(0);
}

void Krell::renderSFML()
{
    _window->clear();

    for (const auto module : _modules) {
        module->renderSFML(*_window);
    }
    _window->display();
}

void Krell::renderNCURSE()
{

    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);

    for (WINDOW* win : _boxes) {
        delwin(win);
    }
    _boxes.clear();
    for (const auto module : _modules) {
        module->renderNCURSE(_boxes);
    }
    for (WINDOW* win : _boxes) {
        wrefresh(win);
    }
    doupdate(); 
    napms(400);
}

static void handleModuleClick(int xMouse, int yMouse, std::vector<AModule *> &modules)
{
    int yOffset = 0;

    for (const auto module : modules) {
        sf::Vector2i pos = module->getPosition();
        if (xMouse >= pos.x && xMouse <= pos.x + 400 && yMouse >= pos.y && yMouse <= pos.y + 100) {
            module->setEnable(!module->isEnable());
            yOffset = (module->isEnable() ?  -(100 - module->getSize().y) : (100 - module->getSize().y) );
        }
    }
    if (yOffset != 0) {
        for (const auto module : modules) {
            sf::Vector2i pos = module->getPosition();
            if (pos.y > yMouse) {
                module->setPosition(pos.x, pos.y + yOffset);
            }
        }
    }
}

void Krell::events()
{
    sf::Event event;

    while (_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            _window->close();
        if (event.type == sf::Event::MouseWheelScrolled) {
            scrollSFML(event.mouseWheelScroll.delta);
        }
        if (event.type == sf::Event::MouseButtonReleased) {
            handleModuleClick(event.mouseButton.x, event.mouseButton.y, _modules);
        }
    }
}

void Krell::update()
{
    if (_clock.getElapsedTime().asMilliseconds() > _updateDelta) {
        _clock.restart();
        for (const auto module : _modules) {
            module->update();
        }
    }
}

void Krell::scrollSFML(int yValue, int mult)
{
    int i = 0;

    for (const auto module : _modules) {
        sf::Vector2i pos = module->getPosition();
        if (i == 0 && pos.y + (yValue * mult) >= 50 && yValue > 0)
            return;
        module->setPosition(pos.x, pos.y + (yValue * mult));
        i++;
    }
}
