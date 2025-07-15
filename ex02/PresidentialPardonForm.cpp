#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), target(other.target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
    if (this != &rhs)
        AForm::operator=(rhs);

    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (this->getIsSigned() == false)
        throw AForm::FormNotSignedException();

    if (executor.getGrade() > this->getExecuteGrade())
        throw AForm::GradeTooHighException();

    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

const std::string& PresidentialPardonForm::getTarget() const
{
    return this->target;
}