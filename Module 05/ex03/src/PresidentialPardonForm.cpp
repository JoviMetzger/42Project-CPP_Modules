#include "../header/PresidentialPardonForm.hpp"
#include "../header/AForm.hpp"
#include "../header/Bureaucrat.hpp"

// Default Constructor
PresidentialPardonForm::PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm: Default constructor called" << std::endl;
	_target = "Default Target";
}

// Constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("Presidential Pardon Form", 25, 5)
{
	std::cout << "PresidentialPardonForm: Constructor called" << std::endl;
	_target = target;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm: Destructor called" << std::endl;
}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& value)
{
	std::cout << "PresidentialPardonForm: Copy constructor called" << std::endl;
	*this = value;
}

// Copy assignment operator
PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm& value)
{
	std::cout << "PresidentialPardonForm: Copy assignment operator called" << std::endl;
	if (this != &value)	
	{
		// Perform a deep copy
		_target = value._target;
	}
	return *this;
}

// Member functions
// Execute the action associated with a presidential pardon form
void PresidentialPardonForm::execute(Bureaucrat const &executer) const
{
	AForm::execute(executer);
    if (!isSigned())
		throw AForm::GradeTooLowException();

        // Execute the action specific to this form
        std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
