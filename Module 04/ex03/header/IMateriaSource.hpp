#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <iostream>
# include "AMateria.hpp"


/* NOTE:
 *	- IMateriaSource is the interface of MateriaSource
 * 	- MateriaSource implements these functions
 */
class	IMateriaSource
{
	public:
		virtual ~IMateriaSource() {};	// Destructor
		
		// Member functions
		virtual void		learnMateria(AMateria*) = 0;			// Pure virtual
		virtual AMateria*	createMateria(std::string const & type) = 0;	// Pure virtual
};

#endif
