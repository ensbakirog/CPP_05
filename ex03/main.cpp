#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include <iostream>

int main()
{
    Intern intern;
    Bureaucrat boss("Boss", 1);

    AForm* form = intern.makeForm("robotomy request", "Bender");
    if (form) {
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }

    std::cout << std::endl;

    AForm* wrong = intern.makeForm("unknown form", "Nobody");
    if (wrong)
        delete wrong;

    return 0;
}