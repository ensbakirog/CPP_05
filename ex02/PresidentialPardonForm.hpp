#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

    class PresidentialPardonForm : public AForm
    {
    private:
        const std::string target;
    public:
        PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);
        ~PresidentialPardonForm();
    
        void execute(Bureaucrat const & executor) const;
        const std::string& getTarget() const;
    };

#endif