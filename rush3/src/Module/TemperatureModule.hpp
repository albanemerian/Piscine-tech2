/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGRUSH3-albane.merian
** File description:
** TemperatureModule
*/

#ifndef TEMPERATUREMODULE_HPP_
#define TEMPERATUREMODULE_HPP_

#include <iostream>
#include "HostModule.hpp"
#include "AModule.hpp"

class TemperatureModule : virtual public AModule, virtual public HostModule {
    public:
        TemperatureModule();
        ~TemperatureModule();

        void setCputemp();
        void setGputemp();
        void setBatterytemp();

        float getCpuTemperature() const;
        float getGpuTemperature() const;
        float getBaterryTemperature() const;
        void setModule();
        void update();
    protected:
        float _cpuTemperature = -1.0;
        float _gpuTemperature = -1.0;
        float _baterryTemperature = -1.0;
        
    private:
};

#endif /* !TEMPERATUREMODULE_HPP_ */
