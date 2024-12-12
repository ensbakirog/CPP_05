#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Empty"), isSigned(false), gradeForSign(150), gradeForExecute(150)
{
    std::cout << "Form Default Constructor Called." << std::endl;
}

Form::Form(const std::string _name, const int _gradeForSign, const int _gradeForExecute) : name(_name), isSigned(false), gradeForSign(_gradeForSign), gradeForExecute(_gradeForExecute)
{
    if (_gradeForSign > 150 || _gradeForExecute > 150)
        throw(Form::GradeTooLowException());
    else if (_gradeForSign < 1 || _gradeForExecute < 1)
        throw(Form::GradeTooHighException());

    std::cout << "Form Constructor Called." << std::endl;
}

Form::Form(const Form& other) : name(other.name), isSigned(other.isSigned), gradeForSign(other.gradeForSign), gradeForExecute(other.gradeForExecute)
{
    std::cout << "Form Copy Constructor Called." << std::endl;
}

Form& Form::operator=(const Form& other)
{
    if(this != &other)
        this->isSigned = other.isSigned;
    std::cout << "Form Copy Assigment Operator Called." << std::endl;
    return (*this);
}

Form::~Form()
{
    std::cout << "Form Destructor Called." << std::endl;
}

const std::string Form::getName(void) const
{
    return this->name;
}

bool Form::getIsSigned(void) const
{
    return this->isSigned;
}

int Form::getGradeForSign(void) const
{
    return this->gradeForSign;
}

int Form::getGradeForExecute(void) const
{
    return this->gradeForExecute;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade too Low!";
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    return (os << form.getName() << ", form isSigned = " << form.getIsSigned() << ", gradeForSign = " << form.getGradeForSign() << ", gradeForExecute = " << form.getGradeForExecute());
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (this->getGradeForSign() >= bureaucrat.getGrade())
        this->isSigned = true;
    else
        throw(Form::GradeTooLowException());
}