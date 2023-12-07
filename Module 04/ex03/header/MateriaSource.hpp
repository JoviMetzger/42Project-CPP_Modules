#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "AMateria.hpp"
# include "IMateriaSource.hpp"


/* NOTE:
 *  - IMateriaSource is the interface of MateriaSource
 *  - That's why IMateriaSource has no 'own functions', it inherits them from MateriaSource
 */
class	MateriaSource : public IMateriaSource
{
	private:
		AMateria	*(_inventoryMateria[4]);
	public:
		MateriaSource();					// Default constructor
		MateriaSource(const MateriaSource& value);		// Copy constructor
		MateriaSource& operator=(const MateriaSource& value);	// Copy assignment operator
		~MateriaSource();					// Destructor

		// Member functions
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif
