#include "FragTrap.hpp"

// Default Constructor
FragTrap::FragTrap() : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 100;
	_damage = 30;
	std::cout << "FragTrap Default Constructor called" << std::endl;
}

// Constructor
FragTrap::FragTrap(const std::string name) : ClapTrap(name)
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

// Copy constructor - Used to initialize a new object
FragTrap::FragTrap(const FragTrap& value) : ClapTrap(value)
{
	*this = value;
}

// Copy assignment operator - Used to make a deep copy of one object
FragTrap	&FragTrap::operator=(const FragTrap& value)
{
	ClapTrap::operator=(value);
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
