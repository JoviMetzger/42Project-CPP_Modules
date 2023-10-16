#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

// COLORS
# define L_BLUE "\e[1;36m"
# define RESET "\033[0m"

// Class
class	Zombie
{
	private:
		std::string _name;
	public:
		Zombie();	// Constructor
		~Zombie();	// Destructor

		void	announce(void);
		void	set_name(std::string name);
};

Zombie*	zombieHorde( int N, std::string name );

#endif
