#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

    #include <string>
    #include <ostream>

    #define
    class Bureaucrat
    {
        private:
            const std::string name;
            int grade;
        public:
            Bureaucrat(const std::string name, const int grade);
            Bureaucrat(const Bureaucrat& other);
            Bureaucrat& operator=(const Bureaucrat& rhs);
            ~Bureaucrat();

            const std::string getName() const;
            int getGrade() const;
            
            void increment();
            void decrement();
    };

    std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs);

#endif