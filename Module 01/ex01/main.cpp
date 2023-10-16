#include "Zombie.hpp"

int	main()
{
	int	N = 5;
	
	std::cout << L_BLUE << "Creating a Zombie Hord" << RESET << std::endl;
	Zombie *horde = zombieHorde(N, "Bob");
	std::cout << L_BLUE << "Zombies Working" << RESET "\n..." <<std::endl;
	std::cout << L_BLUE << "R.I.P. Zombies" << RESET <<std::endl;
    delete[] horde;

	return 0;
}
