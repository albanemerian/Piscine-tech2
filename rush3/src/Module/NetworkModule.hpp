/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGRUSH3-albane.merian
** File description:
** NetworkModule
*/

#ifndef NETWORKMODULE_HPP_
#define NETWORKMODULE_HPP_

#include <iostream>
#include "AModule.hpp"
#include "HostModule.hpp"

class NetworkModule : virtual public AModule, virtual public HostModule {
    public:
        NetworkModule();
        ~NetworkModule();

        size_t getReceiveBytes() const;
        size_t getReceivePackets() const;
        size_t getTransmitBytes() const;
        size_t getTransmitPackets() const;

        void setModule();
        void update();
        void renderNCURSE(std::vector<WINDOW*> &boxe) override;
    protected:
        size_t _receiveBytes = 0;
        size_t _receivePackets = 0;
        size_t _transmitBytes = 0;
        size_t _transmitPackets = 0;
    private:
};

#endif /* !NETWORKMODULE_HPP_ */
