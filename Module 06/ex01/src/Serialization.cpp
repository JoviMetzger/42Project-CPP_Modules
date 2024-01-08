#include "../header/Serialization.hpp"

// Default Constructor
Serialization::Serialization()
{
	std::cout << "Default constructor called" << std::endl;
	_name = "Default Name";
}

// Destructor
Serialization::~Serialization()
{
	std::cout << "Destructor called" << std::endl;
}

// Copy constructor
Serialization::Serialization(const Serialization& value)
{
	std::cout << "Copy constructor called" << std::endl; 
	*this = value;
}

// Copy assignment operator
Serialization	&Serialization::operator=(const Serialization& value)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &value)	
	{
		// Perform a deep copy
		_name = value._name;
	}
	return *this;
}

// Member Functions