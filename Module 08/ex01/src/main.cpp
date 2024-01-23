#include "../header/Span.hpp"

// COLORS
# define BLUE "\e[1;34m"
# define RESET "\033[0m"

/*  Finding the shotest/longest distance between two numbers.
 *  example: 
 *      - the distance between 9 and 11 is the shortest - 2;
 *      - the distance between 3 and 16 is the longest - 14;
 */
int	main()
{
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

		// // Adding numbers single
		// sp.addNumber(1);
		// sp.addNumber(5);

		// Adding numbers by vector
		std::vector<int> moreNumbers = {1, 5};
		sp.addManyNumbers(moreNumbers);

		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl << std::endl;
	}

	try {

		// Having less than 2 numbers
		Span sp(5);
		sp.addNumber(8);

		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
}
