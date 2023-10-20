#include "HumanB.hpp"

// Constructor
// Initializing the _weapon pointer to NULL
HumanB::HumanB(std::string name) :  _weapon(NULL)
{
	_name = name;
	std::cout << "HumanB [" << _name << "] has been created" << std::endl;
}

// Destructor
HumanB::~HumanB() 
{
	std::cout << "HumanB [" << _name << "] has been destroyed" << std::endl;
}

// setWeaopn(): assigns a weapon to HumanB
void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}

// attack(): reports the weapon used by HumanB.
void	HumanB::attack()
{
	if (_weapon != NULL)
		std::cout << "HumanB [" << _name << "] attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << "HumanB [" << _name << "] has no weapon" << std::endl;
}
