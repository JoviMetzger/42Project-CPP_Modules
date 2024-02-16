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
// Does the Reverse Polish Notation calculation by using vectors(container)
int	polishMathematical::calculations(const std::string& str)
{
	std::stack<int> _staStack;
	std::string string;
	std::stringstream iss(str);
	bool firstLoop = false; 

	// Checks if the number input is between 0 and 9
	while (std::getline(iss, string, ' '))
	{
		if (string.size() >= 2)
			throw std::runtime_error("Input must be between 0 and 9");
	}

	for (char c : str)
	{
		if (isdigit(c))
			_staStack.push(c - '0'); // Convert char to int
		else if (isOperator(c))
		{
			// Checks if the amount of operators is correct
			if (_staStack.size() < 2)
				throw std::runtime_error("Too many operators");

			// _staStack.top() returns a reference to the last element in the stack.
			// _staStack.pop(): This function removes the element of the stack. (the last element)
			// The 'int' gets assigned to the last element of the stack.
			int operandOne = _staStack.top(); _staStack.pop();
			int operandTwo = _staStack.top(); _staStack.pop();

			// Swaps the values of 'operandOne' and 'operandTwo', else the output is wrong
			// DOES NOT swap for the firstloop
			if (!firstLoop)
				std::swap(operandOne, operandTwo);
			else
				firstLoop = true;

			// Applies the operator on the operands and pushes the result back to the stack
			if (c == '+')
				_staStack.push(operandOne + operandTwo);
			else if (c == '-')
				_staStack.push(operandOne - operandTwo);
			else if (c == '*')
				_staStack.push(operandOne * operandTwo);
			else if (c == '/')
			{
				if (operandTwo == 0) // can't divide something by zero
					throw std::runtime_error("Undefined");
				_staStack.push(operandOne / operandTwo);
			}
		}
		else if (isspace(c))
			continue; // Skip whitespace
		else
			throw std::runtime_error("Unknown character");
	}

	// Checks if the amount of operators is correct
	if (_staStack.size() != 1)
		throw std::runtime_error("Not enough operators");

	return _staStack.top(); // Returns whats left in the stack (is the result)
}
