/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD07pm-albane.merian
** File description:
** main
*/

#include "Parts.hpp"
#include "KoalaBot.hpp"
#include <iostream>

int main()
{
        KoalaBot kb("Bob-01");

    Arms arm1("Omega-Canon", true);
    Legs leg1("Booster", true);
    Head head1("Helmet", true);

    kb.setParts(arm1);
    kb.setParts(leg1);
    kb.setParts(head1);

    kb.informations();
    std::cout << "Status : " << (kb.status() ? "OK" : "KO") << std::endl;
    std::cout << "==========" << std::endl;

    Arms arm2("Arms-mk2", false);
    kb.swapParts(arm2);

    kb.informations();
    std::cout << "Status : " << (kb.status() ? "OK" : "KO") << std::endl;

    Legs leg2("L-mk4", true);
    Head head2("Visor", true);
    kb.swapParts(arm1);
    kb.swapParts(leg2);
    kb.swapParts(head2);

    std::cout << "==========" << std::endl;
    kb.informations();
    std::cout << "Status : " << (kb.status() ? "OK" : "KO") << std::endl;

    Arms arm3("A-01", true);
    Legs leg3("L-01", true);
    Head head3("H-01", true);
    kb.swapParts(arm3);
    kb.swapParts(leg3);
    kb.swapParts(head3);

    std::cout << "==========" << std::endl;
    kb.informations();
    std::cout << "Status : " << (kb.status() ? "OK" : "KO") << std::endl;
}
//     KoalaBot kb("Bob-01");

//     kb.informations();
//     std::cout << "Status : " << (kb.status() ? "OK" : "KO") << std::endl;
//     kb.informations();
//     std::cout << "Status : " << (kb.status() ? "OK" : "KO") << std::endl;
//     std::cout << "==========" << std::endl;

//     Arms a1("A-404", true);
//     Legs l1("L-042", false);
//     Head h1("Scope", false);
//     kb.setParts(a1);
//     kb.setParts(l1);
//     kb.setParts(h1);
//     kb.informations();
//     std::cout << "Status : " << (kb.status() ? "OK" : "KO") << std::endl;

//     Arms a2("Arms-mk2", false);
//     Legs l2("L-mk4", true);
//     Head h2("Visor", true);
//     kb.setParts(a2);
//     kb.setParts(l2);
//     kb.setParts(h2);
//     kb.informations();
//     std::cout << "Status : " << (kb.status() ? "OK" : "KO") << std::endl;
//     std::cout << "==========" << std::endl;

//     Arms a3("Omega-Canon", true);
//     Legs l3("Booster", true);
//     Head h3("Helmet", true);
//     kb.setParts(a3);
//     kb.setParts(l3);
//     kb.setParts(h3);
//     kb.informations();
//     std::cout << "Status : " << (kb.status() ? "OK" : "KO") << std::endl;
//     std::cout << "==========" << std::endl;

//     kb.setParts(a2);
//     kb.setParts(l3);
//     kb.setParts(h3);
//     kb.informations();
//     std::cout << "Status : " << (kb.status() ? "OK" : "KO") << std::endl;

//     kb.swapParts(a3);
//     kb.setParts(l2);
//     kb.setParts(h2);
//     kb.informations();
//     std::cout << "Status : " << (kb.status() ? "OK" : "KO") << std::endl;
//     std::cout << "==========" << std::endl;

//     kb.setParts(Arms("A-01", true));
//     kb.setParts(Legs("L-01", true));
//     kb.setParts(Head("H-01", true));
//     kb.informations();
//     std::cout << "Status : " << (kb.status() ? "OK" : "KO") << std::endl;
//     kb.informations();
//     std::cout << "Status : " << (kb.status() ? "OK" : "KO") << std::endl;

//     return 0;
// }
