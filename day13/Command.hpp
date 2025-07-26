/*
** EPITECH PROJECT, 2025
** *
** File description:
** Command
*/

#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>
#include <map>
#include <functional>
#include <stdexcept>

class Command {
    public:
        class Error : public std::exception {
        public:
            Error(const std::string& message) : _message(message) {}
            const char* what() const noexcept override {
                return _message.c_str();
            }
        private:
            std::string _message;
        };

        void registerCommand(const std::string& name, const std::function<void()>& function);
        void executeCommand(const std::string& name);

    private:
        std::map<std::string, std::function<void()>> _commands;
};

#endif // COMMAND_HPP
