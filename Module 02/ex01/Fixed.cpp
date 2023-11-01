#include "Fixed.hpp"

// ---------- Constructors ----------
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
	std::cout << "Copy constructor called" << std::endl; 
	*this = value;
}

// Constructor - Converts int to fixed-point value
Fixed::Fixed(const int intValue)
{
	std::cout << "Int constructor called" << std::endl;
	_fixedPoint = intValue << _fractionalBits;
}

// Constructor - Converts float to fixed-point value
Fixed::Fixed(const float floatValue)
{
	std::cout << "Float constructor called" << std::endl;
	_fixedPoint = roundf(floatValue * (1 << _fractionalBits));
}

// --------- Assignment Operator ---------
/* Overload of the insertion operator - Control the way Fixed objects are printed
 *	'value.toFloat()' sends the floating-point value to the output stream 'out'.
 */
std::ostream& operator<<(std::ostream& out, const Fixed& value)
{
	out << value.toFloat();
	return out;
}

/* Copy assignment operator - Used to make a deep copy of one object
 *	Assign one Fixed object to another using the assignment operator (=).
 *	'return *this': returns a reference, allows chain assignments (obj1 = obj2 = obj3).
 */
Fixed	&Fixed::operator=(const Fixed& value)
{
	std::cout << "Copy assignment operator called " << std::endl;
	if (this != &value)				// Check for self-assignment (obj1 = obj1)
		_fixedPoint = value.getRawBits();	// Perform a deep copy
	return *this;
}

// ---------- Member Functions ----------
// Return the raw value (raw bits)
int	Fixed::getRawBits() const
{
	return _fixedPoint;
}

// Returns float
float	Fixed::toFloat() const
{
	return ((float)_fixedPoint / (float)(1 << _fractionalBits));
}

// Returns int
int	Fixed::toInt() const
{
	return _fixedPoint >> _fractionalBits;
}
