/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD07am-albane.merian
** File description:
** WarpSystem
*/

#include "WarpSystem.hpp"


WarpSystem::QuantumReactor::QuantumReactor() : _stability(true) {}

bool WarpSystem::QuantumReactor::isStable() {
    return _stability;
}

void WarpSystem::QuantumReactor::setStability(bool stability) {
    _stability = stability;
}

WarpSystem::Core::Core(WarpSystem::QuantumReactor *coreReactor) : _coreReactor(coreReactor) {}

WarpSystem::QuantumReactor *WarpSystem::Core::checkReactor() {
    return _coreReactor;
}

