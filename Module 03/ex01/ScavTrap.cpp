#include "ScavTrap.hpp"

// Default Constructor
ScavTrap::ScavTrap(): ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 50;
	_damage = 20;
	std::cout << "ScavTrap Constructor called" << std::endl;
}

// Constructor
ScavTrap::ScavTrap(const std::string name) : ClapTrap(name) 
{
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_damage = 20;
	std::cout << "Your ScavTrap player " << YELLOW << _name << RESET << " starts with:" << std::endl;
	std::cout << "[" << _hitPoints << "] HitPoints," <<std::endl;
	std::cout << "[ " << _energyPoints << "] EnergyPoints," << std::endl;
	std::cout << "[ " << _damage << "] Damage." << std::endl << std::endl;
}

// Destructor
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

// Copy constructor - Used to initialize a new object
ScavTrap::ScavTrap(const ScavTrap& value): ClapTrap(value)
{
	*this = value;
} 

// Copy assignment operator - Used to make a deep copy of one object
ScavTrap	&ScavTrap::operator=(const ScavTrap& value)
{
	ClapTrap::operator=(value);
	return *this;
}

void ScavTrap::guardGate()
{
	if (_hitPoints == 0)
	{
		std::cout << "❌ ScavTrap " << _name << " can't switch into " << PURPLE 
		<< "Gate keeper" << RESET << " mode. No hit points left!" << std::endl;
	}
	else
	{
		std::cout << "⚔️  ScavTrap " << _name << " is now in " << PURPLE 
		<< "Gate keeper" << RESET << " mode!" << std::endl;
	}
}