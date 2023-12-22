#include "../header/PresidentialPardonForm.hpp"
#include "../header/ShrubberyCreationForm.hpp"
#include "../header/RobotomyRequestForm.hpp"
#include "../header/Bureaucrat.hpp"
#include "../header/AForm.hpp"
#include "../header/Intern.hpp"

#include <time.h>
#include <cstdlib> 

// COLORS
# define BLUE "\e[1;34m"
# define RESET "\033[0m"

int	main(void)
{
	std::srand(time(NULL)); // Seed for random number generation

	// Constructors
	std::cout << BLUE << " ----- Constructors -----" << RESET << std::endl;
	Intern	intern;
	AForm	*robotomyForm;
	AForm	*ShrubberyForm;
	AForm	*presidentialForm;
	AForm	*unknownForm;

	std::cout << BLUE << "\n ----- Tesing Intern -----" << RESET << std::endl;

	// Testing Robotomy Request
	std::cout << "\n ----- Testing Robotomy Request -----" << std::endl;
	try 
	{
		robotomyForm = intern.makeForm("robotomy request", "Pete");
		std::cout << robotomyForm->getName() << " was just created successful!" << std::endl;
	}
	catch (Intern::InternException &exception)
	{
		std::cout << exception.what() << std::endl;
	}

	// Testing Presidential Pardon
	std::cout << "\n ----- Testing Presidential Pardon -----" << std::endl;
	try 
	{
		presidentialForm = intern.makeForm("presidential pardon", "Frank");
		std::cout << presidentialForm->getName() << " was just created successful!" << std::endl;
	}
	catch (Intern::InternException &exception)
	{
		std::cout << exception.what() << std::endl;
	}

	// Testing Shrubbery Creation
	std::cout << "\n ----- Testing Shrubbery Creation -----" << std::endl;
	try 
	{
		ShrubberyForm = intern.makeForm("shrubbery creation", "Bob");
		std::cout << ShrubberyForm->getName() << " was just created successful!" << std::endl;
	}
	catch (Intern::InternException &exception)
	{
		std::cout << exception.what() << std::endl;
	}

	// Testing UnknownForm: NOTE:
	// You only use an exeption if you know something will go wrong.
	std::cout << "\n ----- Testing UnknownForm -----" << std::endl;
	try
	{
		unknownForm = intern.makeForm("Unknown Form", "Wrong");
		std::cout << unknownForm->getName() << " was just created successful!" << std::endl;
	}
	catch (Intern::InternException &exception)
	{
		std::cout << exception.what() << std::endl;
	}

	std::cout << BLUE << "\n ----- Destructors -----" << RESET << std::endl;
	delete robotomyForm;
	delete ShrubberyForm;
	delete presidentialForm;
	delete unknownForm;
	return (0);	
}
