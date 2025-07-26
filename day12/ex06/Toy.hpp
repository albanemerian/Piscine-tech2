/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD12-albane.merian
** File description:
** Toy
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include <iostream>
#include "Picture.hpp"

class Toy {
    public:
        enum ToyType {
            BASIC_TOY,
            ALIEN,
            BUZZ,
            WOODY
        };

        Toy();
        Toy(ToyType type, std::string name, std::string filename);
        Toy(const Toy &other);
        virtual ~Toy() = default;  // Change this line
        Toy &operator=(const Toy &other);

        std::string getName() const;
        ToyType getType() const;
        std::string getAscii() const;

        void setName(std::string name);
        bool setAscii(std::string filename);

        virtual bool speak(std::string statement);
        virtual bool speak_es(std::string statement);

        Toy &operator<<(std::string const &str);
        class Error {
            public:
                enum ErrorType {
                    UNKNOWN,
                    PICTURE,
                    SPEAK
                };
                std::string what() const;
                std::string where() const;
                ErrorType type = UNKNOWN;
        };
        Error getLastError();
    protected:
        Picture _picture;

    private:
        ToyType _type;
        std::string _name;
        std::string _statement;
        Error _lastError;
};

std::ostream &operator<<(std::ostream &os, const Toy &toy);
#endif /* !TOY_HPP_ */
// Now, create a Toy class. It must contain a ToyType enumeration with two fields: BASIC_TOY and ALIEN.
// The Toy class must contain a type, a name and a picture, as well as the following member func-
// tions :
// ✓ getType, a getter for the toy’s type (there is no setter, as the type will never change),
// ✓ getName,
// ✓ setName,
// ✓ setAscii that takes a filename as parameter and sets the toy’s picture to the file’s content.
// Returns true if it succeeds, false otherwise,
// ✓ getAscii that returns the toy’s picture as a string,
// ✓ a constructor taking no parameter, setting the toy’s type to BASIC_TOY, its name to “toy” and
// its picture to an empty string,
// ✓ a constructor taking three parameters: the ToyType, a string containing the toy’s name, and a
// string containing the picture’s filename. */
