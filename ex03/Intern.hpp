#ifndef INTERN_HPP
#define INTERN_HPP

    #include <string>
    class AForm;

    class Intern
    {
        public:
            Intern();
            Intern(const Intern& other);
            Intern& operator=(const Intern& rhs);
            ~Intern();
        
            AForm* makeForm(const std::string& formName, const std::string& target) const;
    };

#endif