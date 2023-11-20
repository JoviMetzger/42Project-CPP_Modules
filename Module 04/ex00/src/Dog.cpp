#include "../header/Dog.hpp"

// Constructor
Dog::Dog()
{
	std::cout << "Dog: Default constructor called" << std::endl;
	_type = "Dog";
}

// Destructor
Dog::~Dog()
{
	std::cout << "Dog: Destructor called" << std::endl;
}

// Copy constructor
Dog::Dog(const Dog& value)
{
	std::cout << "Dog: Copy constructor called" << std::endl; 
	*this = value;
}

// Copy assignment operator
Dog	&Dog::operator=(const Dog& value)
{
	std::cout << "Dog: Copy assignment operator called" << std::endl;
	Animal::operator=(value);
	return *this;
}

// Member Function
void	Dog::makeSound() const
{
	std::cout << "Woof Woof 🐶" << std::endl;
}
