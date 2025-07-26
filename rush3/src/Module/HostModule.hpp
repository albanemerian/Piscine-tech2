/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGRUSH3-albane.merian
** File description:
** HostModule
*/

#ifndef HOSTMODULE_HPP_
#define HOSTMODULE_HPP_

#include <iostream>
#include <string>
#include <ncurses.h>
#include "AModule.hpp"
#include "../GraphicalComponent/Text.hpp"
#include "../GraphicalComponent/Box.hpp"

class HostModule: virtual public AModule {
    public:
        HostModule(int xpos = 0, int ypos = 0, bool isOriginal = false);
        ~HostModule() = default;
        enum OsType {
            LINUX,
            MACOS,
            OTHER
        };
        void setUserName(std::string username);
        void setHostName(std::string hostname);
        void setModule();
        void setKernel(std::string kernel);
        void setOsType();

        void setLinuxModule();
        void setMacModule();

        std::string getUsername() const;
        std::string getHostname() const;
        std::string getKernel() const;

        void update();
        OsType getOsType();

        void renderNCURSE(std::vector<WINDOW*>& boxes) override;

    protected:
        std::string _hostname;
        std::string _username;
        std::string _os;
        std::string _kernel;
        OsType _osType;

        Text *_hostText;
        Text *_osText;
        Box *_background;
    private:
};

#endif /* !HOSTMODULE_HPP_ */
