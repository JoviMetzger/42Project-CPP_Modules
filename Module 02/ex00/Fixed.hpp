#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

// COLORS
# define BLUE "\e[1;34m"
# define RESET "\033[0m"

class	Fixed
{
	private:
		int	_fixedPoint;
		static const int	_fractionalBits = 8;
	public:
		Fixed();				// Default constructor
		Fixed(const Fixed& value);		// Copy constructor
		Fixed& operator=(const Fixed& value);	// Copy assignment operator
		~Fixed();				// Destructor - used to perform cleanup operations

		int	getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif
