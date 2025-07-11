#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, const int grade) : name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    else
        this->grade = grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
        this->grade = other.grade;
    
    return (*this);
}

const std::string Bureaucrat::getName() const
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
    (grade <= 1) ? throw GradeTooHighException() : --grade; 
}

void Bureaucrat::decrement()
{
    (grade >= 150) ? throw GradeTooLowException() : ++grade; 
}