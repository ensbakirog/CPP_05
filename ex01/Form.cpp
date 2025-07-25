#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string& name, const int signGrade, const int executeGrade) : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
    if (this->signGrade < 1 || this->executeGrade < 1)
        throw Form::GradeTooHighException();
    else if (this->signGrade > 150 || this->executeGrade > 150)
        throw Form::GradeTooLowException();
}

Form::~Form() {}

Form::Form(const Form& other) : name(other.getName()), isSigned(other.getIsSigned()), signGrade(other.getSignGrade()), executeGrade(other.getExecuteGrade()) {}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
        this->isSigned = other.getIsSigned();
    
    return (*this);
}

const std::string& Form::getName() const
{
    return (this->name);
}

int Form::getSignGrade() const
{
    return (this->signGrade);
}

bool Form::getIsSigned() const
{
    return (this->isSigned);
}

int Form::getExecuteGrade() const
{
    return (this->executeGrade);
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Form grade too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Form grade too low!");
}

std::ostream& operator<<(std::ostream& os, const Form& rhs)
{
    os << rhs.getName() << ", sign grade " << rhs.getSignGrade() << ", execute grade " << rhs.getExecuteGrade() << ", signed: " << rhs.getIsSigned();

    return (os);
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (!(bureaucrat.getGrade() <= this->signGrade))
        throw Form::GradeTooLowException();
    else
        this->isSigned = true;
}