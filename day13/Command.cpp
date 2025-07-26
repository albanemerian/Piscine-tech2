/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD13-albane.merian
** File description:
** Command
*/

#include "Command.hpp"

void Command::registerCommand(const std::string& name, const std::function<void()>& function)
{
    if (_commands.find(name) != _commands.end()) {
        throw Command::Error("Already registered command");
    }
    _commands[name] = function;
}

void Command::executeCommand(const std::string& name)
{
    auto it = _commands.find(name);

    if (it == _commands.end()) {
        throw Command::Error("Unknow command");
    }

    it->second();
}
