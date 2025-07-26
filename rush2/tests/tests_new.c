/*
** EPITECH PROJECT, 2025
** rush02
** File description:
** tests_new
*/

#include "../new.h"
#include "../player.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(new, test_new_player, .init = redirect_all_std)
{
    Object *object = new(Player);

    fflush(stdout);
    cr_assert_stdout_eq_str("Player()\n");
    cr_assert_not_null(object);
    cr_assert_str_eq(str(object), "Player");
}

Test(new, test_new_player_with_args, .init = redirect_all_std)
{
    Object *object = new(Player, "toto");

    fflush(stdout);
    cr_assert_stdout_eq_str("Player()\n");
    cr_assert_not_null(object);
    cr_assert_str_eq(str(object), "Player");
}

Test(delete, delete_player, .init = redirect_all_std)
{
    Object *object = new(Player);

    delete(object);
    fflush(stdout);
    cr_assert_stdout_eq_str("Player()\n~Player()\n");
}

Test(new_null_class, test_new_null_class)
{
    Object *object = new(NULL);

    cr_assert_null(object);
}

Test(va_new_null_class, test_va_new_null_class)
{
    va_list ap;
    Object *object = va_new(NULL, &ap);

    cr_assert_null(object);
}

Test(delete_null, test_delete_null)
{
    delete(NULL);
}

Test(new_memory_error, test_new_memory_error)
{
    // Simulate memory allocation failure
    // This test requires a way to simulate malloc failure, which is not trivial
    // and might require a custom memory allocator or a mocking framework.
}

Test(va_new_memory_error, test_va_new_memory_error)
{
    // Simulate memory allocation failure
    // This test requires a way to simulate malloc failure, which is not trivial
    // and might require a custom memory allocator or a mocking framework.
}
