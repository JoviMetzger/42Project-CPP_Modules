#include "../header/AMateria.hpp"

// Constructor
AMateria::AMateria()
{
	std::cout << "AMateria: Default constructor called" << std::endl;
	_type = "Default_AMateria";
}

AMateria::AMateria(const std::string& type)
{
	std::cout << "AMateria: Constructor called" << std::endl;
	_type = type;
}

// Destructor
AMateria::~AMateria()
{
	std::cout << "AMateria: Destructor called" << std::endl;
}

// Copy constructor
AMateria::AMateria(const AMateria& value)
{
	std::cout << "AMateria: Copy constructor called" << std::endl;
	_type = value._type;
}

// Copy assignment operator
AMateria	&AMateria::operator=(const AMateria& value)
{
	std::cout << "AMateria: Copy assignment operator called" << std::endl;
	if (this != &value)
		_type = value._type;
	return *this;
}

// ----- Member function -----
// Gets the Materia type;
std::string const &AMateria::getType() const
{
	return _type;
}

// What materia is used on your Character trough the ICharacter interface;
void AMateria::use(ICharacter& target)
{
	if (_type == "ice")
		std::cout << "♻️  'ice' AMateria is being used on " << target.getName() << std::endl;
	else
		std::cout << "♻️  'cure' AMateria is being used on " << target.getName() << std::endl; 
}
