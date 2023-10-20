#include "HumanA.hpp"

// Constructor
// In C++, when you have a reference member in a class, it must be initialized in the constructor's initializer list.
HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon)
{
	_name = name;
	std::cout << "HumanA [" << _name << "] has been created" << std::endl;
}

// Destructor
HumanA::~HumanA() 
{
	std::cout << "HumanA [" << _name << "] has been destroyed" << std::endl;
}

// attack(): reports the weapon used by HumanA
void	HumanA::attack()
{
	std::cout << "HumanA [" << _name << "] attacks with their " << _weapon.getType() << std::endl;
}
