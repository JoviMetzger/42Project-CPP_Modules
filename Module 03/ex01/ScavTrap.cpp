#include "ScavTrap.hpp"

// Default Constructor
ScavTrap::ScavTrap()
{
	_name = "Default ScavTrap";
	_hitPoints = 100;
	_energyPoints = 50;
	_damage = 20;
	std::cout << "ScavTrap Default Constructor called" << std::endl;
}

// Constructor
ScavTrap::ScavTrap(const std::string name)
{
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_damage = 20;
	std::cout << "ScavTrap Constructor called\n" << std::endl;
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

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap& value)
{
	*this = value;
} 

// Copy assignment operator 
ScavTrap	&ScavTrap::operator=(const ScavTrap& value)
{
	ClapTrap::operator=(value);
	return *this;
}

void	ScavTrap::guardGate()
{
	if (_hitPoints == 0)
	{
		std::cout << "❌ " << _name << " can't switch into " << PURPLE 
		<< "Gate keeper" << RESET << " mode. No hit points left!" << std::endl;
	}
	else if (_energyPoints == 0)
	{
		std::cout << "❌ " << _name << " can't switch into " << PURPLE 
		<< "Gate keeper" << RESET << " mode. No energy points left!" << std::endl;
	}
	else
	{
		std::cout << "⚔️  " << _name << " is now in " << PURPLE 
		<< "Gate keeper" << RESET << " mode!" << std::endl;
	}
}
