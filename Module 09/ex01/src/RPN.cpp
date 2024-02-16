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
	std::stack<int> numStack;
	std::stack<char> opStack;
	std::string string;
	std::stringstream iss(str);
	bool firstLoop = false; 

	// Checks if the number input is between 0 and 9
	while (std::getline(iss, string, ' '))
	{
		if (string.size() >= 2)
			throw std::runtime_error("Input must be between 0 and 9");
	}

	// Iterate through the string from end to start
	for (int i = str.size() - 1; i >= 0; --i)  
	{
		char c = str[i];		// Dereference the reverse iterator to get the character

		if (isdigit(c))
			numStack.push(c - '0');	// Convert char to int
		else if (isOperator(c))
			opStack.push(c);	// Pushes operaator (char) to stack
		else if (isspace(c))
			continue;		// Skip whitespace
		else
			throw std::runtime_error("Unknown character");
	}

	while (!opStack.empty()) 
	{
		// Checks if the amount of operators is correct
		if (numStack.size() < 2)
			throw std::runtime_error("Too many operators");

		// top() returns a reference to the last element in the stack.
		// pop(): This function removes the element of the stack. (the last element)
		// The 'int' gets assigned to the last element of the stack.
		int	operandTwo = numStack.top(); numStack.pop();
		int	operandOne = numStack.top(); numStack.pop();
		char	_opertor = opStack.top(); opStack.pop();

		// Swaps the values of 'operandOne' and 'operandTwo', else the output is wrong
		// DOES NOT swap for the firstloop
		if (!firstLoop)
			std::swap(operandOne, operandTwo);
		else
			firstLoop = true;

		// Applies the operator on the operands and pushes the result back to the stack
		if (_opertor == '+')
			numStack.push(operandOne + operandTwo);
		else if (_opertor == '-')
			numStack.push(operandOne - operandTwo);
		else if (_opertor == '*')
			numStack.push(operandOne * operandTwo);
		else if (_opertor == '/')
		{
			if (operandTwo == 0)	// can't divide something by zero
				throw std::runtime_error("Undefined");
			numStack.push(operandOne / operandTwo);
		}
	}

	// Checks if the amount of operators is correct
	if (numStack.size() != 1) {
		throw std::runtime_error("Not enough operators");
	}

	return numStack.top();	// Returns whats left in the stack (is the result)
}
