#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

/* NOTE:
 * - ICharacter is the interface of Character.
 * - Character implements these functions as required by the ICharacter interface.
 */
class	Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria	*(_inventoryMateria[4]);	// 4 AMateria slots at most
	public:
		Character();					// Default constructor
		Character(const Character& value);		// Copy constructor
		Character& operator=(const Character& value);	// Copy assignment operator
		~Character();					// Destructor

		Character(std::string const name);		// Constructor
		static AMateria *_floor[100];			// For storing the unequip inventory
		static int      _index;				// index for _floor array

		// Member functions
		void 			equip(AMateria* m);
		void 			unequip(int idx);
		void 			use(int idx, ICharacter& target);
		AMateria		*getMateria(int i);
		std::string const 	&getName() const;
};

#endif
