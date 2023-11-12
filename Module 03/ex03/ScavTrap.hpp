#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

// Derived class
class	ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap();					// Default Constructor
		~ScavTrap();					// Destructor
		ScavTrap(const ScavTrap& value);		// Copy constructor
		ScavTrap& operator=(const ScavTrap& value);	// Copy assignment operator

		ScavTrap(const std::string name);		// Constructor

		void	guardGate();
};

#endif
