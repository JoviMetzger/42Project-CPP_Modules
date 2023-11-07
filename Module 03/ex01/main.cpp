#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int	main()
{
	// std::string	ClapTrapName;

	// std::cout << GREEN << " - Please choose a name for your ClapTrap player -" 
	// << RESET << std::endl;
	// std::cout << GREEN << ">> " << RESET;
	// getline(std::cin, ClapTrapName);

	{
		std::cout << BLUE << BOLD << " --- TESTING CLAPTRAP ---\n" << RESET << std::endl;

		ClapTrap clapA;
		ClapTrap clapB("ClapTrapName");

		clapA.attack("CL4P-42");
		clapA.takeDamage(5);
		clapA.beRepaired(3);
		clapA.beRepaired(12);
		clapA.takeDamage(8);
		clapA.takeDamage(2);
		clapA.attack("CL4P-42");	
		clapA.beRepaired(3);
	}
	{
		std::cout << BLUE << BOLD << "\n\n --- TESTING SCAVTRAP ---\n" << RESET << std::endl;

		ScavTrap scavA;
		ScavTrap scavB("ScavTrapName");

		scavA.attack("SC4V-42");
		scavA.beRepaired(22);
		scavA.takeDamage(20);
		scavA.beRepaired(15);
		scavA.guardGate();
		scavA.attack("SC4V-42");
		scavA.takeDamage(50);
		scavA.takeDamage(30);
		scavA.attack("SC4V-42");
		std::cout << std::endl;
	}

	return (0);
}
