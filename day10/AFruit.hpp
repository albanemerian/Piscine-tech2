/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD10-albane.merian
** File description:
** AFruit
*/

#ifndef AFRUIT_HPP_
#define AFRUIT_HPP_

#include "IFruit.hpp"

class AFruit : public IFruit {
    public:
        AFruit(); //empty constructor
        virtual ~AFruit();

        unsigned int getVitamins() const override;
        std::string getName() const override;
        void peel() override;
        bool isPeeled() const override;
        IFruit *clone() const override;
    protected:
    private:
};

#endif /* !AFRUIT_HPP_ */
