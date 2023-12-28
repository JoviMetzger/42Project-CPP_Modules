#include "../header/RobotomyRequestForm.hpp"
#include "../header/AForm.hpp"
#include "../header/Bureaucrat.hpp"

#include <cstdlib>

// Default Constructor
RobotomyRequestForm::RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm: Default constructor called" << std::endl;
	_target = "Default Target";
}

// Constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("Robotomy Request Form", 72, 45)
{
	std::cout << "RobotomyRequestForm: Constructor called" << std::endl;
	_target = target;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm: Destructor called" << std::endl;
}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& value) : AForm(value)
{
	std::cout << "RobotomyRequestForm: Copy constructor called" << std::endl; 
	*this = value;
}

// Copy assignment operator
RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm& value)
{
	std::cout << "RobotomyRequestForm: Copy assignment operator called" << std::endl;
	if (this != &value)	
	{
		// Perform a deep copy
		_target = value._target;
	}
	return *this;
}

// Member Functions
// Execute the action associated with a robotomy request form
void RobotomyRequestForm::execute(Bureaucrat const &executer) const 
{
	AForm::execute(executer);
	if (!isSigned())
		throw AForm::GradeTooLowException();

	// Execute the action specific to this form
	std::cout << "Making drilling noises..." << std::endl;
	if (rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy failed for " << _target << "." << std::endl;
}
