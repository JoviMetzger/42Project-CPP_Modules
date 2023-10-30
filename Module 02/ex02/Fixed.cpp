#include "Fixed.hpp"

// ---------- Constructors ----------
// Constructor - Initializes the object's data members
Fixed::Fixed()
{
	_fixedPoint = 0;
}

// Destructor - Used to perform cleanup operations
Fixed::~Fixed()
{

}

// Copy constructor - Used to initialize a new object
Fixed::Fixed(const Fixed& value)
{ 
	_fixedPoint = value._fixedPoint;
}

// Constructor - Converts int to fixed-point value
Fixed::Fixed(const int intValue)
{
	_fixedPoint = intValue << _fractionalBits;
}

// Constructor - Converts float to fixed-point value
Fixed::Fixed(const float floatValue)
{
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

// ----------- Comparison operators ----------
bool	Fixed::operator>(const Fixed value) const
{
	return (toFloat() > value.toFloat());
}

bool	Fixed::operator<(const Fixed value) const
{
	return (toFloat() < value.toFloat());    
}

bool	Fixed::operator>=(const Fixed value) const
{
	return (toFloat() >= value.toFloat());
}

bool	Fixed::operator<=(const Fixed value) const
{
	return (toFloat() <= value.toFloat());
}

bool	Fixed::operator==(const Fixed value) const
{
	return (toFloat() == value.toFloat());
}

bool	Fixed::operator!=(const Fixed value) const
{
	return (toFloat() != value.toFloat());
}

// ----------- Arithmetic operators ----------
float	Fixed::operator+(const Fixed value) const
{
	return (toFloat() + value.toFloat());
}

float	Fixed::operator-(const Fixed value) const
{
	return (toFloat() - value.toFloat());
}

float	Fixed::operator*(const Fixed value) const
{
	return (toFloat() * value.toFloat());
}

float	Fixed::operator/(const Fixed value) const
{
	if (value._fixedPoint != 0)
		return (toFloat() / value.toFloat());
	else
	{
		std::cout << "Undefined" << std::endl;
		return -1;
	}
}

// ----------- Increment/decrement operators ----------
// Pre-Increment assignment operator (++i)
Fixed	Fixed::operator++(void)
{
	//_fixedPoint += 1 << _fractionalBits;
	_fixedPoint++;
	return *this;
}

// Post-Increment assignment operator (i++)
Fixed	Fixed::operator++(int)
{
	Fixed temp = *this;
	++(*this);
	return temp;
}

// Pre-Decrement assignment operator (--i)
Fixed	Fixed::operator--(void)
{
	//_fixedPoint -= 1 << _fractionalBits;
	_fixedPoint--;
	return *this;
}

// Post-Decrement assignment operator (i--)
Fixed	Fixed::operator--(int)
{
	Fixed temp = *this;
	--(*this);
	return temp;
}

// ----------- Static member functions ----------
Fixed&	Fixed::min(Fixed& value_a, Fixed& value_b)
{
	if (value_a.toFloat() <= value_b.toFloat())
		return value_a;
	else
		return value_b;
}

const	Fixed& Fixed::min(const Fixed& value_a, const Fixed& value_b)
{
	if (value_a.toFloat() <= value_b.toFloat())
		return value_a;
	else
		return value_b;
}

Fixed&	Fixed::max(Fixed& value_a, Fixed& value_b)
{
	if (value_a.toFloat() >= value_b.toFloat())
		return value_a;
	else
		return value_b;
}

const	Fixed& Fixed::max(const Fixed& value_a, const Fixed& value_b)
{
	if (value_a.toFloat() >= value_b.toFloat())
		return value_a;
	else
		return value_b;
}
