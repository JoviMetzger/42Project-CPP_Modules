#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <iostream>
# include "AMateria.hpp"


/* NOTE:
 *  - IMateriaSource is the interface of MateriaSource
 *  - That's why IMateriaSource has no 'own functions', it inherits them from MateriaSource
 */
class IMateriaSource
{
    public:
		virtual ~IMateriaSource() {};				// Destructor

        // Member functions
        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif