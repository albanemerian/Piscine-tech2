/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD06-albane.merian
** File description:
** main
*/


// #include "Student.hpp"
// #include "Seminar.hpp"
// #include "Dean.hpp"
// #include "Assistant.hpp"
// #include <iostream>
// #include <cstdlib>

// int main(void)
// {
//     std::srand(42);

//     Dean dean_thaynam("Thay-Nam");
//     Dean assistant_to_the_dean_devoille("Devoille");
//     Assistant ass_42(42);
//     Assistant ass_24(24);
//     Assistant ass_2077(2077);
//     Student stud_jennifer("Jennifer");
//     Student stud_brian("Brian");
//     Student stud_kevin("Kevin");
//     Student stud_dwayne("Dwayne");
//     Student stud_priscilla("Priscilla");
//     Student stud_stewie("Stewie");

//     {
//         Seminar seminar;

//         seminar.run();
//         seminar.addDean(&dean_thaynam);
//         seminar.addDean(&assistant_to_the_dean_devoille);
//         seminar.addAssistant(&ass_42);
//         seminar.addAssistant(&ass_24);
//         seminar.addAssistant(&ass_42);
//         seminar.addAssistant(&ass_2077);
//         seminar.addStudent(&stud_jennifer);
//         seminar.addStudent(&stud_brian);
//         seminar.addStudent(&stud_kevin);
//         seminar.addStudent(&stud_dwayne);
//         seminar.addStudent(&stud_brian);
//         seminar.addStudent(&stud_priscilla);
//         seminar.addStudent(&stud_stewie);
//         seminar.run();
//     }
//     return 0;
// }

#include "Student.hpp"
#include "Assistant.hpp"
#include "Dean.hpp"
#include <iostream>

int main()
{
    Student student("OupyGoupy");
    Assistant assistant(34);
    Dean dean("Smith");

    assistant.timeCheck(); // Start working

    student.learn("John");
    student.drink("Red Bull");
    student.learn("I'm learning C++!");
    student.drink("Monster");
    student.learn("I'm learning C++!");
    student.drink("Water");
    student.drink("caca");
    student.learn("I'm learning C++!");
    student.learn("I'm learning C++!");
    student.learn("I'm learning C++!");
    student.drink("Monster");
    student.learn("I'm learning C++!");

    assistant.giveDrink(&student, "Water");

    // Test readDrink function
    std::string drink = assistant.readDrink("OupyGoupy");
    assistant.helpStudent(&student);

    // Test teachStudent function
    dean.teachStudent(&student, "Advanced C++");

    assistant.timeCheck(); // Stop working

    std::cout << "\nend\n\n" << std::endl;
    return 0;
}
