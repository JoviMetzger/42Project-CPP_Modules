#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int	main()
{
	// std::string	ClapTrapName;

	// std::cout << GREEN << " - Please choose a name for your ClapTrap player -" 
	// << RESET << std::endl;
	// std::cout << GREEN << ">> " << RESET;
	// getline(std::cin, ClapTrapName);

	// ClapTrap	claptrap("ClapTrapName");	// Create a ClapTrap object
	// std::cout << std::endl;

	// claptrap.attack("CL4P-42");
	// claptrap.takeDamage(5);
	// claptrap.beRepaired(3);

	// // Test: repairing with an amount over the max (10)
	// claptrap.beRepaired(12);		// ClapTrap can't be repaired

	// // Test: taking more hit points
	// claptrap.takeDamage(8);			// ClapTrap had 8 hit points left
	// 					            // Now has 0 hit points left

	// // Test: attacking when no hit points or energy points are left
	// claptrap.takeDamage(2);			// ClapTrap can't take damage
	// claptrap.attack("CL4P-42");		// ClapTrap can't attack

	// // Test: repairing when no hit points or energy points are left
	// claptrap.beRepaired(3);			// ClapTrap can't be repaired

	// std::cout << std::endl;

	ClapTrap claptrap("CL4P-TP");
    claptrap.attack("Bandit");

    ScavTrap scavtrap("SC4V-TP");
    scavtrap.guardGate();

	return (0);
}
