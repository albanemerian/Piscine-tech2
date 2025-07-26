/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD11-albane.merian
** File description:
** main
*/

#include "DirectoryLister.hpp"
#include <iostream>
#include "IDirectoryLister.hpp"
#include "SafeDirectoryLister.hpp"
#include "UniquePointer.hpp"
#include "IObject.hpp"
#include "SharedPointer.hpp"
#include "List.hpp"

int main_test_open(void)
{
    DirectoryLister dl("./test/", true);

    for (std::string file = dl.get(); !file.empty(); file = dl.get())
        std::cout << file << std::endl;
    dl.open("invalid path", true);
    if (dl.open("./test/", false) == true)
        for (std::string file = dl.get(); !file.empty(); file = dl.get())
            std::cout << file << std::endl;

    return 0;
}

void myLs(const std::string& directory)
{
    try {
        SafeDirectoryLister dl(directory, false);

        std::cout << directory << ":" << std::endl;
        for (std::string file = dl.get(); true; file = dl.get())
            std::cout << file << std::endl;
    } catch (const IDirectoryLister::NoMoreFileException& e) {
        return;
    }
    throw std::runtime_error("should not happen");
}

int main_ls(void)
{
    try {
        myLs("./test/");
        myLs("./not_exist/");
        myLs("./test/");
    } catch (const IDirectoryLister::OpenFailureException& e) {
        std::cerr << "failure: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "unexpected error: " << e.what() << std::endl;
    }
    return 0;
}

class TestObject : public IObject {
private:
    std::string name;

public:
    TestObject(const std::string& name) : name(name) {
        std::cout << name << " is alive" << std::endl;
    }

    ~TestObject() override {
        std::cout << name << " is dead" << std::endl;
    }

    void touch() override {
        std::cout << name << " is touched" << std::endl;
    }
};


int main_three(void)
{
    UniquePointer ptr1;
    UniquePointer ptr2(new TestObject("Eccleston"));
    // UniquePointer ptr3(ptr2); // <- Does not compile!
    UniquePointer ptr4 = new TestObject("Hartnell");
    ptr1 = new TestObject("Tennant");
    ptr2 = new TestObject("Smith");
    ptr1->touch();
    ptr4->touch();
    (*ptr2).touch();
    {
        UniquePointer ptr4(new TestObject("Whittaker"));
    }
    ptr1.reset(new TestObject("Capaldi"));
    ptr1.swap(ptr2);
    //ptr1 = ptr2;// <- Does not compile!
    ptr2.reset();
    return 0;
}


void touch(IObject* object)
{
    if (object != nullptr)
        object->touch();
}

int main_four(void)
{
    try {
        List list;

        list.pushBack(new TestObject("Kermit"));
        list.pushBack(new TestObject("Miss Piggy"));
        list.pushFront(nullptr);
        list.front() = new TestObject("Fozzie");
        list.pushBack(nullptr);
        list.forEach(touch);
        list.clear();
        list.popBack();
        list.pushFront(new TestObject("Gonzo"));
    } catch (const List::InvalidOperationException& e) {
        std::cout << "Invalid operation on a list" << std::endl;
    }
    return 0;
}


int main_five(void)
{
    SharedPointer ptr1;
    SharedPointer ptr2(new TestObject("O'Neill"));
    SharedPointer ptr3(ptr2);
    SharedPointer ptr4 = new TestObject("Hartnell");

    ptr1 = ptr3;
    ptr2->touch();
    ptr4->touch();
    std::cout << ptr1.use_count() << std::endl;
    ptr1.reset(new TestObject("Carter"));
    std::cout << ptr1.use_count() << std::endl;
    ptr3.swap(ptr1);
    (*ptr3).touch();
    ptr1.reset();
    std::cout << ptr1.use_count() << std::endl;
    ptr2 = new TestObject("Jackson");
    return 0;
}

// void touch(IObject* object)
// {
//     if (object != nullptr)
//         object->touch();
// }

// int main_ficvz(void)
// {
//     try {
//         List list1;

//         list1.pushBack(new TestObject("Naruto"));
//         list1.pushBack(new TestObject("Sasuke"));
//         list1.pushBack(new TestObject("Sakura"));
//         list1.pushBack(nullptr);
//         list1.pushBack(new TestObject("Serge"));
//         for (List::Iterator it = list1.begin(); it != list1.end(); ++it)
//             if (*it != nullptr)
//                 (*it)->touch();
//         list1.erase(list1.erase(list1.begin()));
//         list1.insert(list1.begin(), new TestObject("Orochimaru"));
//         list1.insert(list1.end(), new TestObject("Tsunade"));
//         list1.forEach(touch);

//         List list2;

//         list2.pushFront(new TestObject("Jiraya"));
//         list1.erase(list2.begin());
//     } catch (const List::Iterator::OutOfRangeException& e) {
//         std::cout << "Iterator out of range" << std::endl;
//     } catch (const List::InvalidIteratorException& e) {
//         std::cout << "Invalid iterator" << std::endl;
//     }

//     return 0;
// }

// int main(void)
// {
//     main_test_open();
//     printf("\n-----\n");
//     main_ls();
//     printf("\n-----\n");
//     main_three();
//     printf("\n-----\n");
//     main_four();
//     printf("\n-----\n");
//     main_five();
//     printf("\n-----\n");
//     // main_ficvz();
//     return 0;
// }
