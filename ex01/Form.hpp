#ifndef FORM_HPP
#define FORM_HPP

	#include <string>
	#include <ostream>

	class Bureaucrat;

	class Form
	{
		private:
			const std::string name;
			bool isSigned;
			const int signGrade;
			const int executeGrade;
		public:
			Form(const std::string& name, const int signGrade, const int executeGrade);
            Form(const Form& other);
            Form& operator=(const Form& rhs);
            ~Form();

			const std::string& getName() const;
			int getSignGrade() const;
			int getExecuteGrade() const;
			bool getIsSigned() const;

			void beSigned(const Bureaucrat& bureaucrat);

			class GradeTooHighException : public std::exception
			{
				public:
					virtual const char* what() const throw();
			};

			class GradeTooLowException : public std::exception
			{
				public:
					virtual const char* what() const throw();
			};
	};

	std::ostream& operator<<(std::ostream& os, const Form& rhs);

#endif