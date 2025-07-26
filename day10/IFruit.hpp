/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD10-albane.merian
** File description:
** IFruit
*/

#ifndef IFRUIT_HPP_
#define IFRUIT_HPP_

#include <iostream>

class IFruit {
    public:
        virtual ~IFruit() = default;
        virtual unsigned int getVitamins() const = 0;
        virtual std::string getName() const = 0;
        virtual void peel() = 0;
        virtual bool isPeeled() const = 0;
        virtual IFruit *clone() const = 0;
    protected:
        bool _isPeeled;
        unsigned int _vitamins;
        std::string _name;
    private:
};

std::ostream &operator<<(std::ostream &os, const IFruit &fruit);

#endif /* !IFRUIT_HPP_ */
