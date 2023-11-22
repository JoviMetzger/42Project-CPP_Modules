#include "../header/Dog.hpp"
#include "../header/Brain.hpp"

// Constructor
Dog::Dog()
{
	std::cout << "Dog: Default constructor called" << std::endl;
	_type = "Dog";
	_DogBrain = new Brain();
}

// Destructor
Dog::~Dog()
{
	std::cout << "Dog: Destructor called" << std::endl;
	delete _DogBrain;
}

// Copy constructor
Dog::Dog(const Dog& value)
{
	std::cout << "Dog: Copy constructor called" << std::endl; 
	_DogBrain = new Brain(*value._DogBrain);	// Perform a deep copy
	*this = value;
}

// Copy assignment operator
Dog	&Dog::operator=(const Dog& value)
{
	std::cout << "Dog: Copy assignment operator called" << std::endl;
	AAnimal::operator=(value);
	return (*this);
}

// Member function
Brain&	Dog::getBrain() const
{
	return *this->_DogBrain;
}

void	Dog::makeSound() const
{
	std::cout << "Woof Woof 🐶" << std::endl;
}
