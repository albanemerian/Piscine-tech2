/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD08-albane.merian
** File description:
** Supply
*/

#ifndef SUPPLY_HPP_
#define SUPPLY_HPP_

#include "Droid.hpp"
#include <iostream>
#include <string>

class Supply {
public:
    enum Types { Iron = 1, Silicon = 2, Wreck = 3 };

    Supply(Types type, size_t amount);
    Supply(Types type, size_t amount, Droid** droids);

    ~Supply();

    Supply(const Supply&) = delete;
    Supply& operator=(const Supply&) = delete;

    size_t getAmount() const;
    Types getType() const;
    Droid** getWrecks() const;

    operator size_t() const;    
    bool operator==(Types type) const;      
    bool operator!=(Types type) const;       
    Supply& operator++();                  
    Supply& operator--();                  
    Droid*& operator*() const;                     
    Droid* operator->() const;            
    Supply& operator!();                      

    // Output operator

private:
    Types _type;             
    size_t _amount;          
    Droid** _wrecks;        
    size_t _currentIndex;
};

std::ostream& operator<<(std::ostream& os, const Supply& supply);
#endif /* SUPPLY_HPP_ */
