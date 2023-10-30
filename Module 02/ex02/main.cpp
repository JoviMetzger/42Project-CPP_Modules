#include "Fixed.hpp"

// COLORS
# define L_BLUE "\e[1;36m"
# define RESET "\033[0m"

int	main( void ) 
{
	Fixed	a;					// Initial value of a
	Fixed	const b( Fixed( 5.05f ) * Fixed( 2 ) );	// Initial value of 10.1016

	std::cout << a << std::endl;			// Value of a
	std::cout << ++a << std::endl;			// Pre-increments a
	std::cout << a << std::endl;			// Current value of a
	std::cout << a++ << std::endl;			// Post-increments a 
	std::cout << a << std::endl;			// Current value of a
	std::cout << b << std::endl;			// Value of b
	std::cout << Fixed::max( a, b ) << std::endl;	// Finding Max value between a & b

	std::cout << "\n ---------- Extra Test ----------" << std::endl;
	Fixed	a;
	Fixed	const b(5.05f);
	Fixed	const c(2);
	Fixed	const d(1.23f);
	Fixed	e;

	std::cout << L_BLUE << "\nInital Values" << RESET << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << "e: " << e << std::endl;

	// Arithmetic operations
	Fixed	result;
	std::cout << L_BLUE << "\nArithmetic operations" << RESET << std::endl;
	result = b + c;
	std::cout << "b + c: " << result << std::endl;

	result= b - c;
	std::cout << "b - c: " << result << std::endl;

	result = b * c;
	std::cout << "b * c: " << result << std::endl;

	result = b / c;
	std::cout << "b / c: " << result << std::endl;

	// Comparison operators
	std::cout << L_BLUE << "\nComparison operators" << RESET << std::endl;
	bool	less_than = b < c;
	std::cout << "b < c : " << (less_than ? "true" : "false") << std::endl;

	bool	equal = b == c;
	std::cout << "b == c: " << (equal ? "true" : "false") << std::endl;

	bool	greater_than = b > c;
	std::cout << "b > c : " << (greater_than ? "true" : "false") << std::endl;

	bool not_equal = b != c;
	std::cout << "b != c: " << (not_equal ? "true" : "false") << std::endl;

	// Increment and decrement operators
	std::cout << L_BLUE << "\nIncrement and decrement operators" << RESET << std::endl;
	e++;
	std::cout << "e after post-increment: " << e << std::endl;

	e--;
	std::cout << "e after post-decrement: " << e << std::endl;

	++e;
	std::cout << "e after pre-increment : " << e << std::endl;

	--e;
	std::cout << "e after pre-decrement : " << e << std::endl;

	// Static member functions
	std::cout << L_BLUE << "\nStatic member functions" << RESET << std::endl;
	Fixed	min_value = Fixed::min(b, c);
	std::cout << "Minimum value among b and c: " << min_value << std::endl;

	Fixed	max_value = Fixed::max(b, c);
	std::cout << "Maximum value among b and c: " << max_value << std::endl;

	const	Fixed& min_bc = Fixed::min(b, c);
	std::cout << "const minimum of b and c   : " << min_bc << std::endl;

	const	Fixed& max_ad = Fixed::max(b, c);
	std::cout << "const maximum of b and c   : " << max_ad << std::endl;

	return 0;
}
