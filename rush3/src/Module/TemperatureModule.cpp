/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGRUSH3-albane.merian
** File description:
** TemperatureModule
*/

#include "TemperatureModule.hpp"
#include <iostream>
#include <fstream>

TemperatureModule::TemperatureModule()
{
    getOsType();
    setModule();
}

TemperatureModule::~TemperatureModule()
{
}

float TemperatureModule::getCpuTemperature() const
{
    return _cpuTemperature;
}

float TemperatureModule::getGpuTemperature() const
{
    return _gpuTemperature;
}

float TemperatureModule::getBaterryTemperature() const
{
    return _baterryTemperature;
}


void TemperatureModule::setCputemp()
{
    std::ifstream tempFile("/sys/class/thermal/thermal_zone0/temp");
    if (tempFile) {
        int tempMilli;
        tempFile >> tempMilli;
        tempFile.close();
        _cpuTemperature = tempMilli / 1000.0;
    } else {
        std::cout << "Error: Could not open /sys/class/thermal/thermal_zone0/temp" << std::endl;
        exit(84);
    }
}

void TemperatureModule::setGputemp()
{
    std::ifstream tempFile("/sys/class/thermal/thermal_zone1/temp");
    if (tempFile) {
        int tempMilli;
        tempFile >> tempMilli;
        tempFile.close();
        _gpuTemperature = tempMilli / 1000.0;
    } else {
        std::cout << "Error: Could not open /sys/class/thermal/thermal_zone1/temp" << std::endl;
        exit(84);
    }
}

void TemperatureModule::setBatterytemp()
{
    std::ifstream tempFile("/sys/class/thermal/thermal_zone0/temp");

    if (tempFile) {
        int tempMilli;
        tempFile >> tempMilli;
        tempFile.close();
        _baterryTemperature = tempMilli / 1000.0;
    } else {
        std::cout << "Error: Could not open /sys/class/thermal/thermal_zone0/temp" << std::endl;
        exit(84);
    }
}

void TemperatureModule::setModule()
{
    setCputemp();
    setGputemp();
    setBatterytemp();
}


void TemperatureModule::update()
{
    setModule();
}
