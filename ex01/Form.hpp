#pragma once

#include <string>
#include <exception>

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool isSigned;
        const int gradeForSign;
        const int gradeForExecute;
    public:
        Form(void);
        Form(const std::string _name, const int _gradeForSign, const int _gradeForExecute);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

        const std::string getName(void) const;
        bool getIsSigned(void) const;
        int getGradeForSign(void) const;
        int getGradeForExecute(void) const;

        void beSigned(const Bureaucrat& bureaucrat);

        class GradeTooHighException : public std::exception
        {
            const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Form& form);