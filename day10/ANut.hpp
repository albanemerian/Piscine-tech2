/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD10-albane.merian
** File description:
** ANut
*/

#ifndef ANUT_HPP_
#define ANUT_HPP_

#include "AFruit.hpp"

class ANut : public AFruit {
    public:
        ANut();
        ~ANut();
        virtual void peel();
        virtual bool isPeeled() const;

        virtual std::string getName() const;
        virtual unsigned int getVitamins() const;

        virtual void setVitamins(unsigned int vitamins);
        virtual void setPeeled(bool isPeeled);

        virtual IFruit *clone() const;
};

#endif /* !ANUT_HPP_ */
