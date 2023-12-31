#include "../header/Bureaucrat.hpp"
#include "../header/AForm.hpp"

// Default Constructor
Bureaucrat::Bureaucrat()
{
	std::cout << "Bureaucrat: Default constructor called" << std::endl;
	_name = "Default Name";
	_grade = 0;
}

// Constructor
Bureaucrat::Bureaucrat(std::string const &name, int grade)
{

	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
	{
		_grade = grade;
		_name = name;
	}
	std::cout << "Bureaucrat: Constructor called" << std::endl;
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat: Destructor called" << std::endl;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& value)
{
	std::cout << "Bureaucrat: Copy constructor called" << std::endl; 
	*this = value;
}

// Copy assignment operator
Bureaucrat	&Bureaucrat::operator=(const Bureaucrat& value)
{
	std::cout << "Bureaucrat: Copy assignment operator called" << std::endl;
	if (this != &value)	
	{
		// Perform a deep copy
		_name = value._name;
		_grade = value._grade;
	}
	return *this;
}

// printing Operator
std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucratName) 
{
	out << bureaucratName.getName() << ", bureaucrat grade " << bureaucratName.getGrade() << std::endl;
	return out;
}

// Member Function
// Retrives the name
std::string Bureaucrat::getName() const
{
	return _name;
}

// Retrives the grade
int Bureaucrat::getGrade() const
{
	return _grade;
}

// Makes grade better (1 highest possible grade)
void Bureaucrat::incrementGrade()
{
	if (_grade > 1)
		_grade--;
	else
		throw GradeTooHighException();
}

// Makes grade less (150 lowest possible grade)
void Bureaucrat::decrementGrade()
{
	if (_grade < 150)
		_grade++;
	else
		throw GradeTooLowException();
}

// signes the form
void Bureaucrat::signForm(AForm& form)
{
	try 
	{
		form.beSigned(_grade);
		std::cout << getName() << " signed " << form.getName() << "!" << std::endl;
	} 
	catch (const std::exception& exception) 
	{
		std::cout << getName() << " couldn't sign " << form.getName() << " because " << exception.what() << std::endl;
	}
}

// Execution of a provided form
void Bureaucrat::executeForm(const AForm& form) 
{
	try 
	{
		form.execute(*this);
		std::cout << getName() << " executed " << form.getName() << std::endl;
	} 
	catch (const std::exception& exception) 
	{
		std::cout << getName() << " couldn't execute " << form.getName() << " because " << exception.what() << std::endl;
	}
}

// Exception classes
// GradeTooHigh message
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high, invalid Grade!");	
} 

// GradeTooLow message
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low, invalid Grade!");
}
