/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD10-albane.merian
** File description:
** ACitrus
*/

#ifndef ACITRUS_HPP_
#define ACITRUS_HPP_

#include "AFruit.hpp"

class ACitrus : public AFruit {
    public:
        ACitrus();
        ~ACitrus();

        virtual void peel();
        virtual bool isPeeled() const;

        virtual std::string getName() const;
        virtual unsigned int getVitamins() const;

        virtual void setVitamins(unsigned int vitamins);
        virtual void setPeeled(bool isPeeled);

        virtual IFruit *clone() const;
};

#endif /* !ACITRUS_HPP_ */
