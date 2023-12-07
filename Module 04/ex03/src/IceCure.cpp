#include "../header/IceCure.hpp"

// -------------------------------------------------------------------------------
// ----------------------------------- Ice ---------------------------------------
// Constructor
Ice::Ice()
{
	std::cout << "Ice: Default constructor called" << std::endl;
	_type = "ice";
}

// Destructor
Ice::~Ice()
{
	std::cout << "Ice: Destructor called" << std::endl;
}

// Copy constructor
Ice::Ice(const Ice& value)
{
	std::cout << "Ice: Copy constructor called" << std::endl;
	_type = value._type;
}

// Copy assignment operator
Ice	&Ice::operator=(const Ice& value)
{
	std::cout << "Ice: Copy assignment operator called" << std::endl;
	if (this != &value)
		_type = value._type;
	return *this;
}

// ----- Member function -----
// clone/ make a copy/ double of ice
Ice	*Ice::clone() const
{
	return (new Ice(*this));
}

// Dislayes a message that 'ice' has been used
void Ice::use(ICharacter& target)
{
	std::cout << " shoots an ice bolt at " << target.getName() << " ☄️" << std::endl;
}

// Need this otherwise _type is getting overwritten and will always return NULL;
std::string const &Ice::getType() const
{
        return _type;
}

// -------------------------------------------------------------------------------
// ----------------------------------- Cure --------------------------------------
// Constructor
Cure::Cure()
{
	std::cout << "Cure: Default constructor called" << std::endl;
	_type = "cure";
}

// Destructor
Cure::~Cure()
{
	std::cout << "Cure: Destructor called" << std::endl;
}

// Copy constructor
Cure::Cure(const Cure& value)
{
	std::cout << "Cure: Copy constructor called" << std::endl;
	_type = value._type;
}

// Copy assignment operator
Cure	&Cure::operator=(const Cure& value)
{
	std::cout << "Cure: Copy assignment operator called" << std::endl;
	if (this != &value)
		_type = value._type;
	return *this;
}

// ----- Member function -----
// clone/ make a copy/ double of cure
Cure *Cure::clone() const
{
	return (new Cure(*this));
}

// Dislayes a message that 'cure' has been used
void Cure::use(ICharacter& target)
{
	std::cout << " heals " << target.getName() << "'s wounds ✨" << std::endl;
}

// Need this otherwise _type is getting overwritten and will always return NULL;
std::string const &Cure::getType() const
{
        return _type;
}
