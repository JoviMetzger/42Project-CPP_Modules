#include "Zombie.hpp"

// Constructor
Zombie::Zombie(std::string name)
{
	_name = name;
	std::cout << "Zombie [" << _name << "] has been created." << std::endl;
}

// Destructor
Zombie::~Zombie() 
{
	std::cout << "Zombie [" << _name << "] has been destroyed." << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

