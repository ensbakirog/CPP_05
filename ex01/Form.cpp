#include "Form.hpp"

Form::Form(const std::string& name, const int& signGrade, const int& executeGrade) : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
    if (this->signGrade < 1 || this->executeGrade < 1)
        throw Form::GradeTooHighException();
    else if (this->signGrade > 150 || this->executeGrade > 150)
        throw Form::GradeTooLowException();
}

Form::~Form() {}

Form::Form(const Form& other) : name(other.getName()), isSigned(other.getisSigned()), signGrade(other.getsignGrade()), executeGrade(other.getexecuteGrade()) {}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
        this->isSigned = other.getisSigned();
    
    return (*this);
}

const std::string Form::getName() const
{
    return (this->name);
}

const int Form::getsignGrade() const
{
    return (this->signGrade);
}

const int Form::getsignGrade() const
{
    return (this->isSigned);
}

const int Form::getexecuteGrade() const
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
    os << rhs.getName() << ", sign grade " << rhs.getsignGrade() << ", execute grade " << rhs.getexecuteGrade() << ", signed: " << rhs.getisSigned();

    return (os);
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (!(bureaucrat.getGrade() <= this->signGrade))
        throw Form::GradeTooLowException();
    else
        this->isSigned = true;
}