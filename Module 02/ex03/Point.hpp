#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class	Point
{
	private:
		Fixed const	_x;
		Fixed const	_y;
	public:
		Point();					// Default constructor
		Point(const float xValue, const float yValue);	// Constructor
		Point(const Point& value);			// Copy constructor
		Point& operator=(const Point& value);		// Copy assignment operator
		~Point();					// Destructor

		Fixed	getValueX() const;
		Fixed	getValueY() const;
};

bool	bsp(const Point a, const Point b, const Point c, const Point point);

#endif
