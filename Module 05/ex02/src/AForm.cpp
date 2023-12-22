#include "../header/AForm.hpp"
#include "../header/Bureaucrat.hpp"

// Default Constructor
AForm::AForm()
{
	std::cout << "AForm: Default constructor called" << std::endl;
	_name = "Default Name";
	_signedStatus = false;
	_grade = 0;
	_gradeToSign = 0;
	_gradeToExecute = 0;
}

// Constructor
AForm::AForm (const std::string& name, int gradeToSign, int gradeToExecute)
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
	std::cout << "AForm: Constructor called" << std::endl;
}

// Destructor
AForm::~AForm()
{
	std::cout << "AForm: Destructor called" << std::endl;
}

// Copy constructor
AForm::AForm(const AForm& value)
{
	std::cout << "AForm: Copy constructor called" << std::endl; 
	*this = value;
}

// Copy assignment operator
AForm	&AForm::operator=(const AForm& value)
{
	std::cout << "AForm: Copy assignment operator called" << std::endl;
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
std::ostream& operator<<(std::ostream& out, const AForm& formName) 
{
	out << formName.getName() << ", bureaucrat grade " << formName.getGrade() << std::endl;
	return out;
}

// Member Functions
// Retrives the name
std::string AForm::getName() const
{
	return _name;
}

// Retrives the grade
int AForm::getGrade() const
{
	return _grade;
}

// Retrives signuture status
bool AForm::isSigned() const 
{
	return _signedStatus;
}

// Retrives the grade that needs to be signed
int AForm::getGradeToSign() const 
{
	return _gradeToSign;
}

// Retrives the grade that needs to be executed
int AForm::getGradeToExecute() const 
{
	return _gradeToExecute;
}

// Checks if the form can be signed
void AForm::beSigned(int bureaucratGrade)
{
	if (bureaucratGrade <= _gradeToSign)
		_signedStatus = true;
	else
		throw GradeTooLowException();
}

// Checks whether the grade of the Bureaucrat is high enough to execute the form
void AForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
}

// Exception classes
// GradeTooHigh message
const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");	
} 

// GradeTooLow message
const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}
