/*
** EPITECH PROJECT, 2025
** rush_3 [WSL: Ubuntu]
** File description:
** main
*/

#include <iostream>
#include <ncurses.h>
#include "Krell.hpp"
#include "Module/CpuModule.hpp"
#include "Module/HostModule.hpp"
#include "Module/DateTime.hpp"
#include "Module/IModule.hpp"
#include "Module/BatteryModule.hpp"
#include "Module/TemperatureModule.hpp"
#include "Module/DiskModule.hpp"
#include "Module/RamModule.hpp"
#include "Module/ProcModule.hpp"
#include "Module/NetworkModule.hpp"

void helper()
{
    std::cout << "USAGE" << std::endl;
    std::cout << "\t./MyGKrellm file [ -flags ]" << std::endl;
    std::cout << "DESCRIPTION :" << std::endl;
    std::cout << "\t Use the [ -t ] flag to use the text interface" << std::endl;
    std::cout << "\t Use the [ -g ] flag to use the graphical interface" << std::endl;
    std::cout << "\t Use the [ --skip ] followed by a module to desable them" << std::endl;
    std::cout << "Module : " << std::endl;
    std::cout << "\t cpu, ram, kernel, disk, datetime, battery" << std::endl;
    std::cout << "HELPER :" << std::endl;
    std::cout << "\t Use the [ -h ] or [ --help ] flag to display this help" << std::endl;
    std::cout << "TYPES :" << std::endl;
    std::cout << "\t press the Q key to exit the text interface" << std::endl;
    exit(0);
}

int main(int ac, char **av)
{
    if (ac == 1) {
        std::cout << "No arguments given" << std::endl;
        helper();
    }
    if (ac > 2 && std::string(av[2]) != "--skip") {
        std::cout << "Too many arguments given" << std::endl;
        exit(84);
    }
    if (ac > 2) {
        if (std::string(av[2]) != "--skip") {
            std::cout << "Invalid format: second argument must be --skip" << std::endl;
            exit(84);
        }
        std::vector<std::string> validModules = {"cpu", "ram", "kernel", "disk", "datetime", "battery"};
        for (int i = 3; i < ac; i++) {
            bool isValid = false;
            for (const auto& module : validModules) {
                if (std::string(av[i]) == module) {
                    isValid = true;
                    break;
                }
            }
            if (!isValid) {
                std::cout << "Invalid module name: " << av[i] << std::endl;
                exit(84);
            }
        }
    }
    if (ac == 2 && (std::string(av[1]) == "-h" || std::string(av[1]) == "--help")) {
        helper();
        return 0;
    }

    if (ac == 2 && std::string(av[1]) == "-t") {
        Krell krell;
        krell.setNcurse(true);
        krell.run();
    }
    if (std::string(av[1]) == "-g") {
        std::string strings = "";
        if (ac > 2) {
            for (int i = 2; i < ac; i++) {
                strings += std::string(av[i]);
                if (i < ac - 1)
                    strings += " ";
            }
        }
        Krell krell(520, 1080, strings);
        krell.setNcurse(false);
        krell.run();
    }
    return 0;
}
