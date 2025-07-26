/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD07pm-albane.merian
** File description:
** main
*/

#include "KreogCom.hpp"

int main() {
    KreogCom k1(42, 42, 1);
    
    k1.addCom(56, 25, 2);

    k1.removeCom();

    k1.removeCom();

    k1.addCom(56, 25, 2);
    k1.addCom(56, 25, 3);
    k1.addCom(56, 25, 4);

    k1.locateSquad();

    k1.ping();
    k1.getCom()->ping();

    k1.getCom()->removeCom();

    k1.locateSquad();

    k1.addCom(56, 25, 5);

    printf("\t==========\n");
    delete k1.getCom();
    printf("=====     =====\n");
    k1.removeCom();
    printf("==========\n");
    k1.removeCom();

    k1.locateSquad();

    const KreogCom *k2 = &k1;

    k2->locateSquad();

}

// int main()
// {
//     KreogCom k(42, 42, 101010);

//     if (k.getCom() == nullptr)
//         printf("head is empty bithc\n");
//     else
//         printf("head is not empty bithc\n");
//     k.addCom(56, 25, 65);
//     k.addCom(73, 34, 51);
//     if (k.getCom() == nullptr)
//         printf("head is empty bithc\n");
//     else
//         printf("head is not empty bithc\n");
//     k.locateSquad();
//     delete k.getCom();
//     k.removeCom();
//     k.removeCom();

//     return 0;
// }
