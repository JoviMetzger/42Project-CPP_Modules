#include "Fixed.hpp"

// Constructor - Initializes the object's data members
Fixed::Fixed()
{
	_fixedPoint = 0;
	std::cout << "Default constructor called" << std::endl;
}

// Destructor - Used to perform cleanup operations
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Copy constructor - Used to initialize a new object
Fixed::Fixed(const Fixed& value)
{
	_fixedPoint = value._fixedPoint;
	std::cout << "Copy constructor called" << std::endl;  
}

/* Copy assignment operator - Used to make a deep copy of one object
 *  Assign one Fixed object to another using the assignment operator (=).
 *  'return *this': returns a reference, allows chain assignments (obj1 = obj2 = obj3).
 */
Fixed	&Fixed::operator=(const Fixed& value)
{
	std::cout << "Copy assignment operator called " << std::endl;
	if (this != &value)				// Check for self-assignment (obj1 = obj1)
		_fixedPoint = value.getRawBits();	// Perform a deep copy
	return *this;
}

// Return the raw value (raw bits)
int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _fixedPoint;
}

// Set the raw value (raw bits)
void	Fixed::setRawBits(int const raw)
{
	_fixedPoint = raw;
}

/*
 * - Deep Copy: Any changes made to the copied object or its internal data won't affect the original object.
 * - Shallow Copy: However, they can lead to unintended side effects, as changes in the copied object 
 *    can affect the original object and vice versa.
 */
