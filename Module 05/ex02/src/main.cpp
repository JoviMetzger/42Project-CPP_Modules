#include "../header/PresidentialPardonForm.hpp"
#include "../header/ShrubberyCreationForm.hpp"
#include "../header/RobotomyRequestForm.hpp"
#include "../header/Bureaucrat.hpp"
#include "../header/AForm.hpp"

#include <time.h>
#include <cstdlib> 

// COLORS
# define BLUE "\e[1;34m"
# define RESET "\033[0m"

// 1 (highest possible grade)
// 150 (lowest possible grade)
// ShrubberyCreationForm: Required grades: 137
// RobotomyRequestForm: Required grades: 45
// PresidentialPardonForm: Required grades: 5
int	main(void)
{
	std::srand(time(NULL)); // Seed for random number generation

	// Constructors
	std::cout << BLUE << " ----- Constructors -----" << RESET << std::endl;
	ShrubberyCreationForm shrubForm("Garfield");
	RobotomyRequestForm robotForm("Gustav");
	PresidentialPardonForm pardonForm("Frank");

	Bureaucrat bureaucratBob("Bob", 5);
	std::cout << std::endl;

	try {
		// Execute Forms before signing
		std::cout << BLUE << "\n ----- Execute Forms before signing -----" << RESET << std::endl;
		bureaucratBob.executeForm(shrubForm);
		bureaucratBob.executeForm(robotForm);
		bureaucratBob.executeForm(pardonForm);
		std::cout << std::endl;

		// Sign forms
		std::cout << BLUE << "\n ----- Sign Forms -----" << RESET << std::endl;
		bureaucratBob.signForm(shrubForm);
		bureaucratBob.signForm(robotForm);  // Output changes beacuse of the rrandom number generation
		bureaucratBob.signForm(pardonForm);
		std::cout << std::endl;

		// Execute Forms after signing
		std::cout << BLUE << "\n ----- Execute Forms after signing -----" << RESET << std::endl;
		bureaucratBob.executeForm(shrubForm);
		bureaucratBob.executeForm(robotForm);
		bureaucratBob.executeForm(pardonForm);
		std::cout << std::endl;
	} 
	catch (const std::exception& exception) {
		std::cerr << "Exception: " << exception.what() << std::endl;
	}
		std::cout << BLUE << "\n ----- Destructors -----" << RESET << std::endl;
	return (0);
}  

