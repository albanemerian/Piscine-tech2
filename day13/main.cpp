/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD13-albane.merian
** File description:
** main
*/

#include <iostream>
#include <string>
#include "Algorithm.hpp"
#include "Array.hpp"
#include "Stack.hpp"
#include "UniquePointer.hpp"
#include "Command.hpp"
#include "SharedPointer.hpp"

int main_zero(void)
{
    int a = 42;
    int b = 21;

    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
    std::cout << "clamp(0, a, b) = " << ::clamp(0, a, b) << std::endl;

    std::string c = "ghi";
    std::string d = "abc";

    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
    std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
    std::cout << "clamp(\"def\", c, d) = " << ::clamp(std::string("def"), c, d) << std::endl;
    std::cout << ::clamp(0, 42, 21) << std::endl;
    return 0;
}

int main_one()
{
    Array<int, 3>   array;
    
    std::cout << array << std::endl;
    try {
        array[0] = 21;
        array[1] = 42;
        array[2] = 84;
        array[3] = 84;
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << array << std::endl;
    array
        .convert<float>([](const int& v) { return static_cast<float>(v) / 10.f; })
        .forEach([](const float& v) { std::cout << v << std::endl; });
    return 0;
}

int main_two(void)
{
    Stack stack;
    stack.push(10.0);
    stack.push(5.0);
    stack.add();
    std::cout << stack.top() << std::endl;
    stack.push(3.0);
    stack.mul();
    std::cout << stack.top() << std::endl;
    stack.push(5.0);
    stack.div();
    std::cout << stack.top() << std::endl;
    return 0;
}

/*
Exercise 3
// */

class Example
{
private:
    int _id;

public:
    Example(int id) : _id(id) { std::cout << "#" << _id << " construction" << std::endl; }
    ~Example() { std::cout << "#" << _id << " destruction" << std::endl; }

    void method() const { std::cout << "#" << _id << " method" << std::endl; }
};

int main_three(void)
{
    UniquePointer<Example>  ptr1(new Example(1));
    UniquePointer<Example>  ptr2(new Example(2));

    ptr1.reset();
    ptr2 = new Example(3);
    ptr2.get()->method();
    ptr2->method();

    return 0;
}

// /*
// Exercise 4
// */

int main_four(void)
{
    Command command;
    Stack stack;

    try {
        command.registerCommand("push", [&stack]() { stack.push(4.2); });
        command.registerCommand("display", [&stack]() { std::cout << stack.top() << std::endl; });
        command.registerCommand("add", [&stack]() { stack.add(); });
        command.registerCommand("sub", [&stack]() { stack.sub(); });
        command.registerCommand("mul", [&stack]() { stack.mul(); });
        command.registerCommand("div", [&stack]() { stack.div(); });
        command.registerCommand("display", []() {});
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        command.executeCommand("push");
        command.executeCommand("push");
        command.executeCommand("push");
        command.executeCommand("add");
        command.executeCommand("div");
        command.executeCommand("display");
        command.executeCommand("nau");
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

// /*
// Exercise 5
// */

class Examples
{
private:
    int _id;

public:
    Examples(int id) : _id(id) { std::cout << "#" << _id << " construction" << std::endl; }
    ~Examples() { std::cout << "#" << _id << " destruction" << std::endl; }

    void method() const { std::cout << "#" << _id << " method" << std::endl; }
};

int main_five(void)
{
    SharedPointer<Examples> ptr1(new Examples(1));
    SharedPointer<Examples> ptr2(ptr1);
    SharedPointer<Examples> ptr3;

    ptr1.reset();
    ptr3 = ptr2;
    ptr2 = new Examples(2);
    ptr2.get()->method();
    ptr3->method();

    return 0;
}

int main()
{
    printf("\n----\n");
    main_zero();
    printf("\n----\n"); 
    main_one(); // Fixed typo here
    printf("\n----\n");
    main_two();
    printf("\n----\n");
    main_three();
    printf("\n----\n");
    main_four();
    printf("\n----\n");
    main_five();
    return 0;
}
