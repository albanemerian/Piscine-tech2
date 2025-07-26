/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGRUSH3-albane.merian
** File description:
** DiskModule
*/

#ifndef DISKMODULE_HPP_
#define DISKMODULE_HPP_

#include <iostream>
#include "AModule.hpp"
#include "HostModule.hpp"
#include "../GraphicalComponent/Box.hpp"
#include "../GraphicalComponent/Text.hpp"
#include "../GraphicalComponent/Graph.hpp"

class DiskModule : virtual public AModule, virtual public HostModule {
    public:
        DiskModule();
        DiskModule(int x, int y);
        ~DiskModule();

        void setModule();
        void update();
        void updates();
        void setDisk();
        void setSwap();

        unsigned long getSwapTotal() const;
        unsigned long getSwapFree() const;
        unsigned long getDiskTotal() const;
        unsigned long getDiskUsed() const;
        unsigned long getDiskFree() const;

        sf::Vector2i getSize() override {return {400, 200} ;};

        void renderNCURSE(std::vector<WINDOW*> &boxe) override;
    protected:
        unsigned long _totalDisk = 0;
        unsigned long _usedDisk = 0;
        unsigned long _freeDisk = 0;
        unsigned long _totalSwap = 0;
        unsigned long _freeSwap = 0;

        Box *_background;
        Text *_diskText;
        Text *_swapText;

    private:
};

#endif /* !DISKMODULE_HPP_ */
