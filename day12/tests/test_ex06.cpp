/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD12-albane.merian
** File description:
** test_ex06
*/

#include <criterion/criterion.h>
#include "../ex06/Woody.hpp"
#include "../ex06/Buzz.hpp"
#include "../ex06/ToyStory.hpp"
#include "../ex06/Picture.hpp"
#include "../ex06/Toy.hpp"

Test(Woody, test_speak) {
    Woody woody("Woody", "woody.txt");
    cr_assert_eq(woody.getName(), "Woody");
    cr_assert(woody.speak("There's a snake in my boot!"));
}

Test(Buzz, test_speak) {
    Buzz buzz("Buzz", "buzz.txt");
    cr_assert_eq(buzz.getName(), "Buzz");
    cr_assert(buzz.speak("To infinity and beyond!"));
    cr_assert(buzz.speak_es("Hola!"));
}

Test(ToyStory, test_tellMeAStory) {
    Woody woody("Woody", "woody.txt");
    Buzz buzz("Buzz", "buzz.txt");
    ToyStory::tellMeAStory("story.txt", woody, &Toy::speak, buzz, &Toy::speak_es);
}

Test(Picture, test_getPictureFromFile) {
    Picture picture("rex.txt");
    cr_assert_neq(picture.data, "1");
    Picture pictureError("nonexistent.txt");
    cr_assert_eq(pictureError.data, "ERROR");
}

Test(Toy, test_constructor) {
    Toy toy;
    cr_assert_eq(toy.getName(), "toy");
    cr_assert_eq(toy.getType(), Toy::BASIC_TOY);
    cr_assert_eq(toy.getAscii(), "");
}

Test(Toy, test_copy_constructor) {
    Toy toy1(Toy::WOODY, "Woody", "woody.txt");
    Toy toy2(toy1);
    cr_assert_eq(toy2.getName(), "Woody");
    cr_assert_eq(toy2.getType(), Toy::WOODY);
    cr_assert_eq(toy2.getAscii(), toy1.getAscii());
}

Test(Toy, test_assignment_operator) {
    Toy toy1(Toy::BUZZ, "Buzz", "buzz.txt");
    Toy toy2;
    toy2 = toy1;
    cr_assert_eq(toy2.getName(), "Buzz");
    cr_assert_eq(toy2.getType(), Toy::BUZZ);
    cr_assert_eq(toy2.getAscii(), toy1.getAscii());
}

Test(Toy, test_setName) {
    Toy toy;
    toy.setName("NewName");
    cr_assert_eq(toy.getName(), "NewName");
}

// Test(Toy, test_setAscii) {
//     Toy toy;
//     // cr_assert(toy.setAscii("woody.txt"));
//     // cr_assert_neq(toy.getAscii(), "ERROR");
//     cr_assert_not(toy.setAscii("nonexistent.txt"));
//     cr_assert_eq(toy.getAscii(), "ERROR");
// }

Test(Toy, test_speak) {
    Toy toy(Toy::BASIC_TOY, "Toy", "toy.txt");
    cr_assert(toy.speak("Hello!"));
}

Test(Toy, test_speak_es) {
    Toy toy(Toy::BASIC_TOY, "Toy", "toy.txt");
    cr_assert_not(toy.speak_es("Hola!"));
    cr_assert_eq(toy.getLastError().type, Toy::Error::SPEAK);
}

Test(Toy, test_operator_insertion) {
    Toy toy(Toy::BASIC_TOY, "Toy", "toy.txt");
    toy << "New ASCII Art";
    cr_assert_eq(toy.getAscii(), "New ASCII Art");
}

Test(Toy, test_getLastError) {
    Toy toy;    toy.setAscii("nonexistent.txt");    cr_assert_eq(toy.getLastError().type, Toy::Error::PICTURE);    cr_assert_eq(toy.getLastError().where(), "setAscii");    cr_assert_eq(toy.getLastError().what(), "bad new illustration");}Test(ToyStory, test_tellMeAStory_bad_story) {
    Woody woody("Woody", "woody.txt");
    Buzz buzz("Buzz", "buzz.txt");
    ToyStory::tellMeAStory("nonexistent_story.txt", woody, &Toy::speak, buzz, &Toy::speak_es);
}

Test(ToyStory, test_tellMeAStory_picture_error) {
    Woody woody("Woody", "woody.txt");
    Buzz buzz("Buzz", "buzz.txt");
    ToyStory::tellMeAStory("story_with_bad_picture.txt", woody, &Toy::speak, buzz, &Toy::speak_es);
}

Test(ToyStory, test_tellMeAStory_success) {
    Woody woody("Woody", "woody.txt");
    Buzz buzz("Buzz", "buzz.txt");
    ToyStory::tellMeAStory("story_success.txt", woody, &Toy::speak, buzz, &Toy::speak_es);
}

