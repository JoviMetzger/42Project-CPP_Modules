#include "ClapTrap.hpp"

// Default Constructor
ClapTrap::ClapTrap(): _name("Default ClapTrap"), _hitPoints(10), _energyPoints(10), _damage(0)
{
	std::cout << "Default Constructor called" << std::endl;
}

// Constructor
ClapTrap::ClapTrap(std::string name)
{
	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_damage = 0;
	std::cout << "Constructor called\n" << std::endl;
	std::cout << "Player " << YELLOW << _name << RESET << " starts with:" << std::endl;
	std::cout << "[" << _hitPoints << "] HitPoints," <<std::endl;
	std::cout << "[" << _energyPoints << "] EnergyPoints," << std::endl;
	std::cout << "[ " << _damage << "] Damage." << std::endl << std::endl;
}

// Destructor
ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap& value)
{
	*this = value;
}

// Copy assignment operator
ClapTrap	&ClapTrap::operator=(const ClapTrap& value)
{
	// Perform a deep copy
	_name = value._name;
	_hitPoints = value._hitPoints;
	_energyPoints = value._energyPoints;
	_damage = value._damage;
	return *this;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
	{
		std::cout << "❌ ClapTrap " << _name << PURPLE << " can't attack." 
		<< RESET << " No hit points left!" << std::endl;
	}
	else if (_energyPoints == 0)
	{
		std::cout << "❌ ClapTrap " << _name << PURPLE << " can't attack." 
		<< RESET << " No energy points left!" << std::endl;
	}
	else
	{
		std::cout << "🤖 ClapTrap " << _name << PURPLE " attacks " << RESET 
		<< target << ", cousing " << _damage << " points of damage!" << std::endl;
		_energyPoints -= 1;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > _hitPoints)
	{
		_hitPoints = 0;
		std::cout << "❌ ClapTrap " << _name << PURPLE << " can't take damage." 
		<< RESET << " No hit points left!" << std::endl;
	}
	else if(_hitPoints > 0)
	{
		_hitPoints -= amount;
		if (_hitPoints < 0) 
			_hitPoints = 0;
		std::cout << "👊 ClapTrap " << _name << " takes " << amount 
		<< " points of " << PURPLE "damage" << RESET << "!" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << "❌ ClapTrap " << _name << PURPLE << " can't be repaired." 
		<< RESET << " No hit points left!" << std::endl;
	}
	else if (_energyPoints <= 0)
	{
		std::cout << "❌ ClapTrap " << _name << PURPLE << " can't be repaired." 
		<< RESET << " No energy points left!" << std::endl;
	}
	else if (_hitPoints + amount > 10)
	{
		std::cout << "❌ ClapTrap " << _name << PURPLE << " can't be repaired." 
		<< RESET << " Reaching over maximum hit points!" << std::endl;
	}
	else
	{
		_hitPoints += amount;
		_energyPoints -= 1;
		std::cout << "♻️  ClapTrap " << _name << " is " << PURPLE << "repaired" 
		<< RESET << " for " << amount << " hit points!" << std::endl;
	}
}
