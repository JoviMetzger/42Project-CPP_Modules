#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

// COLORS
# define RED "\e[1;91m"
# define YELLOW "\e[1;33m"
# define BLUE "\e[1;34m"
# define GREEN "\e[1;32m"
# define PURPLE "\e[0;35m"
# define L_BLUE "\e[1;36m"
# define RESET "\033[0m"

// ----- Class ------
class Zombie
{
	private:
		std::string _name;
	public:
		Zombie(std::string name);	// Constructor
		~Zombie();			// Destructor

		void	announce(void);
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif
