#include "HumanB.hpp"

// Constructor
HumanB::HumanB(std::string name) : _weapon(NULL)
{
	_name = name;
	std::cout << "HumanB [" << _name << "] has been created." << std::endl;
}

// Destructor
HumanB::~HumanB() 
{
	std::cout << "HumanB [" << _name << "] has been destroyed." << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	 _weapon = &weapon;
}

void HumanB::attack()
{
	std::cout << "HumanB [" << _name << "] attacks with their " << _weapon->getType() << std::endl;
}
