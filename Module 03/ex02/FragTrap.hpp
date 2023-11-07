#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

// Derived class
class	FragTrap : public ClapTrap
{
	public:
		FragTrap();					// Default Constructor
		~FragTrap();					// Destructor
		FragTrap(const FragTrap& value);		// Copy constructor
		FragTrap& operator=(const FragTrap& value);	// Copy assignment operator

		FragTrap(const std::string name);		// Constructor

		void	highFivesGuys(void);
};

#endif
