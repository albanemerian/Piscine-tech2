/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD11-albane.merian
** File description:
** DirectoryLister
*/

#ifndef DIRECTORYLISTER_HPP_
#define DIRECTORYLISTER_HPP_

#include "IDirectoryLister.hpp"
#include <dirent.h>
#include <string>

class DirectoryLister : public IDirectoryLister {
public:
    DirectoryLister();
    DirectoryLister(const std::string& path, bool hidden);
    ~DirectoryLister();

    bool open(const std::string& path, bool hidden) override;
    std::string get() override;

    // Delete copy and move constructors and assignment operators
    DirectoryLister(const DirectoryLister&) = delete;
    DirectoryLister& operator=(const DirectoryLister&) = delete;
    DirectoryLister(DirectoryLister&&) = delete;
    DirectoryLister& operator=(DirectoryLister&&) = delete;

private:
    DIR* dir;
    bool showHidden;
};

#endif /* !DIRECTORYLISTER_HPP_ */
