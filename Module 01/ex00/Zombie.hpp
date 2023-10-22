#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

// COLORS
# define L_BLUE "\e[1;36m"
# define RESET "\033[0m"

// Class
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
