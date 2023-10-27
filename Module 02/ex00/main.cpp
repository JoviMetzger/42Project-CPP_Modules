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

	
	std::cout << " --------- Extra Test ---------- " << std::endl;

	// Test the default constructor
	Fixed	one;
	std::cout << BLUE << "Default construction: " << RESET << one.getRawBits() << std::endl;

	// Test the copy constructor
	Fixed	two(one);
	std::cout << BLUE << "Copy construction: " << RESET << two.getRawBits() << std::endl;

	// Test the copy assignment operator
	Fixed	tree;
	tree = two;
	tree = two = one;
	// j = j;	- will not work
	std::cout << BLUE << "Copy assignment: " << RESET << tree.getRawBits() << std::endl;

	// Test setting raw bits
	one.setRawBits(1);
	std::cout << BLUE << "Setting raw bits (Default construction)" << RESET << one.getRawBits() << std::endl;

	two.setRawBits(2);
	std::cout << BLUE << "Setting raw bits: (Copy construction)"<< RESET << two.getRawBits() << std::endl;

	tree.setRawBits(3);
	std::cout << BLUE << "Setting raw bits: (Copy assignment)" << RESET << tree.getRawBits() << std::endl;

	return 0;
}
