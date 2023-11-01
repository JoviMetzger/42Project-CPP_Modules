#include "Point.hpp"

// ---------- Constructors ----------
// Constructor - Initializes the object's data members
Point::Point(): _x(0), _y(0)
{

}

// Destructor - Used to perform cleanup operations
Point::~Point()
{

}

// Copy constructor - Used to initialize a new object
Point::Point(const float xValue, const float yValue): _x(xValue), _y(yValue)
{

}

// Constructor 
Point::Point(const Point& value): _x(value.getValueX()), _y(value.getValueY())
{

}

/* Copy assignment operator - Used to make a deep copy of one object
 *	Assign one Point object to another using the assignment operator (=).
 */
Point	&Point::operator=(const Point& value)
{
	if (this != &value)
	{
		return *this;
	}
	return *this;
}

// ---------- Member Functions ----------
// Return x 
Fixed	Point::getValueX() const
{
	return _x;
}

// Returns y
Fixed	Point::getValueY() const
{
	return _y;
}
