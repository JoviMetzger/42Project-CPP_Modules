#include "../header/Animal.hpp"

// Constructor
Animal::Animal()
{
	std::cout << "Animal: Default constructor called" << std::endl;
	_type = "Animal";
}

Animal::Animal(const std::string& type)
{
	std::cout << "Type constructor of Animal" << std::endl;
	_type = type;
}

// Destructor
Animal::~Animal()
{
	std::cout << "Animal: Destructor called" << std::endl;
}

// Copy constructor
Animal::Animal(const Animal& value)
{
	std::cout << "Animal: Copy constructor called" << std::endl;
	*this = value;
}

// Copy assignment operator
Animal	&Animal::operator=(const Animal& value)
{
	std::cout << "Animal: Copy assignment operator called" << std::endl;
	if (this != &value)	
		_type = value.getType();	// Perform a deep copy
	return *this;
}

// Member function
std::string	Animal::getType() const
{
	return (_type);
}
