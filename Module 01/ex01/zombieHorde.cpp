#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{    
    int i = -1;

    Zombie *newZombie = new Zombie[N];
    while (++i < N)
    {
        newZombie[i].set_name(name);
        newZombie[i].announce();
    }
	return (newZombie);
}
