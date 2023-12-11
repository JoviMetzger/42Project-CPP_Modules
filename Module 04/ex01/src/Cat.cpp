#include "../header/Cat.hpp"
#include "../header/Brain.hpp"

// Constructor
Cat::Cat()
{
	std::cout << "Cat: Default constructor called" << std::endl;
	_type = "Cat";
	_CatBrain = new Brain();
}

// Destructor
Cat::~Cat()
{
	std::cout << "Cat: Destructor called" << std::endl;
	delete _CatBrain;
}

// Copy constructor
Cat::Cat(const Cat& value)
{
	std::cout << "Cat: Copy constructor called" << std::endl;
	_CatBrain = new Brain(*value._CatBrain);	// Perform a deep copy
}

// Copy assignment operator
Cat	&Cat::operator=(const Cat& value)
{
	std::cout << "Cat: Copy assignment operator called" << std::endl;
	Animal::operator=(value);
	return (*this);
}

// Member function
Brain	&Cat::getBrain() const
{
	return *this->_CatBrain;
}
