#include "Weapon.hpp"

// Constructor
Weapon::Weapon(std::string type)
{
	_type = type;
	std::cout << "Weapon has been created" << std::endl;
}

// Destructor
Weapon::~Weapon() 
{
	std::cout << "Weapon has been destroyed" << std::endl;
}

// getType(): retrives the weapon
const	std::string Weapon::getType()
{
	return (_type);
}

// setType(): assignes the weapon to weapon class
void	Weapon::setType(std::string type)
{
	_type = type;
}
