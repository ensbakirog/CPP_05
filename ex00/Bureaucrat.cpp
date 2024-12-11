#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(void) : name("Empty"), grade(150)
{
    std::cout << "Bureaucrat Default Constructor Called." << std::endl;
}

Bureaucrat::Bureaucrat(std::string _name, int _grade) : name(_name), grade(_grade)
{
    if (_grade > 150)
        throw(Bureaucrat::GradeTooLowException());
    else if(_grade < 1)
        throw(Bureaucrat::GradeTooHighException());

    std::cout << "Bureaucrat Constructor Called." << std::endl;
}
Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
    *this = other;
    std::cout << "Bureaucrat Copy Constructor Called." << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if(this != &other)
        this->grade = other.grade;
    std::cout << "Bureaucrat Copy Assigment Operator Called." << std::endl;
    return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Bureaucrat Destructor Called." << std::endl;
}

const std::string Bureaucrat::getName(void) const
{
    return this->name;
}

int Bureaucrat::getGrade(void) const
{
    return this->grade;
}

void Bureaucrat::increment(void)
{
    (this->grade == 1) ? throw(Bureaucrat::GradeTooHighException()) : --this->grade;
}

void Bureaucrat::decrement(void)
{
    (this->grade == 150) ? throw(Bureaucrat::GradeTooLowException()) : ++this->grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too Low!";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    return (os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".");
}