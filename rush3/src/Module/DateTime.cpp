/*
** EPITECH PROJECT, 2025
** DateTime
** File description:
** Module Date and Time
*/

#include <iostream>
#include <ncurses.h>
#include "DateTime.hpp"
#include <unistd.h>

DateTime::DateTime() : AModule(0, 0)
{
}

DateTime::DateTime(int x, int y)
    : AModule(x, y)
{
    this->_background = Box(pos.x, pos.y, 400, 100, "Date and Time");
    this->addComponent(&_background);

    this->_hoursDial = Dial(pos.x + 310, pos.y + 10, 80, 80, 0, 12, true, 0.09f);
    addComponent(&_hoursDial);

    this->_minutesDial = Dial(pos.x + 310, pos.y + 10, 80, 80, 0, 60, false, 0.07f);
    addComponent(&_minutesDial);

    this->_secondsDial = Dial(pos.x + 310, pos.y + 10, 80, 80, 0, 60, false, 0.04f, sf::Color(0, 0, 100), sf::Color(0, 0, 200));
    addComponent(&_secondsDial);

    this->_dateText = Text(pos.x + 15, pos.y + 10 + 10, 280, 100, "Date", 25);
    addComponent(&_dateText);
}

DateTime::~DateTime()
{
}

void DateTime::update()
{
    reloadTime();
    _secondsDial.update(&_info.tm_sec);
    _minutesDial.update(&_info.tm_min);
    _hoursDial.update(&_info.tm_hour);
    std::string date = getDay() + " " + std::to_string(_info.tm_mday) + " " + getMonth() + " " + std::to_string(getYear());
    _dateText.update(&date);
}

void DateTime::reloadTime()
{
    time(&_time);
    _info = *localtime(&_time);
}

int DateTime::getDayInt()
{
    reloadTime();
    return _info.tm_mday;
}

std::string DateTime::getDay()
{
    static const std::string days[] = {
        "Sunday",
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday"
    };

    reloadTime();
    return days[_info.tm_wday];
}

std::string DateTime::getMonth()
{
    static const std::string monthes[] = {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };

    reloadTime();
    return monthes[_info.tm_mon];
}

int DateTime::getYear()
{
    reloadTime();
    return _info.tm_year + 1900;
}

int DateTime::getHour()
{
    reloadTime();
    return _info.tm_hour;
}

int DateTime::getMinute()
{
    reloadTime();
    return _info.tm_min;
}

int DateTime::getSecond()
{
    reloadTime();
    return _info.tm_sec;
}

void DateTime::renderNCURSE(std::vector<WINDOW*>& boxe)
{
    reloadTime();

    int boxHeight = 5;
    int boxWidth = 60;
    int startY = 2;
    int startX = 0;

    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);

    WINDOW* boxWin = newwin(boxHeight, boxWidth, startY, startX);
    if (boxWin == nullptr) {
        printw("Failed to create window\n");
        return;
    }

    box(boxWin, 0, 0);
    wattron(boxWin, COLOR_PAIR(1));
    mvwprintw(boxWin, 0, 2, " DATE ");
    wattroff(boxWin, COLOR_PAIR(1));

    mvwprintw(boxWin, 1, 2, "%s, %02d, %s", getDay().c_str(), getDayInt(), getMonth().c_str());
    mvwprintw(boxWin, 2, 2, "%d: ", getYear());
    mvwprintw(boxWin, 3, 2, "%02d:%02d:%02d\n", getHour(), getMinute(), getSecond());

    boxe.push_back(boxWin);
    wrefresh(boxWin);

}
