#include "../header/RPN.hpp"

// Default Constructor
polishMathematical::polishMathematical()
{
	std::cout << "Default constructor called" << std::endl;
}

// Destructor
polishMathematical::~polishMathematical()
{
	std::cout << "Destructor called" << std::endl;
}

// Copy constructor
polishMathematical::polishMathematical(const polishMathematical& value)
{
	std::cout << "Copy constructor called" << std::endl; 
	*this = value;
}

// Copy assignment operator
polishMathematical	&polishMathematical::operator=(const polishMathematical& value)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &value) {}
	return *this;
}

//------------------------------------------------------------------------------
// -- Member Functions --
// Checks if the operators are '+', '-', '*', '/'
bool	polishMathematical::isOperator(char c)
{
	if ((c == '+' || c == '-' || c == '*' || c == '/'))
		return true;
	return false;
}

// Does the Reverse Polish Notation calculation by using vectors(container)
int	polishMathematical::calculations(const std::string& str)
{
	std::vector<int> _vecStack;
	bool firstLoop = false; 

	for (char c : str)
	{
		if (isdigit(c))
			_vecStack.push_back(c - '0'); // Convert char to int
		else if (isOperator(c))
		{
			// Checks if the amount of operators is correct
			if (_vecStack.size() < 2)
				throw std::runtime_error("Too many operators.");

			// _vecStack.back() returns a reference to the last element in the vector stack.
			// _vecStack.pop_back(): This function removes the last element of the vector stack.
			// The 'int' gets assigned to the last element of the stack.
			int operandOne = _vecStack.back(); _vecStack.pop_back();
			int operandTwo = _vecStack.back(); _vecStack.pop_back();

			// Swaps the values of 'operandOne' and 'operandTwo', else the output is wrong
			// DOES NOT swap for the firstloop
			if (!firstLoop)
				std::swap(operandOne, operandTwo);
			else
				firstLoop = true;

			// Applies the operator on the operands and pushes the result back to the vector
			if (c == '+')
				_vecStack.push_back(operandOne + operandTwo);
			else if (c == '-')
				_vecStack.push_back(operandOne - operandTwo);
			else if (c == '*')
				_vecStack.push_back(operandOne * operandTwo);
			else if (c == '/')
			{
				if (operandTwo == 0) // can't divide something by zero
					throw std::runtime_error("Undefined");
				_vecStack.push_back(operandOne / operandTwo);
			}
		}
		else if (isspace(c))
			continue;	 // Skip whitespace
		else
			throw std::runtime_error("Unknown character.");
	}

	// Checks if the amount of operators is correct
	if (_vecStack.size() != 1)
		throw std::runtime_error("Not enough operators.");

	return _vecStack.back(); // Returns whats left in the vector (is the result)
}

