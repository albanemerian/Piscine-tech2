/*
** EPITECH PROJECT, 2025
** Test Date and Time
** File description:
** Test
*/

#include <ctime>
#include <string>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../src/Module/DateTime.hpp"

Test(DateTime, getDay)
{
    DateTime date;
    time_t now;
    struct tm info;
    const std::string days[] = {
        "Sunday", "Monday", "Tuesday", "Wednesday",
        "Thursday", "Friday", "Saturday"
    };

    time(&now);
    info = *localtime(&now);
    cr_assert_eq(date.getDay().c_str(), days[info.tm_wday]);
}

Test(DateTime, getMonth)
{
    DateTime date;
    time_t now;
    struct tm info;
    const std::string months[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    time(&now);
    info = *localtime(&now);
    cr_assert_eq(date.getMonth().c_str(), months[info.tm_mon]);
}

Test(DateTime, getYear)
{
    DateTime date;
    time_t now;
    struct tm info;

    time(&now);
    info = *localtime(&now);
    cr_assert_eq(date.getYear(), info.tm_year + 1900);
}

Test(DateTime, getHour)
{
    DateTime date;
    time_t now;
    struct tm info;

    time(&now);
    info = *localtime(&now);
    cr_assert_eq(date.getHour(), info.tm_hour);
}

Test(DateTime, getMinute)
{
    DateTime date;
    time_t now;
    struct tm info;

    time(&now);
    info = *localtime(&now);
    cr_assert_eq(date.getMinute(), info.tm_min);
}

Test(DateTime, getSecond)
{
    DateTime date;
    time_t now;
    struct tm info;

    time(&now);
    info = *localtime(&now);
    cr_assert_eq(date.getSecond(), info.tm_sec);
}