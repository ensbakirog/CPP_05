#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, const int signGrade, const int executeGrade) : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
    if (this->signGrade < 1 || this->executeGrade < 1)
        throw AForm::GradeTooHighException();
    else if (this->signGrade > 150 || this->executeGrade > 150)
        throw AForm::GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(const AForm& other) : name(other.getName()), isSigned(other.getIsSigned()), signGrade(other.getSignGrade()), executeGrade(other.getExecuteGrade()) {}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
        this->isSigned = other.getIsSigned();
    
    return (*this);
}

const std::string& AForm::getName() const
{
    return (this->name);
}

int AForm::getSignGrade() const
{
    return (this->signGrade);
}

bool AForm::getIsSigned() const
{
    return (this->isSigned);
}

int AForm::getExecuteGrade() const
{
    return (this->executeGrade);
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("AForm grade too high!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("AForm grade too low!");
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return ("AForm is not signed!");
}

std::ostream& operator<<(std::ostream& os, const AForm& rhs)
{
    os << rhs.getName() << ", sign grade " << rhs.getSignGrade() << ", execute grade " << rhs.getExecuteGrade() << ", signed: " << rhs.getIsSigned();

    return (os);
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (!(bureaucrat.getGrade() <= this->signGrade))
        throw AForm::GradeTooLowException();
    else
        this->isSigned = true;
}