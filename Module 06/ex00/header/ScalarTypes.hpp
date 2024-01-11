#ifndef SCALARTYPES_HPP
# define SCALARTYPES_HPP

# include <iostream>
# include <limits>
# include <iomanip>

class	ScalarConverter
{
	private:
		// Private constructor to prevent instantiation
		ScalarConverter();						// Default constructor
		ScalarConverter(const ScalarConverter& value);			// Copy constructor
		ScalarConverter& operator=(const ScalarConverter& value);	// Copy assignment operator
		~ScalarConverter();						// Destructor
	public:
		static void convert(const std::string &input);			// Convert Fuction
};

bool correctNumberInput(const std::string &input);				// Function to check input
#endif
