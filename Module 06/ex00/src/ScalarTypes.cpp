#include "../header/ScalarTypes.hpp"

// Convert Function
void ScalarConverter::convert(const std::string &input)
{
	char	_char = 0;
	int	_int = 0;
	float	_float = 0.0f;
	double	_double = 0.0;

	std::istringstream stream(input);

	// stream.clear();	- Resets these error flags, allowing further operations on the stream to be attempted.
	// stream.str(input);	- Replaces the current contents of the stream buffer with the content specified by the string 'input'.

	// _______________________________________________________________________________
	// Atempt to convert to char
	if (input.size() == 1) // For single characters
	{
		// If the single character is a number, output the ascii value.
		if (isdigit(input[0]))
		{
			int num = std::stoi(input);
			if (!isprint(num))	// ascii value is not printable
				std::cout << "Char: Non displayable" << std::endl;
			else
				std::cout << "Char: " << _char << std::endl;
		}
		else
		{
			// Output the single character
			_char = input[0];
			std::cout << "Char: " << _char << std::endl;
		}
	}
	else
	{
		if (correctNumberInput(input))	// Check if the correct number input
		{
			// try/catch for overflow
			try 
			{
				int num = std::stoi(input);
		
				// Check if num is within the valid range for a char
				if (num >= 0 && num <= 127)
				{
					_char = static_cast<char>(num);
					if (!isprint(num))
						std::cout << "Char: Non displayable" << std::endl; // ascii value is not printable
					else
						std::cout << "Char: " << _char << std::endl;
				}
				else
					std::cout << "Char: impossible (out of ascii range)" << std::endl; // num is out off ascii range
			}
			catch (std::out_of_range& e) {
				std::cout << "Char: impossible (out of ascii range)" << std::endl;
			}
		}
		else
			std::cout << "Char: impossible" << std::endl;
	}

	// _______________________________________________________________________________
	// Atempt to convert to int
	stream.clear();		
	stream.str(input);	
	
	if (correctNumberInput(input)) // Checks for correct number input
	{
		// try/catch for overflow
		try
		{
			_int = static_cast<int>(std::stoi(input)); // If overflow: stoi() 'catches' it
			std::cout << "Int: " << _int << std::endl;
		} 
		catch (const std::exception& e) {
			std::cout << "Int: impossible (out of int range)" << std::endl;
		}
	}
	else
		std::cout << "Int: impossible" << std::endl;


	// _______________________________________________________________________________
	// Atempt to convert to float
	stream.clear();		
	stream.str(input);	
	
	if (correctNumberInput(input)) // Checks for correct number input
	{
		// try/catch for overflow
		try
		{
			_float = static_cast<float>(std::stof(input)); // If overflow: stof() 'catches' it
			std::cout << "Float: " << std::setprecision(1) << std::fixed << _float << "f" << std::endl;
		} 
		catch (std::out_of_range& e) {
			std::cout << "Float: impossible (out of float range)" << std::endl;	
		}
	}
	else
		std::cout << "Float: " << input << 'f' << std::endl;


	// _______________________________________________________________________________
	// Atempt to convert to double
	stream.clear();	
	stream.str(input);

	if (correctNumberInput(input)) // Checks for correct number input
	{
		// try/catch for overflow
		try
		{
			_double = static_cast<double>(std::stod(input)); // If overflow: stod() 'catches' it
			std::cout << "Double: " << std::setprecision(1) << std::fixed << _double << std::endl;
		} 
		catch (std::out_of_range& e) {
			std::cout << "Double: impossible (out of double range)" << std::endl;
		}
	}
	else
		std::cout << "Double: " << input << std::endl;
}


// correctNumberInput();
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
