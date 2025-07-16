#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

typedef AForm* (*FormCreator)(const std::string& target);

static AForm* createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

static AForm* createPresidential(const std::string& target) {
    return new PresidentialPardonForm(target);
}

Intern::Intern() {}

Intern::Intern(const Intern&) {}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern&) {
    return *this;
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    static const std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    static FormCreator creators[3] = {
        &createShrubbery,
        &createRobotomy,
        &createPresidential
    };
    for (int i = 0; i < 3; ++i) {
        if (formName == names[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return creators[i](target);
        }
    }
    std::cerr << "Intern: Error: Form name \"" << formName << "\" does not exist." << std::endl;
    return NULL;
}