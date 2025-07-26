/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD11-albane.merian
** File description:
** SafeDirectoryLister
*/

#include "SafeDirectoryLister.hpp"
#include <iostream>
#include <cstring>

SafeDirectoryLister::SafeDirectoryLister() : dir(nullptr), showHidden(false) {}

SafeDirectoryLister::SafeDirectoryLister(const std::string& path, bool hidden) : dir(nullptr), showHidden(hidden) {
    open(path, hidden);
}

SafeDirectoryLister::~SafeDirectoryLister() {
    if (dir) {
        closedir(dir);
    }
}

bool SafeDirectoryLister::open(const std::string& path, bool hidden) {
    if (dir) {
        closedir(dir);
        dir = nullptr;
    }
    showHidden = hidden;
    dir = opendir(path.c_str());
    if (!dir) {
        throw OpenFailureException(strerror(errno));
    }
    return true;
}

std::string SafeDirectoryLister::get() {
    if (!dir) {
        throw NoMoreFileException();
    }
    struct dirent* entry;
    while ((entry = readdir(dir)) != nullptr) {
        if (!showHidden && entry->d_name[0] == '.') {
            continue;
        }
        return std::string(entry->d_name);
    }
    throw NoMoreFileException();
}

