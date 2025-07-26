/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD07am-albane.merian
** File description:
** WarpSystem
*/

#ifndef WARPSYSTEM_HPP_
#define WARPSYSTEM_HPP_

namespace WarpSystem {
    class QuantumReactor {
    public:
        QuantumReactor();
        bool isStable();
        void setStability(bool stability);
    private:
        bool _stability;
    };
    class Core {
    public:
        Core(QuantumReactor *coreReactor);
        QuantumReactor *checkReactor();
    private:
        QuantumReactor *_coreReactor;
    };
}

#endif /* !WARPSYSTEM_HPP_ */
