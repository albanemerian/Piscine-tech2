/*
** EPITECH PROJECT, 2025
** DateTime
** File description:
** Header
*/

#ifndef DATETIME_H_
    #define DATETIME_H_

#include <ctime>
#include <string>
#include "IModule.hpp"
#include "AModule.hpp"
#include "../GraphicalComponent/Dial.hpp"
#include "../GraphicalComponent/Text.hpp"
#include "../GraphicalComponent/Box.hpp"

class DateTime : virtual public AModule {
    public:
        DateTime(int x, int y);
        DateTime();
        ~DateTime();
        void reloadTime();
        int getDayInt();
        std::string getDay();
        std::string getMonth();
        int getYear();
        int getHour();
        int getMinute();
        int getSecond();
        void update() override;
        void renderNCURSE(std::vector<WINDOW*> &boxe) override;

    private:
        Dial _secondsDial;
        Dial _minutesDial;
        Dial _hoursDial;
        Text _dateText;
        Box _background;
        time_t _time;
        struct tm _info;
};

#endif /* !DATETIME_H_ */
