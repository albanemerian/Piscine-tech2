/*
** EPITECH PROJECT, 2025
** day8
** File description:
** Droid
*/

#ifndef DROID_HPP_
#define DROID_HPP_

#include <iostream>

class Droid {
    public:
        Droid(std::string id = "", size_t Energy = 50, const size_t attack = 25, const size_t toughness = 15, std::string *status = new std::string("Standing by"));
        ~Droid();
        Droid(const Droid &other);
        Droid& operator=(const Droid &other);
    
        std::string getId() const;
        size_t getEnergy() const;
        size_t getAttack() const;
        size_t getToughness() const;
        std::string *getStatus() const;

        void setId(std::string id);
        void setEnergy(size_t energy);
        void setStatus(std::string *status);

        Droid &operator<<(size_t &energy);
        bool operator==(const Droid &droid) const;
        bool operator!=(const Droid &droid) const;
    protected:
    private:
        std::string id;
        size_t Energy;
        const size_t attack;
        const size_t toughness;
        std::string *status;

};

std::ostream& operator<<(std::ostream& os, const Droid& d);

#endif /* !DROID_HPP_ */
