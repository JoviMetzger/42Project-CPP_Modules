#include "DiamondTrap.hpp"

// Default Constructor
DiamondTrap::DiamondTrap()
{
	_name = "Default DiamondTrap";
	_hitPoints = FragTrap::_hitPoints;		// 100
	_energyPoints = ScavTrap::_energyPoints;	// 50
	_damage = FragTrap::_damage;			// 30
	std::cout << "DiamondTrap Default Constructor called" << std::endl;
}

// Constructor
DiamondTrap::DiamondTrap(const std::string name)
{
	Claptrap::_name = name + "_clap_trap";
	_name = name;
	_hitPoints = FragTrap::_hitPoints;		// 100
	_energyPoints = ScavTrap::_energyPoints;	// 50
	_damage = FragTrap::_damage;			// 30
	std::cout << "DiamondTrap Constructor called\n" << std::endl;
	std::cout << "Your DiamondTrap player " << YELLOW << _name << RESET << " starts with:" << std::endl;
	std::cout << "[" << _hitPoints << "] HitPoints," <<std::endl;
	std::cout << "[ " << _energyPoints << "] EnergyPoints," << std::endl;
	std::cout << "[ " << _damage << "] Damage." << std::endl << std::endl;
}

// Destructor
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap& value)
{
	*this = value;
}

// Copy assignment operator
DiamondTrap	&DiamondTrap::operator=(const DiamondTrap& value)
{
	// Perform a deep copy
	_name = value._name;
	_hitPoints = value._hitPoints;
	_energyPoints = value._energyPoints;
	_damage = value._damage;
	return *this;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "❓ " << PURPLE << "Who am I" << RESET << "? I am " 
	<< _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}

void	DiamondTrap::attack(std::string const &target)
{
	ScavTrap::attack(target);
}
