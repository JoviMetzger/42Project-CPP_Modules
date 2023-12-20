#include "../header/Form.hpp"
#include "../header/Bureaucrat.hpp"

// Default Constructor
Form::Form()
{
	std::cout << "Form: Default constructor called" << std::endl;
	_name = "Default Name";
	_signedStatus = false;
	_grade = 0;
	_gradeToSign = 0;
	_gradeToExecute = 0;
}

// Default Constructor
Form::Form (const std::string& name, int gradeToSign, int gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	else
	{
		_grade = gradeToSign;
		_name = name;
		_signedStatus = false;
		_gradeToSign = gradeToSign;
		_gradeToExecute = gradeToExecute;
	}
	std::cout << "Form: Constructor called" << std::endl;
}

// Destructor
Form::~Form()
{
	std::cout << "Form: Destructor called" << std::endl;
}

// Copy constructor
Form::Form(const Form& value)
{
	std::cout << "Form: Copy constructor called" << std::endl; 
	*this = value;
}

// Copy assignment operator
Form	&Form::operator=(const Form& value)
{
	std::cout << "Form: Copy assignment operator called" << std::endl;
	if (this != &value)	
	{
		// Perform a deep copy
		_name = value._name;
		_signedStatus = value._signedStatus;
		_grade = value._grade;
		_gradeToSign = value._gradeToSign;
		_gradeToExecute = value._gradeToExecute;
	}
	return *this;
}

// printing Operator
std::ostream& operator<<(std::ostream& out, const Form& formName) 
{
	out << formName.getName() << ", bureaucrat grade " << formName.getGrade() << std::endl;
	return out;
}

// Member Functions
// Retrives the name
std::string Form::getName() const
{
	return _name;
}

// Retrives the grade
int Form::getGrade() const
{
	return _grade;
}

// Retrives signuture status
bool Form::isSigned() const 
{
	return _signedStatus;
}

// Retrives the grade that needs to be signed
int Form::getGradeToSign() const 
{
	return _gradeToSign;
}

// Retrives the grade that needs to be executed
int Form::getGradeToExecute() const 
{
	return _gradeToExecute;
}

// Checks if the form can be signed
void Form::beSigned(int bureaucratGrade)
{
	if (bureaucratGrade <= _gradeToSign)
		_signedStatus = true;
	else
		throw GradeTooLowException();
}

// Exception classes
// GradeTooHigh message
const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");	
} 

// GradeTooLow message
const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}
