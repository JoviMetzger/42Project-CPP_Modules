#include "FragTrap.hpp"

// Default Constructor
FragTrap::FragTrap()
{
	_name = "Default FragTrap";
	_hitPoints = 100;
	_energyPoints = 100;
	_damage = 30;
	std::cout << "FragTrap Default Constructor called" << std::endl;
}

// Constructor
FragTrap::FragTrap(const std::string name)
{
	_name = name;
	_hitPoints = 100;
	_energyPoints = 100;
	_damage = 30;
	std::cout << "FragTrap Constructor called\n" << std::endl;
	std::cout << "Your FragTrap player " << YELLOW << _name << RESET << " starts with:" << std::endl;
	std::cout << "[" << _hitPoints << "] HitPoints," <<std::endl;
	std::cout << "[" << _energyPoints << "] EnergyPoints," << std::endl;
	std::cout << "[ " << _damage << "] Damage." << std::endl << std::endl;
}

// Destructor
FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

// Copy constructor
FragTrap::FragTrap(const FragTrap& value)
{
	*this = value;
}

// Copy assignment operator
FragTrap	&FragTrap::operator=(const FragTrap& value)
{
	// Perform a deep copy
	_name = value._name;
	_hitPoints = value._hitPoints;
	_energyPoints = value._energyPoints;
	_damage = value._damage;
	return *this;
}

void	FragTrap::highFivesGuys(void)
{
	if (_hitPoints == 0)
	{
		std::cout << "❌ " << _name << " can't give a " << PURPLE 
		<< "High five" << RESET << ". No hit points left!" << std::endl;
	}
	else if (_energyPoints == 0)
	{
		std::cout << "❌ " << _name << " can't give a " << PURPLE 
		<< "High five" << RESET << ". No energy points left!" << std::endl;
	}
	else
	{
		std::cout << "🖐️  " << PURPLE << "High five" 
		<< RESET << " alert!🎊 Let's make this moment awesome! 🎊" << std::endl;
	}
}
