#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

// Derived class
class	DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string	_name;
	public:
		DiamondTrap();						// Default Constructor
		~DiamondTrap();						// Destructor
		DiamondTrap(const DiamondTrap& value);			// Copy constructor
		DiamondTrap& operator=(const DiamondTrap& value);	// Copy assignment operator

		DiamondTrap(const std::string name);			// Constructor

		void	whoAmI();
		void	attack(std::string const &target);
};

#endif
