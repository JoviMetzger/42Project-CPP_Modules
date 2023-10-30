#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
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

		int	getRawBits( void ) const;
		int	toInt( void ) const;
		float	toFloat( void ) const;
};

std::ostream&	operator<<(std::ostream &out, Fixed const &fixed);

#endif
