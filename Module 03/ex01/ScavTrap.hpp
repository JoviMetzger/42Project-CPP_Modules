#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

// Derived class
class	ScavTrap : public ClapTrap
{
	private:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
	public:
		ScavTrap();				      				// Default Constructor
		~ScavTrap();				        		// Destructor
		ScavTrap(const ScavTrap& value);			// Copy constructor
		ScavTrap& operator=(const ScavTrap& value);	// Copy assignment operator

		ScavTrap(const std::string name);					// Constructor

		void guardGate();
};

#endif
