#include "Cat.hpp"

// Constructor
Cat::Cat()
{
	std::cout << "Cat: Default constructor called" << std::endl;
    _type = "Cat";
}

// Destructor
Cat::~Cat()
{
	std::cout << "Cat: Destructor called" << std::endl;
}

// Copy constructor
Cat::Cat(const Cat& value)
{
	std::cout << "Cat: Copy constructor called" << std::endl; 
	*this = value;
}

// Copy assignment operator
Cat	&Cat::operator=(const Cat& value)
{
	std::cout << "Cat: Copy assignment operator called" << std::endl;
	Animal::operator=(value);
	return *this;
}
