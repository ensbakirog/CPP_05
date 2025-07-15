#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

    #include "AForm.hpp"
    #include <string>
    
    class Bureaucrat;

    class RobotomyRequestForm : public AForm
    {
    private:
        const std::string target;
    public:
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);
        ~RobotomyRequestForm();

        void execute(Bureaucrat const & executor) const;
        const std::string& getTarget() const;
    };

#endif