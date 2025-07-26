/*
** EPITECH PROJECT, 2025
** rush02
** File description:
** tests_player
*/

#include "../new.h"
#include "../player.h"
#include <criterion/criterion.h>

Test(str, test_str_player)
{
    Object *object = new(Player);

    cr_assert_not_null(object);
    cr_assert_str_eq(str(object), "Player");
}
