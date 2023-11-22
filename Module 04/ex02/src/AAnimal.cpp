#include "../header/AAnimal.hpp"

// Constructor
AAnimal::AAnimal()
{
	std::cout << "AAnimal: Default constructor called" << std::endl;
	_type = "AAnimal";
}

AAnimal::AAnimal(const std::string& type)
{
	std::cout << "AAnimal: Constructor called" << std::endl;
	_type = type;
}

// Destructor
AAnimal::~AAnimal()
{
	std::cout << "AAnimal: Destructor called" << std::endl;
}

// Copy constructor
AAnimal::AAnimal(const AAnimal& value)
{
	std::cout << "AAnimal: Copy constructor called" << std::endl;
	*this = value;
}

// Copy assignment operator
AAnimal	&AAnimal::operator=(const AAnimal& value)
{
	std::cout << "AAnimal: Copy assignment operator called" << std::endl;
	if (this != &value)	
		_type = value.getType();	// Perform a deep copy
	return *this;
}

// Member function
void	AAnimal::makeSound() const
{
	std::cout << "AAnimal sound" << std::endl;
}

std::string	AAnimal::getType() const
{
	return (_type);
}
