#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class	Bureaucrat;

class	Form
{
	private:
		std::string	_name;
		bool		_signedStatus;
		int		_grade;
		int		_gradeToSign;
		int		_gradeToExecute;
	public:
		Form();									// Default constructor
		Form(const Form& value);						// Copy constructor
		Form& operator=(const Form& value);					// Copy assignment operator
		~Form();								// Destructor

		Form(const std::string& name, int gradeToSign, int gradeToExecute);	// Constructor

        // Member Function
        void		beSigned(int bureaucratGrade);
        std::string	getName() const;
	int		getGrade() const;
        bool		isSigned() const;
        int		getGradeToSign() const;
        int		getGradeToExecute() const;

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
std::ostream&	operator<<(std::ostream &out, Form const &formName);

#endif
