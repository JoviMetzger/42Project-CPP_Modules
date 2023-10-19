#include "Weapon.hpp"

// Constructor
Weapon::Weapon(std::string type)
{
	_type = type;
	std::cout << "Weapon has been created." << std::endl;
}

// Destructor
Weapon::~Weapon() 
{
	std::cout << "Weapon has been destroyed." << std::endl;
}

const std::string Weapon::getType()
{
    return (_type);
}

void Weapon::setType(std::string type)
{
    _type = type;
}