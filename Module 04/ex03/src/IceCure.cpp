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
// get the type of ice
std::string const &Ice::getType() const
{
	return _type;
}

// clone/ make a copy/ double of ice
Ice	*Ice::clone() const
{
	Ice *obj = new Ice;
	return obj;
}

// Dislayes a message that 'ice' has been used
void Ice::use(ICharacter& target)
{
	std::cout << " shoots an ice bolt at " << target.getName() << " ☄️" << std::endl;
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
std::string const &Cure::getType() const
{
	return _type;
}

// clone/ make a copy/ double of cure
Cure *Cure::clone() const
{
	Cure *obj = new Cure;
	return obj;
}

// Dislayes a message that 'cure' has been used
void Cure::use(ICharacter& target)
{
	std::cout << " heals " << target.getName() << "\'s wounds ✨" << std::endl;
}