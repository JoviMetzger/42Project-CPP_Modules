# include "../header/WrongCat.hpp"

// Constructor
WrongCat::WrongCat()
{
	std::cout << "WrongCat: Default constructor called" << std::endl;
	_type = "WrongCat";
}

// Destructor
WrongCat::~WrongCat()
{
	std::cout << "WrongCat: Destructor called" << std::endl;
}

// Copy constructor
WrongCat::WrongCat(const WrongCat& value)
{
	std::cout << "WrongCat: Copy constructor called" << std::endl; 
	*this = value;
}

// Copy assignment operator
WrongCat	&WrongCat::operator=(const WrongCat& value)
{
	std::cout << "WrongCat: Copy assignment operator called" << std::endl;
	if (this != &value)	
		_type = value._type;	// Perform a deep copy
	return *this;
}

// Member Function
void	WrongCat::makeSound() const 
{
	std::cout << "WrongCat sound ✖️" << std::endl;
}
