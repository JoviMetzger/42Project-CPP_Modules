#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class	Fixed
{
	private:
		int			_fixedPoint;
		static const int	_fractionalBits = 8;
	public:
		Fixed();				// Default constructor
		Fixed(const int intValue);		// Converts int to fixed-point value
		Fixed(const float floatValue);		// Converts float to fixed-point value
		Fixed(const Fixed& value);		// Copy constructor
		Fixed& operator=(const Fixed& value);	// Copy assignment operator
		~Fixed();				// Destructor

		// ----------- Comparison operators ----------
		bool	operator>(const Fixed value) const;		// Greater than assignment operator
		bool	operator<(const Fixed value) const;		// Less than assignment operator
		bool	operator>=(const Fixed value) const;		// Greater than or equal assignment operator
		bool	operator<=(const Fixed value) const;		// Less than or equal assignment operator
		bool	operator==(const Fixed value) const;		// Equal assignment operator
		bool	operator!=(const Fixed value) const;		// Not Equal assignment operator

		// ----------- Arithmetic operators ----------
		Fixed	operator+(const Fixed value) const;		// addition assignment operator
		Fixed	operator-(const Fixed value) const;		// Subtraction assignment operator
		Fixed	operator*(const Fixed value) const;		// Multiplication assignment operator
		Fixed	operator/(const Fixed value) const;		// Division assignment operator

		int	getRawBits( void ) const;
		float	toFloat( void ) const;
};

std::ostream &operator<<(std::ostream &o, Fixed const &fixed);

#endif
