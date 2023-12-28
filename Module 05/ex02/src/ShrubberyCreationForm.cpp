#include "../header/ShrubberyCreationForm.hpp"
#include "../header/AForm.hpp"
#include "../header/Bureaucrat.hpp"

# include <iostream>

// Default Constructor
ShrubberyCreationForm::ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm: Default constructor called" << std::endl;
	_target = "Default Target";
}

// Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery Creation Form", 145, 137)
{
	std::cout << "ShrubberyCreationForm: Constructor called" << std::endl;
	_target = target;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm: Destructor called" << std::endl;
}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& value) : AForm(value)
{
	std::cout << "ShrubberyCreationForm: Copy constructor called" << std::endl; 
	*this = value;
}

// Copy assignment operator
ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm& value)
{
	std::cout << "ShrubberyCreationForm: Copy assignment operator called" << std::endl;
	if (this != &value)	
	{
		// Perform a deep copy
		_target = value._target;
	}
	return *this;
}

// Member Functions
// Execute the action associated with a shrubbery creation form
void ShrubberyCreationForm::execute(Bureaucrat const &executer) const 
{
	AForm::execute(executer);
	if (!isSigned())
		throw AForm::GradeTooLowException();
	else
	{
		// Execute the action specific to this form
		// Create a file <_target>_shrubbery in the working directory
		 std::ofstream fileName;
		 std::string	output_filename = std::string(_target + "_shrubbery");
		 const char*	conv_outfilename = output_filename.c_str();		// Converts to const char*

	    fileName.open(conv_outfilename);
	    if (!fileName)
	    {
		    std::cout << "Coulnd't open the output file" << std::endl;
		    return ;
	    }
	    fileName << ASCII_TREE;
	    fileName.close();
	}
}
