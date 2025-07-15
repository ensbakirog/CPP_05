#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
    if (this != &rhs)
        AForm::operator=(rhs);

    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (this->getIsSigned() == false)
        throw AForm::FormNotSignedException();

    if (executor.getGrade() > this->getExecuteGrade())
        throw AForm::GradeTooHighException();

    std::string filename = this->target + "_shrubbery";
    std::ofstream file(filename.c_str());
    
    if (!file.is_open())
    {
        std::cerr << "Error: Could not create file " << filename << std::endl;
        return;
    }

    file << SHRUBBERY_TREE;
    
    file.close();
}

const std::string& ShrubberyCreationForm::getTarget() const
{
    return this->target;
}