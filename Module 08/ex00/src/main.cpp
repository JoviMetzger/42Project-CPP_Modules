#include "../header/easyfind.hpp"

// header for the containers
# include <vector>
# include <list>

// COLORS
# define BLUE "\e[1;34m"
# define RESET "\033[0m"

int	main( void ) 
{
	// Example usage with a vector
	std::cout << BLUE << "Example usage with a vector" << RESET << std::endl;
	try {
		std::vector<int> _vector = {1, 2, 3, 4, 5};
		int	valueToFind = 3;
		int	invalidValueToFind = 10;

		// Finds value
		std::vector<int>::iterator result_valueToFind = easyfind(_vector, valueToFind);
		std::cout << "Value found at position: " << std::distance(_vector.begin(), result_valueToFind) << std::endl;

		// Throws exeption, value not found
		std::vector<int>::iterator result_invalidValueToFind = easyfind(_vector, invalidValueToFind);
		std::cout << "Value found at position: " << std::distance(_vector.begin(), result_invalidValueToFind) << std::endl;
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	// Example usage with a list
	std::cout << BLUE << "\nExample usage with a list" << RESET << std::endl;
	try {
		std::list<int> myList = {10, 20, 30, 40, 50};
		int	valueToFind = 10;
		int	invalidValueToFind = 1;

		std::list<int>::iterator result_valueToFind = easyfind(myList, valueToFind);
		std::cout << "Value found at position: " << std::distance(myList.begin(), result_valueToFind) << std::endl;

		std::list<int>::iterator result_invalidValueToFind = easyfind(myList, invalidValueToFind);
		std::cout << "Value found at position: " << std::distance(myList.begin(), result_invalidValueToFind) << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
