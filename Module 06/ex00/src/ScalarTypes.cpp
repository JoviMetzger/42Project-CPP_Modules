#include "../header/ScalarTypes.hpp"

// Default Constructor
ScalarConverter::ScalarConverter()
{
	std::cout << "Default constructor called" << std::endl;
}

// Destructor
ScalarConverter::~ScalarConverter()
{
	std::cout << "Destructor called" << std::endl;
}

// Copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter& value)
{
	std::cout << "Copy constructor called" << std::endl; 
	*this = value;
}

// Copy assignment operator
ScalarConverter	&ScalarConverter::operator=(const ScalarConverter& value)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &value)	
	{
		// Perform a deep copy
	}
	return *this;
}

// Convert Function
void ScalarConverter::convert(const std::string &input)
{
	char	_char = 0;
	int	_int = 0;
	float	_float = 0.0f;
	double	_double = 0.0;

	std::istringstream stream(input);

	// _______________________________________________________________________________
	// Atempt to convert to char
	if (input.size() == 1)
	{
		if (isdigit(input[0]))		// If the single character is a number, output the ascii value.
		{
			int num = std::stoi(input);
			if (!isprint(num))	// ascii value is not printable
				std::cout << "Char: Non displayable" << std::endl;
			else
				std::cout << "Char: " << _char << std::endl;
		}
		else	// Output the single character
		{
			_char = input[0];
			std::cout << "Char: " << _char << std::endl;
		}
	}
	else
	{
		try 
		{
			if (correctNumberInput(input))	// Check if the correct number input
			{
				// Check if num is within the valid range for a char
				int num = std::stoi(input);
				if (num > std::numeric_limits<char>::min() && num < std::numeric_limits<char>::max())
				{
					// Output the ascii value.
					_char = static_cast<char>(num);
					if (!isprint(num))	// ascii value is not printable
						std::cout << "Char: Non displayable" << std::endl;
					else
						std::cout << "Char: " << _char << std::endl;
				} 
				else 
					std::cout << "Char: impossible (out of char range)" << std::endl;
			}
			else	// Input is not a single character, but a string
				std::cout << "Char: impossible" << std::endl;
		} catch (const std::out_of_range& exeption) {
			std::cout << "Char: impossible (out of int range)" << std::endl;
		}
	}
	// _______________________________________________________________________________

	// Atempt to convert to int
	stream.clear();		// Resets these error flags, allowing further operations on the stream to be attempted.
	stream.str(input);	// Replaces the current contents of the stream buffer with the content specified by the string 'input'.
	
	if (correctNumberInput(input)) // Checks for correct number input
	{

		if (input.find('.') != std::string::npos) // Input is a float or double
		{
			stream >> std::noskipws; // Avoid skipping whitespace
			
			// Check if 'f' is the last character in the input
			if (input.back() != 'f') // Converts string value (double) to int
			{
				std::istringstream(input) >> _int;
				if (_int > std::numeric_limits<int>::min() && _int < std::numeric_limits<int>::max())
					std::cout << "Int: " << _int << std::endl;
				else
					std::cout << "Int: impossible (out of int range)" << std::endl;
			} 
			else if (input.back() == 'f') // Converts string value (float) to int
			{
				std::istringstream(input) >> _int;
				if (_int > std::numeric_limits<int>::min() && _int < std::numeric_limits<int>::max())
					std::cout << "Int: " << _int << std::endl;
				else
					std::cout << "Int: impossible (out of int range)" << std::endl;
			}
		}
		else // String value is int
		{
			std::istringstream(input) >> _int; // Convert string to int
			if (_int > std::numeric_limits<int>::min() && _int < std::numeric_limits<int>::max())
				std::cout << "Int: " << _int << std::endl;
			else
				std::cout << "Int: impossible (out of int range)" << std::endl;
		}
	}
	else
		std::cout << "Int: impossible" << std::endl;
	// _______________________________________________________________________________

	// Atempt to convert to float
	stream.clear();		// Resets these error flags, allowing further operations on the stream to be attempted.
	stream.str(input);	// Replaces the current contents of the stream buffer with the content specified by the string 'input'.
	
	if (correctNumberInput(input)) // Checks for correct number input
	{
		stream >> std::noskipws >> _float;
		if (input.back() == 'f') // String value is a float
		{
			// Converts string value to float value
			if (_float > std::numeric_limits<float>::min() && _float < std::numeric_limits<float>::max())
				std::cout << "Float: " << std::setprecision(1) << std::fixed << _float << "f" << std::endl;
			else
			{
				if (input[0] == '-') // Outputs negative float number
        			std::cout << "Float: " << std::setprecision(1) << std::fixed << _float << "f" << std::endl;
				else
					std::cout << "Float: impossible (out of int range)" << std::endl;
			}
		}
		else
		{
			if (input.find('.') != std::string::npos) // String value is a double
			{
				// Converts string value to float value
				if (_float > std::numeric_limits<float>::min() && _float < std::numeric_limits<float>::max())
						std::cout << "Float: " << std::setprecision(1) << std::fixed << _float << "f" << std::endl;
				else
				{
					if (_float == 0) // Specaial case for 0
						std::cout << "Float: 0.0f" << std::endl;
					else
					{
						if (input[0] == '-')  // Outputs negative float number
							std::cout << "Float: " << std::setprecision(1) << std::fixed << _float << "f" << std::endl;
						else
							std::cout << "Float: impossible (out of int range)" << std::endl;
					}
				}
			}
			else
				std::cout << "Float: " << std::setprecision(1) << std::fixed << _float << "f" << std::endl;
		}
	}
	else
		std::cout << "Float: " << input << 'f' << std::endl;
	// _______________________________________________________________________________

	// Atempt to convert to double
	stream.clear();		// Resets these error flags, allowing further operations on the stream to be attempted.
	stream.str(input);	// Replaces the current contents of the stream buffer with the content specified by the string 'input'.
	
	if (correctNumberInput(input)) // Checks for correct number input
	{
		stream >> _double;
		if (input.back() == 'f') // String value is float
		{
			// Converts string value to double value
			if (_double > std::numeric_limits<double>::min() && _double < std::numeric_limits<double>::max())
				std::cout << "Double: " << std::setprecision(1) << std::fixed << _double << std::endl;
			else
			{
				if (input[0] == '-') // Outputs negative double number
					std::cout << "Double: " << std::setprecision(1) << std::fixed << _double << std::endl;
				else
					std::cout << "Double: impossible (out of int range)" << std::endl;
			}
		}
		else
		{
			// Converts string value to double value
			if (input.find('.') != std::string::npos)
			{
				if (_double > std::numeric_limits<double>::min() && _double < std::numeric_limits<double>::max())
					std::cout << "Double: " << std::setprecision(1) << std::fixed << _double << std::endl;
				else
				{
					if (_double == 0) // Specaial case for 0
						std::cout << "Double: 0.0" << std::endl;
					else
					{
						if (input[0] == '-') // Outputs negative double number
							std::cout << "Double: " << std::setprecision(1) << std::fixed << _double << std::endl;
						else
							std::cout << "Double: impossible (out of int range)" << std::endl;
					}
				}
			}
			else
				std::cout << "Double: " << std::setprecision(1) << std::fixed << _double << std::endl;
		}
	}
	else
		std::cout << "Double: " << input << std::endl;
	// _______________________________________________________________________________

}


