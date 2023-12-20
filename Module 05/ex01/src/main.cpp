#include "../header/Bureaucrat.hpp"
#include "../header/Form.hpp"

// COLORS
# define BLUE "\e[1;34m"
# define RESET "\033[0m"

// 1 (highest possible grade)
// 150 (lowest possible grade).
int	main(void)
{
	std::cout << BLUE << " --------------------------------------" << RESET << std::endl;
	{
		// Test the Bureaucrat constractor
		std::cout << BLUE << " ----- Test the Bureaucrat constractor -----" << RESET << std::endl;
		try 
		{
			Bureaucrat gustav("Gustav", 999);
		}
		catch (const std::exception& exeption)
		{
			std::cerr << exeption.what() << std::endl;	// cerr: standard error
		}
		try 
		{
			Bureaucrat gustav("Gustav", 0);
		}
		catch (const std::exception& exeption)
		{
			std::cerr << exeption.what() << std::endl;	// cerr: standard error
		}
		std::cout << std::endl;
	}
	std::cout << BLUE << " --------------------------------------" << RESET << std::endl;
	{
		// Constructors
		std::cout << BLUE << " ----- Constructors -----" << RESET << std::endl;

		Bureaucrat	frank("Frank", 130);

		// Constructors
		std::cout << BLUE << "\n ----- Incrementing/Decrementing -----" << RESET << std::endl;
		try
		{
			frank.incrementGrade();				// grade 129
			std::cout << frank;
			frank.incrementGrade();				// garde 128
			std::cout << frank;
			frank.decrementGrade();				// garde 129
			std::cout << frank;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;		// cerr: standard error
		}

		// Sign forms
		std::cout << BLUE << "\n ----- Sign Forms -----" << RESET << std::endl;

		// const std::string& name, int gradeToSign, int gradeToExecute
		Form formA("Tax Form", 10, 10);
		Form formB("Complain Form", 130, 150);
		std::cout << std::endl;

		frank.signForm(formA);					// Couln't sign Form
		std::cout << formA;
		std::cout << std::endl;

		frank.signForm(formB);					// Could sign Form
		std::cout << formB;

		std::cout << BLUE << "\n ----- Destructors -----" << RESET << std::endl;
	}
	return (0);
}  
