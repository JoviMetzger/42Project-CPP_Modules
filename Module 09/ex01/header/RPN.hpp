#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <algorithm>
# include <stack>
# include <stdexcept>
# include <sstream>

// COLORS
# define RED "\e[1;91m"
# define RESET "\033[0m"

class	polishMathematical
{
	public:
		polishMathematical();						// Default Constructor
		~polishMathematical();						// Destructor 
		polishMathematical(const polishMathematical& value);		// Copy constructor
		polishMathematical &operator=(const polishMathematical& value);	// Assignment= operator

		// Member function
		int	calculations(const std::string& str);
		bool	isOperator(char c);
};

#endif
