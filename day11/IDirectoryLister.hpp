/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD11-albane.merian
** File description:
** IDirectoryLister
*/

#ifndef IDIRECTORYLISTER_HPP
#define IDIRECTORYLISTER_HPP

#include <string>
#include <exception>

class IDirectoryLister {
public:
    IDirectoryLister() = default;
    virtual ~IDirectoryLister() = default;
    virtual bool open(const std::string& path, bool hidden) = 0;
    virtual std::string get() = 0;

    class OpenFailureException : public std::exception {
    public:
        OpenFailureException(const std::string& message) : msg(message) {}
        const char* what() const noexcept override {
            return msg.c_str();
        }
    private:
        std::string msg;
    };

    class NoMoreFileException : public std::exception {
    public:
        const char* what() const noexcept override {
            return "End of stream";
        }
    };
};

#endif // IDIRECTORYLISTER_HPP
