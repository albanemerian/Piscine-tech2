/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGRUSH3-albane.merian
** File description:
** ProcModule
*/

#ifndef PROCMODULE_HPP_
#define PROCMODULE_HPP_

#include "AModule.hpp"
#include "HostModule.hpp"

class ProcModule : virtual public AModule, virtual public HostModule {
    public:
        ProcModule();
        ~ProcModule();

        void update();
        void setModule();

        unsigned int getNbProc() const;
        unsigned int getNbProcRunning() const;
        unsigned int getNbProcSleeping() const;
        unsigned int getNbProcZombie() const;
        void renderNCURSE(std::vector<WINDOW*> &boxe) override;
    protected:
        unsigned int _nbProc = 0;
        unsigned int _nbProcRunning = 0;
        unsigned int _nbProcSleeping = 0;
        unsigned int _nbProcZombie = 0;
    private:
};

#endif /* !PROCMODULE_HPP_ */
