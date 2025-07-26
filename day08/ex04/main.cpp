/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD08-albane.merian
** File description:
** main
*/

#include <iostream>
#include "Carrier.hpp"
#include "Droid.hpp"
#include "Supply.hpp"

void const_test()
{
    Droid **w = new Droid*[10];
    char c = '0';
    for (int i = 0; i < 3; ++i)
        w[i] = new Droid(std::string("wreck: ") + (char)(c + i));
    const Supply s(Supply::Wreck, 3, w);
    const Droid *d = *s;
    // Droid *la = *s;
}

int main()
{
    // const_test();

    Droid **w = new Droid*[10];
    char c = '0';

    for (int i = 0; i < 3; ++i)
        w[i] = new Droid(std::string("wreck: ") + (char)(c + i));
    Supply s1(Supply::Silicon, 42);
    Supply s2(Supply::Iron, 70);
    Supply s3(Supply::Wreck, 3, w);
    std::cout << s3 << std::endl;

    size_t s = s2;
    std::cout << s << std::endl;
    std::cout << *(*(--s3)) << std::endl;
    std::cout << *(++s3)->getStatus() << std::endl;
    ++s3;
    *s3 = 0;
    std::cout << *s3 << std::endl;
    std::cout << s2 << std::endl;
    // std::cout << s3 << std::endl; this segfaults don't know why
    std::cout << !s3 << std::endl;
    return 0;
}

// int main()
// {
//     Droid **w = new Droid*[10];
//     char c = '0';

//     for (int i = 0; i < 3; ++i)
//         w[i] = new Droid(std::string("wreck: ") + (char)(c + i));
//     Supply s1(Supply::Silicon, 42);
//     Supply s2(Supply::Iron, 70);
//     Supply s3(Supply::Wreck, 3, w);
//     std::cout << s3 << std::endl;

//     size_t s = s2;
//     std::cout << s << std::endl;
//     std::cout << *(*(--s3)) << std::endl;
//     std::cout << *(++s3)->getStatus() << std::endl;
//     ++s3;
//     *s3 = 0;
//     std::cout << *s3 << std::endl;
//     std::cout << s2 << std::endl;
//     std::cout << !s3 << std::endl;

//     return 0;
// }
