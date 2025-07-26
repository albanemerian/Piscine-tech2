/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGRUSH3-albane.merian
** File description:
** RamModule
*/

#ifndef RAMMODULE_HPP_
#define RAMMODULE_HPP_

#include "AModule.hpp"
#include "HostModule.hpp"
#include "../GraphicalComponent/Box.hpp"
#include "../GraphicalComponent/Text.hpp"
#include "../GraphicalComponent/Graph.hpp"
#include <string>

class RamModule : virtual public AModule, virtual public HostModule {
    public:
        RamModule(int xpos = 0, int ypos = 0);
        ~RamModule() = default;

        void setModule();
        void update() override;
        void updates();
        unsigned long getTotalRam() const;
        unsigned long getUsedRam() const;
        unsigned long getFreeRam() const;
        void renderNCURSE(std::vector<WINDOW*> &boxe) override;
    protected:
        unsigned long _totalRam = 0;
        unsigned long _usedRam = 0;
        unsigned long _freeRam = 0;

        Box _background;
        Text _titleText;
        Text _ramUsageText;
        Graph _ramGraph;

    private:
};

#endif /* !RAMMODULE_HPP_ */
