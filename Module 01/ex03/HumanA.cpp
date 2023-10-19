#include "HumanA.hpp"

// Constructor
//  In C++, when you have a reference member in a class, it must be initialized in the constructor's initializer list.
HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon)
{
	_name = name;
	_weapon = weapon;
	std::cout << "HumanA [" << _name << "] has been created." << std::endl;
	std::cout << "HumanA [" << _name << "] has weapon " << weapon.getType() << std::endl;
}

// Destructor
HumanA::~HumanA() 
{
	std::cout << "HumanA [" << _name << "] has been destroyed." << std::endl;
}

void HumanA::setWeapon(Weapon &weapon)
{
	_weapon = weapon;
}

void HumanA::attack()
{
	std::cout << "HumanA [" << _name << "] attacks with their " << _weapon.getType() << std::endl;
}
