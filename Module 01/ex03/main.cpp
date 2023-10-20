#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

/* HumanA and HumanB are almost the same except for these two tiny details:
 *	- While HumanA takes the Weapon in its constructor, HumanB doesn’t.
 *	- HumanB may not always have a Weapon, whereas HumanA will always be armed.
*/
int	main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	std::cout << "\n --------- Extra Test ---------" << std::endl;
	{
		// Create a weapon for HumanA
		Weapon knifeA("knife");
		HumanA bob("Bob", knifeA);
	
		bob.attack();			// Test HumanA's attack with the initial weapon
		knifeA.setType("bat");	// Change the weapon type for HumanA
		bob.attack();			// Test HumanA's attack with the modified weapon

		// Create a weapon for HumanB
		Weapon knifeB("knife");
		HumanB jim("Jim");

		jim.attack();			// Test HumanB's attack without initially having a weapon
		jim.setWeapon(knifeB);	// Set a weapon for HumanB
		jim.attack();			// Test HumanB's attack with the weapon
		knifeB.setType("bat");	// Change the weapon type for HumanB
		jim.attack();			// Test HumanB's attack with the modified weapon
	}
	
	return 0;
}
