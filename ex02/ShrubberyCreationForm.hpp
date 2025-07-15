#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

    #include <string>
    #include "AForm.hpp"

    class Bureaucrat;

    class ShrubberyCreationForm : public AForm
    {
        private:
            const std::string target;
        public:
            ShrubberyCreationForm(const std::string& target);
            ShrubberyCreationForm(const ShrubberyCreationForm& other);
            ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);
            ~ShrubberyCreationForm();

            void execute(Bureaucrat const & bureaucrat) const;

            const std::string& getTarget() const;
    };

#endif