// Checks if the input is a 'correct' int, float or double (int: x, float: x.xf, double: x.x)
bool correctNumberInput(const std::string &input)
{
	if (input[0] == '-')
	{
		// If input is negative, remove '-' and do all checks
		std::string iinput = input.substr(1);
		return correctNumberInput(iinput);
	}
	else if (input.find('.') != std::string::npos) // Input is either float or double
	{
		size_t i = 0;

		if (input[0] == '.') // If first character is '.'
			return false;

		while (i < input.size())
		{
			if (input[i] == '.')
			{
				if (input[i + 1] == 'f') // If the character after '.' is a 'f'
					return false;
				
				if (!isprint(input[i + 1])) // If there is no chararcter after '.'
					return false;

				size_t j = 0;
				while (input[j] != '.')
				{
					// Checking if every character before the '.' is a digit
					if (!isdigit(input[j]))
						return false;
					j++;
				}
				if (input.back() == 'f') // Input is a float
				{
					// Check if all character between '.' and 'f' are digits
					j = i + 1;
					while (j < input.size() - 1)
					{
						if (!isdigit(input[j]))
							return false;
						j++;
					}
				}
				else if (input.back() != 'f') // Input is a double
				{
					// Check if all character between '.' and last character are digits
					j = i + 1;
					while (j < input.size())
					{
						if (!isdigit(input[j]))
							return false;
						j++;
					}
				}
				else
					return false;
			}
			i++;
		}
	}
	else
	{
		// Input is a 'normal' number - check if all characters are digits
		for (size_t i = 0; i < input.size(); i++)
		{
			if (!isdigit(input[i]))
				return false;
		}
	}
	return true;
}
