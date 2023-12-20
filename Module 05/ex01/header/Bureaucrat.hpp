#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Form;

// Base class
class	Bureaucrat
{
	private:
		std::string	_name;
		int		_grade;
	public:
		Bureaucrat();					// Default constructor
		Bureaucrat(const Bureaucrat& value);		// Copy constructor
		Bureaucrat& operator=(const Bureaucrat& value);	// Copy assignment operator
		~Bureaucrat();					// Destructor

		Bureaucrat(std::string const &name, int grade);	// Constructor

		// Member Functions
		std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void signForm(Form &form);			// add signForm();

		// exception classes that inherits from the standard std::exception class
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();                 
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

};

// Printing operator<<
std::ostream&	operator<<(std::ostream &out, Bureaucrat const &bureaucratName);

#endif
