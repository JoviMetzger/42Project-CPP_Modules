#include "FragTrap.hpp"

// Default Constructor
FragTrap::FragTrap()
{
	std::cout << "FragTrap Constructor called" << std::endl;
}

// Constructor
FragTrap::FragTrap(const std::string name)
{
	_name = name;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "Your FragTrap player " << YELLOW << _name << RESET << " starts with:" << std::endl;
	std::cout << "[" << _hitPoints << "] HitPoints," <<std::endl;
	std::cout << "[" << _energyPoints << "] EnergyPoints," << std::endl;
	std::cout << "[" << _attackDamage << "] Damage." << std::endl << std::endl;
}

// Destructor
FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

// Copy constructor - Used to initialize a new object
FragTrap::FragTrap(const FragTrap& value)
{
	*this = value;
}

// Copy assignment operator - Used to make a deep copy of one object
FragTrap	&FragTrap::operator=(const FragTrap& value)
{
	// Perform a deep copy
	_name = value._name;
	_hitPoints = value._hitPoints;
	_energyPoints = value._energyPoints;
	_attackDamage = value._attackDamage;
	return *this;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "🖐️  FragTrap requests a " << PURPLE << "high five" << RESET << "! 🎊" << std::endl;
}
