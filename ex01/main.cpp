#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <cstdlib>

int main(void)
{
    try
    {
        Bureaucrat b3("Chris", 2);
        b3.increment();
        std::cout << b3 << std::endl;
        b3.increment();
        std::cout << b3 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "--------------------------" << std::endl;

    try
    {
        Bureaucrat b2("Tyler", 149);
        b2.decrement();
        std::cout << b2 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "--------------------------" << std::endl;

    try
    {
        Bureaucrat b1("Hello", 300);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "--------------------------" << std::endl;

    try
    {
        Bureaucrat b4("Rock", 18);
        Form f1("Jack", 30, 30);
        b4.signForm(f1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "--------------------------" << std::endl;

    try
    {
        Bureaucrat b5("Robert", 150);
        Form f1("Rose", 1, 1);
        b5.signForm(f1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return EXIT_SUCCESS;
}
