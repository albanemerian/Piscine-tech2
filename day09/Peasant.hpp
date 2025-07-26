/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD09-albane.merian
** File description:
** Peasant
*/

#ifndef PEASANT_HPP_
#define PEASANT_HPP_

#include "ICharacter.hpp"
#include <iostream>

class Peasant : public ICharacter {
    public:
        Peasant(const std::string &name, int power);
        ~Peasant();
        
    
        int getPower() const;
        int getHp() const;
        const std::string &getName() const;

        void setPower(int power);
        void setHp(int hp);
        void setName(std::string name);


        int attack();
        int special();
        void rest();
        void damage(int damage);

        void drink(const PowerPotion& potion);
        void drink(const PoisonPotion& potion);
        void drink(const HealthPotion& potion);
        void drink(const IPotion& potion);
    protected:
        std::string name;
        int power;
    private:
        int hp;
        // int 

};

#endif /* !PEASANT_HPP_ */
