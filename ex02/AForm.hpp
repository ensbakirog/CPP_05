#ifndef AFORM_HPP
#define AFORM_HPP

	#include <string>
	#include <ostream>

	class Bureaucrat;

	class AForm
	{
		private:
			const std::string name;
			bool isSigned;
			const int signGrade;
			const int executeGrade;
		public:
			AForm(const std::string& name, const int signGrade, const int executeGrade);
            AForm(const AForm& other);
            AForm& operator=(const AForm& rhs);
            virtual ~AForm();

			const std::string& getName() const;
			int getSignGrade() const;
			int getExecuteGrade() const;
			bool getIsSigned() const;

			void beSigned(const Bureaucrat& bureaucrat);

			virtual void execute(Bureaucrat const & bureaucrat) const = 0;

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

			class FormNotSignedException : public std::exception
			{
				public:
					virtual const char* what() const throw();
			};
	};

	std::ostream& operator<<(std::ostream& os, const AForm& rhs);

#endif