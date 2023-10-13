#include "Zombie.hpp"

// It creates a zombie, name it, and the zombie announces itself.
void randomChump( std::string name )
{  
    Zombie *randomChump = newZombie(name);
    randomChump->announce();
    delete randomChump;
}