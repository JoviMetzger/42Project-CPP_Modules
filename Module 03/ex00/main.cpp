#include "ClapTrap.hpp"

int main()
{
    std::string ClapTrapName;

    std::cout << GREEN << " - Please choose a name for your player -" 
    << RESET << std::endl;
    std::cout << GREEN << ">> " << RESET;
    getline(std::cin, ClapTrapName);

    ClapTrap ClapTrap(ClapTrapName);    //Create a ClapTrap object
    ClapTrap.attack("CL4P-TP");
    ClapTrap.takeDamage(5);
    ClapTrap.beRepaired(3);
    
    return (0);
}