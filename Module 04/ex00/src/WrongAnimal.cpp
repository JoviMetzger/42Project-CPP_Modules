#include "../header/WrongAnimal.hpp"

// Constructor
WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal: Default constructor called" << std::endl;
	_type = "WrongAnimal";
}

// Destructor
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal: Destructor called" << std::endl;
}

// Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal& value)
{
	std::cout << "WrongAnimal: Copy constructor called" << std::endl; 
	*this = value;
}

// Copy assignment operator
WrongAnimal	&WrongAnimal::operator=(const WrongAnimal& value)
{
	std::cout << "WrongAnimal: Copy assignment operator called" << std::endl;
	if (this != &value)	
		_type = value._type;	// Perform a deep copy
	return *this;
}

// Member function
void	WrongAnimal::makeSound() const 
{
	std::cout << "WrongAnimal sound" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return _type;
}
