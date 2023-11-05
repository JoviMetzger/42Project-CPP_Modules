#include "ScavTrap.hpp"

// Default Constructor
ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap Constructor called" << std::endl;
}

// Constructor
ScavTrap::ScavTrap(std::string name)
{
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "Your ScavTrap player " << YELLOW << _name << RESET << " starts with:" << std::endl;
	std::cout << "[" << _hitPoints << "] HitPoints," <<std::endl;
	std::cout << "[" << _energyPoints << "] EnergyPoints," << std::endl;
	std::cout << "[" << _attackDamage << "] Damage." << std::endl << std::endl;
}

// Destructor
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

// Copy constructor - Used to initialize a new object
ScavTrap::ScavTrap(const ScavTrap& value)
{
	*this = value;
} 

// Copy assignment operator - Used to make a deep copy of one object
ScavTrap	&ScavTrap::operator=(const ScavTrap& value)
{
	// Perform a deep copy
	_name = value._name;
	_hitPoints = value._hitPoints;
	_energyPoints = value._energyPoints;
	_attackDamage = value._attackDamage;
	return *this;
}

void ScavTrap::guardGate()
{
    std::cout << "⚔️ ScavTrap is now in " << PURPLE << "Gate keeper" 
    << RESET << " mode!" << std::endl;
}