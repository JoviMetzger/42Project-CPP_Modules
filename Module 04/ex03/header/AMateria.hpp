#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class   AMateria
{
    protected:
        std::string _type;
    public:
        AMateria();					// Default constructor
		AMateria(const AMateria& value);			// Copy constructor
		virtual ~AMateria();				// Destructor
		AMateria& operator=(const AMateria& value);	// Copy assignment operator // Not behing used

        AMateria(std::string const & type);
        
        // Member functions
        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif