/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGRUSH3-albane.merian
** File description:
** NetworkModule
*/

#include "NetworkModule.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

NetworkModule::NetworkModule()
{
    getOsType();
    setModule();
}

NetworkModule::~NetworkModule()
{
}

size_t NetworkModule::getReceiveBytes() const
{
    return _receiveBytes;
}

size_t NetworkModule::getReceivePackets() const
{
    return _receivePackets;
}

size_t NetworkModule::getTransmitBytes() const
{
    return _transmitBytes;
}

size_t NetworkModule::getTransmitPackets() const
{
    return _transmitPackets;
}

void NetworkModule::setModule()
{
    std::ifstream net("/proc/net/dev");
    if (!net) {
        std::cout << "Error: Could not open /proc/net/dev" << std::endl;
        exit(0);
    }
    std::string line;
    std::string interface;

    _receiveBytes = 0;
    _receivePackets = 0;
    _transmitBytes = 0;
    _transmitPackets = 0;

    std::getline(net, line);
    std::getline(net, line);

    while (std::getline(net, line)) {
        std::istringstream iss(line);
        std::string interfaceName;
        std::getline(iss >> std::ws, interfaceName, ':');
        if (interfaceName == "lo") {
            continue;
        }
        size_t recv_bytes, recv_packets, recv_errs, recv_drop,
            recv_fifo, recv_frame, recv_compressed, recv_multicast;
        size_t trans_bytes, trans_packets, trans_errs, trans_drop,
            trans_fifo, trans_colls, trans_carrier, trans_compressed;
        iss >> recv_bytes >> recv_packets >> recv_errs >> recv_drop
            >> recv_fifo >> recv_frame >> recv_compressed >> recv_multicast
            >> trans_bytes >> trans_packets >> trans_errs >> trans_drop
            >> trans_fifo >> trans_colls >> trans_carrier >> trans_compressed;
        _receiveBytes += recv_bytes;
        _receivePackets += recv_packets;
        _transmitBytes += trans_bytes;
        _transmitPackets += trans_packets;
    }
}

void NetworkModule::update()
{
    setModule();
}

void NetworkModule::renderNCURSE(std::vector<WINDOW*> &boxe)
{
    update();
    int boxHeight = 6;
    int boxWidth = 60;
    float startY = 47;
    int startX = 0;

    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_WHITE, COLOR_BLACK);

    WINDOW* boxWin = newwin(boxHeight, boxWidth, startY, startX);
    if (boxWin == nullptr) {
        printw("Failed to create window\n");
        return;
    }
    box(boxWin, 0, 0);
    wattron(boxWin, COLOR_PAIR(1));
    mvwprintw(boxWin, 0, 2, " NETWORK ");
    wattroff(boxWin, COLOR_PAIR(1));
    mvwprintw(boxWin, 2, 2, "Received Packets: %zu - Received Bytes: %zu", _receivePackets / 1024, _receiveBytes / 1024);
    mvwprintw(boxWin, 3, 2, "Transmited Bytes: %zu - Transmited Packets %zu", _transmitBytes / 1024, _transmitPackets / 1024);
    boxe.push_back(boxWin);
    wrefresh(boxWin);
    return;
}
