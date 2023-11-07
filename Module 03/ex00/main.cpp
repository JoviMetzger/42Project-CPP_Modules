#include "ClapTrap.hpp"

int	main()
{
	std::string	ClapTrapName;

	std::cout << GREEN << " --- " << RESET << "Please choose a name for your player"
	<< GREEN " ---" << RESET << std::endl;
	std::cout << GREEN << ">> " << RESET;
	getline(std::cin, ClapTrapName);

	ClapTrap	clapA;		// Create a ClapTrap object
	ClapTrap	clapB(ClapTrapName);

	std::cout << std::endl;

	clapB.attack("CL4P-42");
	clapB.takeDamage(5);
	clapB.beRepaired(3);

	// Test: repairing with an amount over the max (10)
	clapB.beRepaired(12);		// ClapTrap can't be repaired

	// Test: taking more hit points
	clapB.takeDamage(8);		// ClapTrap had 8 hit points left
					// Now has 0 hit points left

	// Test: attacking when no hit points or energy points are left
	clapB.takeDamage(2);		// ClapTrap can't take damage
	clapB.attack("CL4P-42");	// ClapTrap can't attack

	// Test: repairing when no hit points or energy points are left
	clapB.beRepaired(3);		// ClapTrap can't be repaired

	std::cout << std::endl;
	return (0);
}
