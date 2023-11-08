// #include "ScavTrap.hpp"
// #include "ClapTrap.hpp"
// #include "FragTrap.hpp"
#include "DiamondTrap.hpp"

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

		clapB.attack("CL4P-42");	// Attackes
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

		scavB.attack("SC4V-42");	// Attackes
		scavB.takeDamage(20);		// Takes damage 
		scavB.beRepaired(15);		// Gets repaired, has now 95 hit points
		scavB.guardGate();		// Guards gate
		scavB.attack("SC4V-42");	// Attackes
		scavB.takeDamage(95);		// Takes damage
		scavB.takeDamage(30);		// Can't take damage, has 0 hit points
		scavB.attack("SC4V-42");	// Can't attack, has 0 hit points 
		scavB.guardGate();		// Can't guards gate has 0 hit points

		std::cout << std::endl;
	}
	{
		std::cout << BLUE << BOLD << "\n\n --- TESTING FRAGTRAP ---\n" << RESET << std::endl;

		FragTrap	fragA;
		FragTrap	fragB(Name);

		fragB.attack("FR4G-42");	// Attackes
		fragB.takeDamage(20);		// Takes damage 
		fragB.beRepaired(15);		// Gets repaired, has now 95 hit points
		fragB.highFivesGuys();		// Gives High five
		fragB.attack("FR4G-42");	// Attackes
		fragB.takeDamage(95);		// Takes damage
		fragB.takeDamage(30);		// Can't take damage, has 0 hit points
		fragB.attack("FR4G-42");	// Can't attack, has 0 hit points 
		fragB.highFivesGuys();		// Can't give High five, has 0 hit points
		
		std::cout << std::endl;
	}
	{
		std::cout << BLUE << BOLD << "\n\n --- TESTING DIAMONDTRAP ---\n" << RESET << std::endl;

		DiamondTrap	diamondA;
		DiamondTrap	diamondB(Name);;

		diamondB.attack("DI4M-42");	// Attackes
		diamondB.takeDamage(20);	// Takes damage 
		diamondB.beRepaired(15);	// Gets repaired, has now 95 hit points
		diamondB.highFivesGuys();	// Gives High five
		diamondB.attack("DI4M-42");	// Attackes
		diamondB.guardGate();		// Guards gate
		diamondB.whoAmI();		// Who am I?
		diamondB.takeDamage(95);	// Takes damage
		diamondB.takeDamage(30);	// Can't take damage, has 0 hit points
		diamondB.attack("DI4M-42");	// Can't attack, has 0 hit points 
		diamondB.highFivesGuys();	// Can't give High five, has 0 hit points
		diamondB.guardGate();		// Guards gate
		
		std::cout << std::endl;
	}

	return (0);
}
