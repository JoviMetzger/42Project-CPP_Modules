#include "../header/iter.hpp"

// COLORS
# define BLUE "\e[1;34m"
# define RESET "\033[0m"

// ---------- Main() ----------
int	main() 
{
	std::cout << BLUE << " ----- Testing func 1: printElement -----" << RESET << std::endl;
	std::cout << BLUE << " Testing intArray" << RESET << std::endl;
	// Example 1: Using iter with an array of int - with function printElement()
	{
		int intArray[] = {1, 2, 3, 4, 5};
		size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);

		std::cout << "Applying iter to intArray: ";
		iter(intArray, intArrayLength, printElement<int>);
		std::cout << std::endl << std::endl;
	}
	std::cout << BLUE << " Testing doubleArray" << RESET << std::endl;
    // Example 2: Using iter with an array of doubles - with function printElement()
	{
		double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
		size_t doubleArrayLength = sizeof(doubleArray) / sizeof(doubleArray[0]);

		std::cout << "Applying iter to doubleArray: ";
		iter(doubleArray, doubleArrayLength, printElement<double>);
		std::cout << std::endl << std::endl;
	}
	std::cout << BLUE << " Testing charArray " << RESET << std::endl;
	// Example 3: Using iter with an array of char - with function printElement()
	{
		char charArray[] = {'x', 'y', 'z', '1', '2'};
		size_t charArrayLength = sizeof(charArray) / sizeof(charArray[0]);

		std::cout << "Applying iter to charArray: ";
		// Applying iter to turn everything into 'a'
		iter(charArray, charArrayLength, printElement<char>);
		std::cout << std::endl << std::endl;
	}
	std::cout << BLUE << " ----- Testing func 2: turnIntoA -----" << RESET << std::endl;
	std::cout << BLUE << " Testing intArray" << RESET << std::endl;
	// Example 4: Using iter with an array of int - with function turnIntoA()
	{
		int intArray[] = {1, 2, 3, 4, 5};
		size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);

		std::cout << "Original intArray: ";
		for (size_t i = 0; i < intArrayLength; ++i) 
			std::cout << intArray[i] << ", ";
		std::cout << std::endl;

		// Applying iter to turn everything into 'a'
		iter(intArray, intArrayLength, turnIntoA<int>);

		std::cout << "After applying iter: ";
		for (size_t i = 0; i < intArrayLength; ++i) 
			std::cout << intArray[i] << ", ";
		std::cout << std::endl << std::endl;
	}
	std::cout << BLUE << " Testing doubleArray" << RESET << std::endl;
	// Example 5: Using iter with an array of doubles- with function turnIntoA()
	{
		double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
		size_t doubleArrayLength = sizeof(doubleArray) / sizeof(doubleArray[0]);

		std::cout << "Original doubleArray: ";
		for (size_t i = 0; i < doubleArrayLength; ++i) 
			std::cout << doubleArray[i] << ", ";
		std::cout << std::endl;

		// Applying iter to turn everything into 'a'
		iter(doubleArray, doubleArrayLength, turnIntoA<double>);

		std::cout << "After applying iter: ";
		for (size_t i = 0; i < doubleArrayLength; ++i) 
			std::cout << doubleArray[i] << ", ";
		std::cout << std::endl << std::endl;
	}
	std::cout << BLUE << " Testing charArray " << RESET << std::endl;
	// Example 6: Using iter with an array of char - with function turnIntoA()
	{
		char charArray[] = {'x', 'y', 'z', '1', '2'};
		size_t charArrayLength = sizeof(charArray) / sizeof(charArray[0]);

		std::cout << "Original charArray: ";
		for (size_t i = 0; i < charArrayLength; ++i) 
			std::cout << charArray[i] << ", ";
		std::cout << std::endl;

		// Applying iter to turn everything into 'a'
		iter(charArray, charArrayLength, turnIntoA<char>);

		std::cout << "After applying iter: ";
		for (size_t i = 0; i < charArrayLength; ++i) 
			std::cout << charArray[i] << ", ";
		std::cout << std::endl;
	}

    return 0;
}
