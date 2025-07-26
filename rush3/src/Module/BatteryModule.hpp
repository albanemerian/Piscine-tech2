/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGRUSH3-albane.merian
** File description:
** BatteryModule
*/

#ifndef BATTERYMODULE_HPP_
    #define BATTERYMODULE_HPP_

#include "AModule.hpp"
#include "HostModule.hpp"
#include "../GraphicalComponent/Bar.hpp"

class BatteryModule : virtual public AModule, virtual public HostModule {
    public:
        BatteryModule(int posx = 0, int posy = 0);
        ~BatteryModule();

        void setModule();
        void update();
        unsigned int getBattery() const;
        void renderNCURSE(std::vector<WINDOW*> &boxe) override;
    protected:
        unsigned int _battery;
        std::string _status;
    private:
        Box *_background;
        Bar *_bar;
        Bar *_power;
        Text *_name;
        Text *_level;
};

#endif /* !BATTERYMODULE_HPP_ */
