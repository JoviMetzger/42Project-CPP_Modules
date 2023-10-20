#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class	Weapon
{
	private:
		std::string _type;
	public:
		Weapon(std::string type);	// Constructor
		~Weapon();			// Destructor

		const	std::string getType();
		void	setType(std::string type);
};

#endif
