#include "Point.hpp"

// COLORS
# define BLUE "\e[1;34m"
# define RESET "\033[0m"

int	main() 
{
	const	Point A(0, 0);
	const	Point B(5, 0);
	const	Point C(2.5f, 5);

	Point	a(4, 2.3f);
	Point	b(4.99f, 1);
	Point	c(4.0f, 4.0f);
	Point	d(6, 6);
	Point	e(2, 2);

	std::cout << BLUE << "a: " << RESET << (bsp(A, B, C, a) ? "Inside" : "Outside") << std::endl;
	std::cout << BLUE << "b: " << RESET << (bsp(A, B, C, b) ? "Inside" : "Outside") << std::endl;
	std::cout << BLUE << "c: " << RESET << (bsp(A, B, C, c) ? "Inside" : "Outside") << std::endl;
	std::cout << BLUE << "d: " << RESET << (bsp(A, B, C, d) ? "Inside" : "Outside") << std::endl;
	std::cout << BLUE << "e: " << RESET << (bsp(A, B, C, e) ? "Inside" : "Outside") << std::endl;
	return 0;
}
