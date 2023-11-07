#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int	main()
{
	std::string	Name;

	std::cout << GREEN << " --- " << RESET << "Please choose a name for your player"
	<< GREEN << " ---" << RESET << std::endl;
	std::cout << GREEN << ">> " << RESET;
	getline(std::cin, Name);
	
	{
		std::cout << BLUE << BOLD << " --- TESTING CLAPTRAP ---\n" << RESET << std::endl;
	
		ClapTrap	clapA;
		ClapTrap	clapB(Name);

		clapB.attack("CL4P-42");	// Attckes
		clapB.takeDamage(5);		// Takes damage 
		clapB.beRepaired(3);		// Gets repaired, has now 8 hit points
		clapB.takeDamage(8);		// Takes damage of 8 hit points
		clapB.takeDamage(2);		// Can't take damage has already 0 hit points
		clapB.attack("CL4P-42");	// Can't attack, has 0 hit points
		clapB.beRepaired(3);		// can't be repaired, has 0 hit points
	}
	{
		std::cout << BLUE << BOLD << "\n\n --- TESTING SCAVTRAP ---\n" << RESET << std::endl;

		ScavTrap	scavA;
		ScavTrap	scavB(Name);

		scavB.attack("SC4V-42");	// Attckes
		scavB.takeDamage(20);		// Takes damage 
		scavB.beRepaired(15);		// Gets repaired, has now 95 hit points
		scavB.guardGate();		// Guards gate
		scavB.attack("SC4V-42");	// Attckes
		scavB.takeDamage(95);		// Takes damage
		scavB.takeDamage(30);		// Can't take damage, has 0 hit points
		scavB.attack("SC4V-42");	// Can't attack, has 0 hit points 
		scavB.guardGate();		// Can't guards gate has 0 hit points
		
		std::cout << std::endl;
	}

	return (0);
}
