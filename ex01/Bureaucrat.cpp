#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(const std::string& name, const int grade) : name(name), grade(grade)
{
    if (this->grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (this->grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.getName()), grade(other.getGrade()) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
        this->grade = other.getGrade();
    
    return (*this);
}

const std::string& Bureaucrat::getName() const
{
    return (this->name);
}

int Bureaucrat::getGrade() const
{
    return (this->grade);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs)
{
    os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();

    return os;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Bureaucrat grade too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Bureaucrat grade too low!");
}

void Bureaucrat::increment()
{
    if (grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    else
        --this->grade; 
}

void Bureaucrat::decrement()
{
    if (grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    else
        ++this->grade;
}

void Bureaucrat::signForm(Form& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << this->getName() << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
    }
}