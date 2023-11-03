#include "ClapTrap.hpp"

// Default Constructor
ClapTrap::ClapTrap()
{
	std::cout << "Constructor called" << std::endl;
}

// Constructor
ClapTrap::ClapTrap(std::string name): _damage(0)
{
    _name = name;
    _hitPoints = 10;
    _energyPoints = 10;
    //_damage = 0;
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

// Copy constructor - Used to initialize a new object
ClapTrap::ClapTrap(const ClapTrap& value)
{
	std::cout << "Copy constructor called" << std::endl; //RM 
	*this = value;
}

// Copy assignment operator - Used to make a deep copy of one object
ClapTrap	&ClapTrap::operator=(const ClapTrap& value)
{
	std::cout << "Copy assignment operator called " << std::endl; //RM
	// Perform a deep copy
    _name = value._name;
    _hitPoints = value._hitPoints;
    _energyPoints = value._energyPoints;
    _damage = value._damage;
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if (_hitPoints > 0 && _energyPoints > 0)
    {
        std::cout << "🤖 ClapTrap " << _name << PURPLE " attacks " << RESET 
        << target << ", cousing " << _damage << " points of damage!" << std::endl;
        _energyPoints -= 1;
    }
    else
    {
        std::cout << "❌ ClapTrap " << _name << PURPLE << " can't attack." 
        << RESET << " No hit points or energy points left!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints > 0)
    {
        _hitPoints -= amount;
        std::cout << "👊 ClapTrap " << _name << " takes " << amount 
        << " points of " << PURPLE "damage" << RESET << "!" << std::endl;
    }
    else
    {
        std::cout << "❌ ClapTrap " << _name << PURPLE << " can't take damage." 
        << RESET << " No hit points left!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints > 0 && _energyPoints > 0)
    {
        _hitPoints += amount;
        _energyPoints -= 1;
        std::cout << "♻️  ClapTrap " << _name << " is " << PURPLE << "repaired" 
        << RESET << " for " << amount << " hit points!" << std::endl;
    }
    else
    {
        std::cout << "❌ ClapTrap " << _name << PURPLE << " can't be repaired." 
        << RESET << " No hit points or energy points left!" << std::endl;
    }
}
