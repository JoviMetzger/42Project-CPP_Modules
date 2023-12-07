#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>
# include "AMateria.hpp"

class	AMateria;

/* NOTE:
 *  - ICharacter is the interface of Character
 *  - That's why ICharacter has no 'own functions', it inherits them from Character
 */
class	ICharacter
{
	public:
		virtual ~ICharacter() {};	// Destructor
		
		// Member functions
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif
