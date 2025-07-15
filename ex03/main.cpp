#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    Bureaucrat high("High", 1);
    Bureaucrat low("Low", 150);

    ShrubberyCreationForm shrub("garden");
    RobotomyRequestForm robo("Bender");
    PresidentialPardonForm pardon("Arthur Dent");

    try
    {
        std::cout << shrub << std::endl;

        shrub.execute(high);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << shrub << std::endl;
    }

    std::cout << std::endl;

    try
    {
        std::cout << shrub << std::endl;

        low.signForm(shrub);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << shrub << std::endl;
    }

    std::cout << std::endl;

    try
    {
        std::cout << shrub << std::endl;

        high.signForm(shrub);

        std::cout << shrub << std::endl;

        shrub.execute(low);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        std::cout << robo << std::endl;

        high.signForm(robo);

        std::cout << robo << std::endl;

        robo.execute(high);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    std::cout << std::endl;

    try
    {
        std::cout << pardon << std::endl;

        high.signForm(pardon);

        std::cout << pardon << std::endl;

        pardon.execute(high);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}