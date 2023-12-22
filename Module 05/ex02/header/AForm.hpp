#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>

class	Bureaucrat;

class	AForm
{
	private:
		std::string	_name;
		bool		_signedStatus;
		int		_grade;
		int		_gradeToSign;
		int		_gradeToExecute;
	public:
		AForm();								// Default constructor
		AForm(const AForm& value);						// Copy constructor
		AForm& operator=(const AForm& value);					// Copy assignment operator
		virtual ~AForm();							// Destructor

		AForm(const std::string &name, int gradeToSign, int gradeToExecute);	// Constructor

		// Member Function
        	void		beSigned(int bureaucratGrade);
        	std::string	getName() const;
		int		getGrade() const;
       		bool		isSigned() const;
        	int		getGradeToSign() const;
        	int		getGradeToExecute() const;
        	virtual void	execute(Bureaucrat const &executor) const = 0;		// Pure virtual

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
std::ostream&	operator<<(std::ostream &out, AForm const &formName);

#endif
