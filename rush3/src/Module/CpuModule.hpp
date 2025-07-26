/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGRUSH3-albane.merian
** File description:
** CpuModule
*/

#ifndef CPUMODULE_HPP_
#define CPUMODULE_HPP_

#include <vector>
#include <iostream>
#include <list>
#include "HostModule.hpp"
#include "AModule.hpp"

#include "../GraphicalComponent/Text.hpp"
#include "../GraphicalComponent/Box.hpp"
#include "../GraphicalComponent/Graph.hpp"


struct LinkedCpuModule {
    std::vector<std::string> _modeleCPU;
    std::vector<std::string> _freqCPU;
    std::string _model;
    std::string _freq;
};

class CpuModule : virtual public AModule, virtual public HostModule {
    public:
        CpuModule(int x = 0, int y = 0);
        ~CpuModule() = default;
        unsigned int getNbCpu();

        void setModule();
        void LinuxModule();
        void update();
        typedef std::list<LinkedCpuModule> LinkedList;
        LinkedList& getList() { return _listCpu; }
        void renderNCURSE(std::vector<WINDOW*> &boxe) override;
    protected:

        std::vector<Text *>_coreTitle;
        std::vector<Text *>_coreFreq;
        std::vector<Graph *>_coreGraph;

        Text *_cpuName;
        Graph *_cpuGraph;
        Box *_cpuBackground;
        Box *_globalBackground;

        LinkedList _listCpu;
        std::string _modeleCPU;
        std::string _freqCPU;
        unsigned int _scroll_pos = 0;
    private:
        unsigned int _nbCpu;
};

#endif /* !CPUMODULE_HPP_ */
