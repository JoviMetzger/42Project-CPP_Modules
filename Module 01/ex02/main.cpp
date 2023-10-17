#include <iostream>
#include <string>

// COLORS
# define L_BLUE "\e[1;36m"
# define RESET "\033[0m"

int	main()
{
	std::cout << "\n ---------- Subject requirements ----------\n" << std::endl;
	// A string variable
	std::string	str = "HI THIS IS BRAIN";

	// A pointer to the string
	std::string*	stringPTR = &str;

	// A reference to the string
	std::string&	stringREF = str;

	// Print the memory addresses
	std::cout << L_BLUE << "The memory address of the string variable: " << RESET << &str << std::endl;
	std::cout << L_BLUE << "The memory address held by stringPTR: " << RESET << stringPTR << std::endl;
	std::cout << L_BLUE << "The memory address held by stringREF: " << RESET << &stringREF << std::endl;

	// Print the values
	std::cout << L_BLUE << "The value of the string variable: " << RESET << str << std::endl;
	std::cout << L_BLUE << "The value pointed to by stringPTR: " << RESET << *stringPTR << std::endl;
	std::cout << L_BLUE << "The value pointed to by stringREF: " << RESET << stringREF << std::endl;

	std::cout << "\n\n ---------- Extra Test ----------\n" << std::endl;

	int	x = 10;
	int	y = 20;

	// Display initial values
	std::cout << L_BLUE << "Initial values:" << RESET << std::endl;
	std::cout << "x: " << x << "\ny: " << y << std::endl;
}
