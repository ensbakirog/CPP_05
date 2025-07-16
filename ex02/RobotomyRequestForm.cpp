#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
    if (this != &rhs)
        AForm::operator=(rhs);

    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (this->getIsSigned() == false)
        throw AForm::FormNotSignedException();

    if (executor.getGrade() > this->getExecuteGrade())
        throw AForm::GradeTooHighException();

    std::cout << "* drilling noises *" << std::endl;

    static bool seeded = false;
    if (!seeded)
    {
        std::srand(static_cast<unsigned int>(std::time(0)));
        seeded = true;
    }

    if (std::rand() % 2)
        std::cout << this->target << " has been robotomized successfully!" << std::endl;
    else
        std::cerr << "Robotomy failed on " << this->target << "!" << std::endl;
}

const std::string& RobotomyRequestForm::getTarget() const
{
    return this->target;
}