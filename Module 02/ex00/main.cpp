#include "Fixed.hpp"

int	main( void )
{
	Fixed	a;
	Fixed	b( a );
	Fixed	c;
	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	
	// std::cout << " --------- Extra Test ---------- " << std::endl;
	// // Test the default constructor
	// Fixed	a;
	// std::cout << BLUE << "Default construction: " << RESET << a.getRawBits() << std::endl;

	// // Test the copy constructor
	// Fixed	b(a);
	// std::cout << BLUE << "Copy construction: " << RESET << b.getRawBits() << std::endl;

	// // Test the copy assignment operator
	// Fixed	c;
	// c = b;
	// c = b = a;
	// // d = d;	- will not work
	// std::cout << BLUE << "Copy assignment: " << RESET << c.getRawBits() << std::endl;

	// // Test setting raw bits (only takes x.0 or x)
	// a.setRawBits(1.0);
	// std::cout << BLUE << "Setting raw bits (Default construction)" << RESET << a.getRawBits() << std::endl;

	// b.setRawBits(2);
	// std::cout << BLUE << "Setting raw bits: (Copy construction)"<< RESET << b.getRawBits() << std::endl;

	// c.setRawBits(3);
	// std::cout << BLUE << "Setting raw bits: (Copy assignment)" << RESET << c.getRawBits() << std::endl;

	return 0;
}
