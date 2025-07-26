/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGRUSH3-albane.merian
** File description:
** HostModule
*/

#include "HostModule.hpp"
#include <sys/utsname.h>
#include <unistd.h>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <string.h>
#include <ncurses.h>

HostModule::HostModule(int xpos, int ypos, bool isOriginal)
    : AModule(xpos, ypos)
{
    getOsType();
    setModule();

    if (isOriginal) {
        _background = new Box(pos.x, pos.y, 400, 100, "Host");
        addComponent(_background);

        _hostText = new Text(pos.x + 40, pos.y + 10, 280, 100, _username + "@" + _hostname, 25);
        addComponent(_hostText);

        _osText = new Text(pos.x + 40, pos.y + 50, 280, 100, _os + ": " + _kernel);
        addComponent(_osText);

    }
}

HostModule::OsType HostModule::getOsType()
{
    struct utsname buffer;

    if (uname(&buffer) != 0) {
        return HostModule::OTHER;
    }

    std::string sysName(buffer.sysname);

    if (sysName.find("Linux") != std::string::npos) {
        _osType = HostModule::LINUX;
        return HostModule::LINUX;
    }
    if (sysName.find("Darwin") != std::string::npos) {
        _osType = HostModule::MACOS;
        return HostModule::MACOS;
    }

    _osType = HostModule::OTHER;
    return HostModule::OTHER;
}

std::string HostModule::getUsername() const
{
    return _username;
}

std::string HostModule::getHostname() const
{
    return _hostname;
}

std::string HostModule::getKernel() const
{
    return _kernel;
}

void HostModule::setUserName(std::string username)
{
    _username = username;
}

void HostModule::setHostName(std::string hostname)
{
    _hostname = hostname;
}

void HostModule::setKernel(std::string kernel)
{
    _kernel = kernel;
}

void HostModule::setOsType()
{
    if (_osType == 0)
        _os = "Linux";
    if (_osType == 1)
        _os = "MacOs";
    if (_osType == 2)
        _os = "Unknown";
}

void HostModule::setLinuxModule()
{
    const char *env_var[2] = {"USER", "HOSTNAME"};
    char *env_val[2];
    for (int i = 0; i < 2; ++i) {
        env_val[i] = getenv(env_var[i]);
        if (env_val[i] == NULL)
            env_val[i] = (char *)"Unknown";
    } 
    setUserName(env_val[0]);
    setHostName(env_val[1]);
    setOsType();
    struct utsname ker;
    if (uname(&ker) == 0) {
        setKernel(ker.release);
    } else {
        setKernel("Unknown");
    }

}

void HostModule::setMacModule()
{
    const char* env_var = "USER";
    char* env_val = getenv(env_var);
    if (!env_val) env_val = (char*)"Unknown";
    setUserName(env_val);

    char hostname[256];
    if (gethostname(hostname, sizeof(hostname)) == 0) {
        setHostName(hostname);
    } else {
        setHostName("Unknown");
    }
    struct utsname ker;
    if (uname(&ker) == 0) {
        setKernel(ker.release);
    } else {
        setKernel("Unknown");
    }
    setOsType();
}

void HostModule::setModule()
{
    if (_osType == 0) {
        setLinuxModule();
    }
    if (_osType == 1)
        setMacModule();
    if (_osType == 2) {
        std::cout << "Error Unkown distribution" << std::endl;
        exit(84);
    }
}

void HostModule::update()
{
    getOsType();
    setModule();
}

void HostModule::renderNCURSE(std::vector<WINDOW*>& boxes)
{
    update();

    int boxHeight = 6;
    int boxWidth = 60;
    int startY = 1 * 6 + 1;
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
    mvwprintw(boxWin, 0, 2, " OS ");
    wattroff(boxWin, COLOR_PAIR(1));


    mvwprintw(boxWin, 1, 2, "OS Type  : %s", _os.c_str());
    mvwprintw(boxWin, 2, 2, "Username : %s", _username.c_str());
    mvwprintw(boxWin, 3, 2, "Hostname : %s", _hostname.c_str());
    mvwprintw(boxWin, 4, 2, "Kernel   : %s", _kernel.c_str());


    boxes.push_back(boxWin);
    wrefresh(boxWin);
    wrefresh(boxWin);
}
