#include "Zombie.hpp"

void Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// Constructor
Zombie::Zombie(std::string name)
{
    _name = name;
}

// Destructor
Zombie::~Zombie() 
{
    std::cout << "Zombie [" << _name << "] has been destroyed." << std::endl;
}


