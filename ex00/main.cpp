#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try
    {
        std::cout << "Test 1: Create with grade 1 and increment (should throw)" << std::endl;
        Bureaucrat high("High", 1);
        std::cout << high << std::endl;
        high.increment();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;

    try
    {
        std::cout << "Test 2: Create with grade 150 and decrement (should throw)" << std::endl;
        Bureaucrat low("Low", 150);
        std::cout << low << std::endl;
        low.decrement();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;

    try
    {
        std::cout << "Test 3: Create with grade 0 (should throw)" << std::endl;
        Bureaucrat zero("Zero", 0);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        std::cout << "Test 3: Create with grade 151 (should throw)" << std::endl;
        Bureaucrat over("Over", 151);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;

    try
    {
        std::cout << "Test 4: Normal increment and decrement" << std::endl;
        Bureaucrat mid("Mid", 75);
        std::cout << mid << std::endl;
        mid.increment();
        std::cout << mid << std::endl;
        mid.decrement();
        std::cout << mid << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;

    try
    {
        std::cout << "Test 5: Copy constructor and assignment operator" << std::endl;
        Bureaucrat original("Original", 42);
        Bureaucrat copy(original);
        std::cout << original << std::endl;
        std::cout << copy << std::endl;

        Bureaucrat another("Another", 100);
        std::cout << "Another: " << another << std::endl;
        copy = another;
        std::cout << copy << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;

    try
    {
        std::cout << "Test 6: Multiple decrements to cross the lower boundary" << std::endl;
        Bureaucrat b("Border", 149);
        std::cout << b << std::endl;
        b.decrement();
        std::cout << b << std::endl;
        b.decrement();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}