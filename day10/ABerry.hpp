/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD10-albane.merian
** File description:
** ABerry
*/

#ifndef ABERRY_HPP_
#define ABERRY_HPP_


#include "AFruit.hpp"

class ABerry : public AFruit {
    public:
        ABerry();
        ~ABerry();
        virtual void setVitamins(unsigned int vitamins); // call the other getter and setter
        virtual unsigned int getVitamins() const;
        virtual std::string getName() const;

        virtual IFruit *clone() const;
};

#endif /* !ABERRY_HPP_ */
