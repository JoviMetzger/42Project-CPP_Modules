#include "../header/RealType.hpp"

// Default Constructor
Realtype::Realtype()
{
	std::cout << "Default constructor called" << std::endl;
	_name = "Default Name";
}

// Destructor
Realtype::~Realtype()
{
	std::cout << "Destructor called" << std::endl;
}

// Copy constructor
Realtype::Realtype(const Realtype& value)
{
	std::cout << "Copy constructor called" << std::endl; 
	*this = value;
}

// Copy assignment operator
Realtype	&Realtype::operator=(const Realtype& value)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &value)	
	{
		// Perform a deep copy
		_name = value._name;
	}
	return *this;
}

// Member Function