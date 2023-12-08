#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>
# include "AMateria.hpp"

class	AMateria;

/* NOTE:
 *	- ICharacter is the interface of Character
 *	- Character implements these functions 
 */
class	ICharacter
{
	public:
		virtual ~ICharacter() {};	// Destructor
		
		// Member functions
		virtual std::string const	&getName() const = 0;			// Pure virtual
		virtual void			equip(AMateria* m) = 0;			// Pure virtual
		virtual void			unequip(int idx) = 0;			// Pure virtual
		virtual void			use(int idx, ICharacter& target) = 0;	// Pure virtual
};

#endif
