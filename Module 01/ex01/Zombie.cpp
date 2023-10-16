#include "Zombie.hpp"

// Constructor
Zombie::Zombie()
{

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

void	Zombie::set_name(std::string name)
{
	_name = name;
}
