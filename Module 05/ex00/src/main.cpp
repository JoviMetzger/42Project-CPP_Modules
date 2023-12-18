#include "../header/Bureaucrat.hpp"

// COLORS
# define BLUE "\e[1;34m"
# define RESET "\033[0m"

// 1 (highest possible grade)
// 150 (lowest possible grade).
int	main()
{
	// Test the GardeIncrement()
	std::cout << BLUE << "\n ----- Test the GardeIncrement() -----" << RESET << std::endl;
	try 
	{
		Bureaucrat frank("Frank", 2);

		std::cout << frank;
		frank.incrementGrade();				// Frank's grade now 1
		std::cout << frank;
		frank.incrementGrade();				// throws exeption: too high
	}
	catch (const std::exception& exeption)
	{
		std::cerr << exeption.what() << std::endl;	// cerr: standard error
	}
	// Test the GardeDecrement()
	std::cout << BLUE << "\n ----- Test the GardeDecrement() -----" << RESET << std::endl;
	try 
	{
		Bureaucrat bob("Bob", 149);

		std::cout << bob;
		bob.decrementGrade();				// Bob's grade now 150
		std::cout << bob;
		bob.decrementGrade();				// throws exeption: too low
	}
	catch (const std::exception& exeption)
	{
		std::cerr << exeption.what() << std::endl;	// cerr: standard error
	}
	// Test the Bureaucrat constractor
	std::cout << BLUE << "\n ----- Test the Bureaucrat constractor -----" << RESET << std::endl;
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
	return 0;
}
