#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

// COLORS
# define YELLOW "\e[1;33m"
# define GREEN "\e[1;32m"
# define PURPLE "\e[0;35m"
# define BLUE "\033[34m"
# define BOLD "\033[1m"
# define RESET "\033[0m"

// Base class
class	ClapTrap
{
	protected:
		std::string	_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_damage;
	public:
		ClapTrap();					// Default Constructor
		~ClapTrap();					// Destructor
		ClapTrap(const ClapTrap& value);		// Copy constructor
		ClapTrap& operator=(const ClapTrap& value);	// Copy assignment operator

		ClapTrap(const std::string name);		// Constructor

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif
