/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD13-albane.merian
** File description:
** test_file_five
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/assert.h>
#include "../Command.hpp"
#include <stdexcept>

void redirect_all(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Command, register_and_execute_command, .init = redirect_all)
{
    Command cmd;
    bool executed = false;

    cmd.registerCommand("test", [&executed]() { executed = true; });
    cmd.executeCommand("test");

    cr_assert(executed, "Command was not executed");
}

Test(Command, register_existing_command, .init = redirect_all)
{
    Command cmd;

    cmd.registerCommand("test", []() {});
    cr_assert_throw(cmd.registerCommand("test", []() {}), Command::Error, "Already registered command");
}

Test(Command, register_existing_command_loop, .init = redirect_all)
{
    Command cmd;

    cmd.registerCommand("test", []() {});
    try {
        cmd.registerCommand("test", []() {});
    } catch (const Command::Error& e) {
        cr_assert_str_eq(e.what(), "Already registered command", "Error message does not match");
    }
}

Test(Command, execute_unknown_command, .init = redirect_all)
{
    Command cmd;

    cr_assert_throw(cmd.executeCommand("unknown"), Command::Error, "Unknown command");
}



Test(Command, RegisterCommand_Duplicate) {
    Command command;
    command.registerCommand("test", []() {});
    cr_assert_throw(command.registerCommand("test", []() {}), Command::Error, "Should throw when registering a duplicate command.");
}


Test(Command, ExecuteCommand_Unknown) {
    Command command;
    cr_assert_throw(command.executeCommand("unknown"), Command::Error, "Should throw when executing an unregistered command.");
}

Test(Command, ExecuteCommand_CallsFunction) {
    Command command;
    int counter = 0;
    command.registerCommand("increment", [&counter]() { counter++; });

    command.executeCommand("increment");
    cr_assert_eq(counter, 1, "Counter should increment to 1 after execution.");

    command.executeCommand("increment");
    cr_assert_eq(counter, 2, "Counter should increment to 2 after second execution.");
}
