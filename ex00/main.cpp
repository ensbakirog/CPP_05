#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>

int main()
{
    try
    {
        Bureaucrat Alex("Alex", 1);
        std::cout << Alex << std::endl;

        Bureaucrat Jack("Jack", 150);
        std::cout << Jack << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return EXIT_SUCCESS;
}