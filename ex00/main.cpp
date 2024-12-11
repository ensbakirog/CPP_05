#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>

int main(void)
{
    try
    {
        Bureaucrat empty;
        empty.increment();
        std::cout << empty << std::endl;

        std::cout << std::endl;

        Bureaucrat test("Enes", 5);
        test.increment();
        std::cout << test << std::endl;

        std::cout << std::endl;

        Bureaucrat test2("Mehmet", 30);
        test2.decrement();
        std::cout << test2 << std::endl;

        std::cout << std::endl;

        Bureaucrat test3("Kemal", 150);
        test3.increment();
        std::cout << test3 << std::endl;

        std::cout << std::endl;

        Bureaucrat test4("Ceren", 1);
        test4.increment();
        std::cout << test4 << std::endl;
    }
    catch(const std::exception& exp)
    {
        std::cerr << exp.what() << '\n';
        return EXIT_FAILURE;
    }    
    return EXIT_SUCCESS;
}
