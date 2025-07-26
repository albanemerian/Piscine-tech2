#include "KoalaBot.hpp"

// void testKoalaBot() {
//     KoalaBot kb("Bob-01");

//     // Initial state
//     kb.informations();
//     std::cout << "Status : " << (kb.status() ? "OK" : "KO") << std::endl;

//     // Change parts and test
//     Arms newArms("A-404", true);
//     Legs newLegs("L-042", false);
//     Head newHead("Scope", false);
//     kb.setParts(newArms);
//     kb.setParts(newLegs);
//     kb.setParts(newHead);
//     kb.informations();
//     std::cout << "Status : " << (kb.status() ? "OK" : "KO") << std::endl;
//     printf("==========\n");
//     // Swap parts and test
//     kb.swapParts(Arms("Arms-mk2", false));
//     kb.swapParts(Legs("L-mk4", true));
//     kb.swapParts(Head("Visor", true));
//     kb.informations();
//     std::cout << "Status : " << (kb.status() ? "OK" : "KO") << std::endl;
//     printf("==========\n");
//     // Another swap and test
//     kb.swapParts(Arms("Omega-Canon", true));
//     kb.swapParts(Legs("Booster", true));
//     kb.swapParts(Head("Helmet", true));
//     kb.informations();
//     std::cout << "Status : " << (kb.status() ? "OK" : "KO") << std::endl;

//     // Final swap and test
//     kb.swapParts(Arms("Arms-mk2", false));
//     kb.swapParts(Legs("Booster", true));
//     kb.swapParts(Head("Helmet", true));
//     kb.informations();
//     std::cout << "Status : " << (kb.status() ? "OK" : "KO") << std::endl;
//     printf("==========\n");
//     kb.swapParts(Arms("Arms-mk2", false));
//     kb.swapParts(Legs("L-mk4", true));
//     kb.swapParts(Head("Visor", true));
//     kb.informations();
//     std::cout << "Status : " << (kb.status() ? "OK" : "KO") << std::endl;
//     printf("==========\n");
//     // Reset to initial state
//     kb.setParts(Arms("A-01", true));
//     kb.setParts(Legs("L-01", true));
//     kb.setParts(Head("H-01", true));
//     kb.informations();
//     std::cout << "Status : " << (kb.status() ? "OK" : "KO") << std::endl;
// }

// int main() {
//     testKoalaBot();
//     return 0;
// }
