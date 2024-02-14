#include "../header/RPN.hpp"

/* Reverse Polish notation (RPN) the operators follow their operands. 
 * For example, to add 3 and 4 together, the expression is 3 4 + rather than 3 + 4. 
 * The conventional notation expression 3 − 4 + 5 becomes 3 4 − 5 + in reverse Polish notation: 
 * 4 is first subtracted from 3, then 5 is added to it.
 */
int	main(int argc, char **argv)
{
	polishMathematical rpn;

	try {
		// Checks arguments
		if (argc != 2)
			throw std::runtime_error("./RPN '<RPN expression>'.");

		// Converts char** into string
		std::string str = argv[1];

		// Calculates Reverse Polish Notation
		int result = rpn.calculations(str);
		std::cout << result << std::endl;

	} catch(const std::exception& e) {
		std::cerr << RED << "Error: " << RESET <<  e.what() << std::endl;;
	}

	return 0;
}
