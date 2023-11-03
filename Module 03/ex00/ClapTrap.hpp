#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

// COLORS
# define RED "\e[1;91m"
# define YELLOW "\e[1;33m"
# define BLUE "\e[1;34m"
# define GREEN "\e[1;32m"
# define PURPLE "\e[0;35m"
# define L_BLUE "\e[1;36m"
# define RESET "\033[0m"

class	ClapTrap
{
	private:
                std::string _name;
                int         _hitPoints;
                int         _energyPoints;
                int         _damage;
	public:
		ClapTrap();				        // Default Constructor
		~ClapTrap();				        // Destructor
		ClapTrap(const ClapTrap& value);		// Copy constructor
		ClapTrap& operator=(const ClapTrap& value);	// Copy assignment operator

                ClapTrap(std::string name);			// Constructor

                void attack(const std::string& target);
                void takeDamage(unsigned int amount);
                void beRepaired(unsigned int amount);
};

#endif