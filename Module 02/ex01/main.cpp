#include "Fixed.hpp"

int	main( void ) 
{
	Fixed	a;			// Default constructor, a is initialized to 0.0
	Fixed	const b(10);		// Constructor with an integer, b is initialized to 10.0
	Fixed	const c(42.42f);	// Constructor with a float, c is initialized to 42.42
	Fixed	const d(b);		// Copy constructor, d is initialized as a copy of b
	a = Fixed(1234.4321f);		// Assignment operator, a is assigned a new value

	std::cout << "a is " << a << std::endl;	// Output a, should be the new value
	std::cout << "b is " << b << std::endl;	// Output b, should be 10.0
	std::cout << "c is " << c << std::endl;	// Output c, should be 42.42
	std::cout << "d is " << d << std::endl;	// Output d, should be 10.0 (a copy of b)

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	std::cout << "a is " << a.toFloat() << " as Float" << std::endl;
	std::cout << "b is " << b.toFloat() << " as Float" << std::endl;
	std::cout << "c is " << c.toFloat() << " as Float" << std::endl;
	std::cout << "d is " << d.toFloat() << " as Float" << std::endl;

	return 0;
}
