#include "../header/ScalarTypes.hpp"

// COLORS
# define BLUE "\e[1;34m"
# define RESET "\033[0m"

int	main()
{
       	std::cout << BLUE << ">>>>> INPUT: 0 <<<<<" << RESET << std::endl;
	{
		ScalarConverter::convert("0");		// int
		std::cout << std::endl;
	}
	std::cout << BLUE << ">>>>> INPUT: nan <<<<<" << RESET << std::endl;
	{
		ScalarConverter::convert("nan");	// string
		std::cout << std::endl;
	}
	std::cout << BLUE << ">>>>> INPUT: 42.0f <<<<<" << RESET << std::endl;
	{
		ScalarConverter::convert("42.0f");	// float
		std::cout << std::endl;
	}
	std::cout << BLUE << ">>>>> INPUT: a <<<<<" << RESET << std::endl;
	{
		ScalarConverter::convert("a");		// char
		std::cout << std::endl;
	}
	std::cout << BLUE << ">>>>> INPUT: 4.2 <<<<<" << RESET << std::endl;
	{
		ScalarConverter::convert("4.2");	// double
		std::cout << std::endl;
	}
	std::cout << BLUE << ">>>>> INPUT: 234456778994453355354576 <<<<<" << RESET << std::endl;
	{
		ScalarConverter::convert("234456778994453355354576");	// Max Int
		std::cout << std::endl;
	}
	std::cout << BLUE << ">>>>> INPUT: 66 <<<<<" << RESET << std::endl;
	{
		ScalarConverter::convert("66");		// Int
		std::cout << std::endl;
	}
	std::cout << BLUE << ">>>>> INPUT: 12.h <<<<<" << RESET << std::endl;
	{
		ScalarConverter::convert("12.h");	// invalid
		std::cout << std::endl;
	}
	std::cout << BLUE << ">>>>> INPUT: 12h <<<<<" << RESET << std::endl;
	{
		ScalarConverter::convert("12h");	// invalid
		std::cout << std::endl;
	}
	std::cout << BLUE << ">>>>> INPUT: 12.12h <<<<<" << RESET << std::endl;
	{
		ScalarConverter::convert("12.12h");	// invalid
		std::cout << std::endl;
	}
	std::cout << BLUE << ">>>>> INPUT: 12.12 <<<<<" << RESET << std::endl;
	{
		ScalarConverter::convert("12.12");	// double
		std::cout << std::endl;
	}
	std::cout << BLUE << ">>>>> INPUT: 12.12f <<<<<" << RESET << std::endl;
	{
		ScalarConverter::convert("12.12f");	// float
		std::cout << std::endl;
	}
	std::cout << BLUE << ">>>>> INPUT: 12.f <<<<<" << RESET << std::endl;
	{
		ScalarConverter::convert("12.f");	// invalid
		std::cout << std::endl;
	}
	std::cout << BLUE << ">>>>> INPUT: 12.0h <<<<<" << RESET << std::endl;
	{
		ScalarConverter::convert("12.0h");	// invalid
		std::cout << std::endl;
	}
	std::cout << BLUE << ">>>>> INPUT: 12.12hf <<<<<" << RESET << std::endl;
	{
		ScalarConverter::convert("12.12hf");	// invalid
		std::cout << std::endl;
	}
	std::cout << BLUE << ">>>>> INPUT: 12.12fh <<<<<" << RESET << std::endl;
	{
		ScalarConverter::convert("12.12fh");	// invalid
		std::cout << std::endl;
	}
	std::cout << BLUE << ">>>>> INPUT: 12. <<<<<" << RESET << std::endl;
	{
		ScalarConverter::convert("12.");	// invalid
		std::cout << std::endl;
	}
	std::cout << BLUE << ">>>>> INPUT: .12 <<<<<" << RESET << std::endl;
	{
		ScalarConverter::convert(".12");	// invalid
		std::cout << std::endl;
	}
	std::cout << BLUE << ">>>>> INPUT: a2.12 <<<<<" << RESET << std::endl;
	{
		ScalarConverter::convert("a2.12");	// invalid
		std::cout << std::endl;
	}
	std::cout << BLUE << ">>>>> INPUT: -4.2 <<<<<" << RESET << std::endl;
	{
		ScalarConverter::convert("-4.2");	// negative double
		std::cout << std::endl;
	}
	std::cout << BLUE << ">>>>> INPUT: -4.20f <<<<<" << RESET << std::endl;
	{
		ScalarConverter::convert("-4.20f");	// negative float
		std::cout << std::endl;
	}
	std::cout << BLUE << ">>>>> INPUT: -234456778994453355354576 <<<<<" << RESET << std::endl;
	{
		ScalarConverter::convert("-234456778994453355354576");	// Min Int
		std::cout << std::endl;
	}
	std::cout << BLUE << ">>>>> INPUT: -66 <<<<<" << RESET << std::endl;
	{
		ScalarConverter::convert("-66");	// negative Int
		std::cout << std::endl;
	}
	return 0;
}
