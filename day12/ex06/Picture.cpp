/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD12-albane.merian
** File description:
** Picture
*/

#include "Picture.hpp"
#include <fstream>

Picture::Picture() : data("")
{
}

Picture::Picture(const std::string &file)
{
    if (!getPictureFromFile(file)) {
        data = "ERROR";
    }
}

Picture::Picture(const Picture &other)
{
    this->data = other.data;
}

Picture &Picture::operator=(const Picture &other)
{
    if (this != &other)
        this->data = other.data;
    return *this;
}

Picture::~Picture()
{
}

bool Picture::getPictureFromFile(const std::string &file)
{
    std::ifstream imageFile(file);
    if (!imageFile.is_open()) {
        data = "ERROR";
        return false;
    }
    
    std::string content;
    std::string line;
    while (std::getline(imageFile, line)) {
        content += line + "\n";
    }
    
    data = content;
    imageFile.close();
    return true;
}
