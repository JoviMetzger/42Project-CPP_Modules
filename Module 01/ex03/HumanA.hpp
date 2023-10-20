#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class	HumanA
{
	private:
		std::string _name;
		Weapon &_weapon;				// reference weapon: is designed to always have a weapon.
	public:
		HumanA(std::string name, Weapon &weapon);	// Constructor
		~HumanA();					// Destructor

		void	attack();
};

#endif
