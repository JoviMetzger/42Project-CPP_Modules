#include "../header/Intern.hpp"

// Default Constructor
Intern::Intern()
{
	std::cout << "Intern: Default constructor called" << std::endl;
}

// Destructor
Intern::~Intern()
{
	std::cout << "Intern: Destructor called" << std::endl;
}

// Copy constructor
Intern::Intern(const Intern& value)
{
	std::cout << "Intern: Copy constructor called" << std::endl; 
	*this = value;
}

// Copy assignment operator
Intern	&Intern::operator=(const Intern& value)
{
	std::cout << "Intern: Copy assignment operator called" << std::endl;
	if (this != &value)	
	{
		// Perform a deep copy
	}
	return *this;
}

// Member Function
// Creating new ShrubberyCreation form
AForm*	Intern::ShrubberyCreation(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

// Creating new RobotomyRequest form
AForm* Intern::RobotomyRequest(std::string target)
{
	return (new RobotomyRequestForm(target));
}

// Creating new PresidentialPardon form
AForm* Intern::PresidentialPardon(std::string target)
{
	return (new PresidentialPardonForm(target));
}

// Makes a form - finds the correct one and creats a new form
AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
	std::string FormName[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (Intern::*newForm[3]) ( std::string target) = {
		newForm[0] = &Intern::ShrubberyCreation,
                newForm[1] = &Intern::RobotomyRequest,
                newForm[2] = &Intern::PresidentialPardon
	};

    // Looks for the correct form
	for (int i = 0; i < 3; i++)
	{
		if (FormName[i] == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return ((this->*newForm[i])(target));
		}			
	}
	throw Intern::InternException();
}

// Exception classes
// InternException message
const char* Intern::InternException::what() const throw()
{
	return ("Intern does not recognize the form");	
} 
