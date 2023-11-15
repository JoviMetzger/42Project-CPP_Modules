#include "Animal.hpp"

// Constructor
Animal::Animal()
{
	std::cout << "Animal: Default constructor called" << std::endl;
    _type = "Animal";
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
		_type = value._type;	// Perform a deep copy
	return *this;
}

// Member Function
void Animal::makeSound() const
{
    std::cout << "Animal Sound" << std::endl;
}

std::string Animal::getType() const
{
    return (_type);
}