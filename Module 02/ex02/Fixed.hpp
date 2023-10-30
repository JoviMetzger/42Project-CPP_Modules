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
		Fixed();						// Default constructor
		~Fixed():						// Destructor
		Fixed(const int intValue);				// Converts int to fixed-point value
		Fixed(const float floatValue);				// Converts float to fixed-point value
		Fixed(const Fixed& value);				// Copy constructor
		Fixed& operator=(const Fixed& value);			// Copy assignment operator

		// ----------- Comparison operators ----------
		bool	operator>(const Fixed value) const;		// Greater than assignment operator
		bool	operator<(const Fixed value) const;		// Less than assignment operator
		bool	operator>=(const Fixed value) const;		// Greater than or equal assignment operator
		bool	operator<=(const Fixed value) const;		// Less than or equal assignment operator
		bool	operator==(const Fixed value) const;		// Equal assignment operator
		bool	operator!=(const Fixed value) const;		// Not Equal assignment operator

		// ----------- Arithmetic operators ----------
		float	operator+(const Fixed value) const;		// addition assignment operator
		float	operator-(const Fixed value) const;		// Subtraction assignment operator
		float	operator*(const Fixed value) const;		// Multiplication assignment operator
		float	operator/(const Fixed value) const;		// Division assignment operator

		// ----------- Increment/decrement operators ----------
		Fixed	operator++(void);				// Pre-Increment assignment operator (++i)
		Fixed	operator++(int);				// Post-Increment assignment operator (i++)
		Fixed	operator--(void);				// Pre-Decrement assignment operator (--i)
		Fixed	operator--(int);				// Post-Decrement assignment operator (i--)

		// ----------- Static member functions ----------
		static		Fixed& min(Fixed& value_a, Fixed& value_b);
		static const	Fixed& min(const Fixed& value_a, const Fixed& value_b);
		static		Fixed& max(Fixed& value_a, Fixed& value_b);
		static const	Fixed& max(const Fixed& value_a, const Fixed& value_b);

		// ---------- Member functions ----------
		int	getRawBits( void ) const;
		float	toFloat( void ) const;
};

std::ostream&	operator<<(std::ostream &out, Fixed const &fixed);

#endif
