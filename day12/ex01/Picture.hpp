/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD12-albane.merian
** File description:
** Picture
*/

#ifndef PICTURE_HPP_
#define PICTURE_HPP_

#include <iostream>
#include <fstream>
#include <string>

class Picture {
    public:
        Picture();
        Picture(const std::string &file);
        Picture(const Picture &other);
        virtual ~Picture();
        Picture &operator=(const Picture &other);

        bool getPictureFromFile(const std::string &file);
        std::string data;

    private:
};

#endif /* !PICTURE_HPP_ */

// Start by creating a Picture class to represent our toys’ illustrations. It must contain, publicly :
// 1. std :: string data ;
// Our toy’s ASCII art.
// 2. bool getPictureFromFile ( const std :: string & file ) ;
// Sets data’s value to the content of file. If an error occurs, data must be set to “ERROR” and the
// function must return false. Otherwise, it returns true.
// 3. Picture ( const std :: string & file ) ;
// Creates a Picture object by loading the content of file. If an error occurs, data must be set to “ER-
// ROR”. Creating a Picture without a filename as parameter sets data to an empty string.
