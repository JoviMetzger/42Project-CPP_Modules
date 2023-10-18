#include <iostream>
#include <string>

// COLORS
# define L_BLUE "\e[1;36m"
# define RESET "\033[0m"

/* 
 * - We use a pointer 'intPTR' to modify the value of x and then change the pointer to point to y.
 * - We use a reference 'intREF' to modify the value of x.
 * - You'll notice that when using a reference, changes made to the reference also affect the original variable,
 * 	 whereas pointers can be redirected to different variables.
 */
int	main()
{
	std::cout << "\n ---------- Subject requirements ----------\n" << std::endl;
	
	std::string	str = "HI THIS IS BRAIN";	// A string variable
	std::string	*stringPTR = &str;			// A pointer to the string
	std::string	&stringREF = str;			// A reference to the string

	// Print the memory addresses
	std::cout << L_BLUE << "The memory address of the string variable: " << RESET << &str << std::endl;
	std::cout << L_BLUE << "The memory address held by stringPTR: " << RESET << stringPTR << std::endl;
	std::cout << L_BLUE << "The memory address held by stringREF: " << RESET << &stringREF << std::endl;

	// Print the values
	std::cout << L_BLUE << "The value of the string variable: " << RESET << str << std::endl;
	std::cout << L_BLUE << "The value pointed to by stringPTR: " << RESET << *stringPTR << std::endl;
	std::cout << L_BLUE << "The value pointed to by stringREF: " << RESET << stringREF << std::endl;

	std::cout << "\n\n --------------- Extra Test ---------------\n" << std::endl;

	int	x = 10;
	int	y = 20;

	// Display initial values
	std::cout << "\n --------- Initial values: ---------" << std::endl;
	std::cout << L_BLUE << "X: " << RESET << "value: " << x << "  |  address: " << &x << std::endl;
	std::cout << L_BLUE << "Y: " << RESET << "value: " << y << "  |  address: " << &y << std::endl;

	int	*intPTR = &x;	// Pointer to an integer
	int	&intREF = x;	// Reference to an integer

	std::cout << L_BLUE << "\nintPTR: " << RESET << "value: " << intPTR << "  |  address: " << &intPTR << "  |  pointed value: " << *intPTR << std::endl;
	std::cout << L_BLUE << "intREF: " << RESET << "value: " << intREF << "  |  address: " << &intREF << std::endl;

	// Changing values
	*intPTR = 30; // Modifies the value of x through the pointer
	intPTR = &y;  // Changes the pointer to point to y
	intREF = 40;  // Modifies the value of x through the reference

	// Display final values
	std::cout << "\n --------- Final values: ---------" << std::endl;
	std::cout << L_BLUE << "X: " << RESET << "value: " << x << "  |  address: " << &x << std::endl;
	std::cout << L_BLUE << "Y: " << RESET << "value: " << y << "  |  address: " << &y << std::endl;
	std::cout << L_BLUE << "\nintPTR: " << RESET << "value: " << intPTR << "  |  address: " << &intPTR << "  |  pointed value: " << *intPTR << std::endl;
	std::cout << L_BLUE << "intREF: " << RESET << "value: " << intREF << "  |  address: " << &intREF << std::endl;
}
