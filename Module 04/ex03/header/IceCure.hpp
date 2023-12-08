#ifndef ICECURE_HPP
# define ICECURE_HPP

# include <iostream>
# include "AMateria.hpp"

// Ice class
class	Ice : public AMateria
{
	private:
		std::string	_type;
	public:
		Ice();					// Default constructor
		Ice(const Ice& value);			// Copy constructor
		Ice& operator=(const Ice& value);	// Copy assignment operator
		~Ice();					// Destructor

		// Member functions
		Ice			*clone() const;
		void			use(ICharacter& target);
		std::string const	&getType() const; 
};

// Cure class
class	Cure : public AMateria
{
	private:
		std::string	_type;
	public:
		Cure();					// Default constructor
		Cure(const Cure& value);		// Copy constructor
		Cure& operator=(const Cure& value);	// Copy assignment operator
		~Cure();				// Destructor

		// Member functions
		Cure			*clone() const;
		void			use(ICharacter& target);
		std::string const	&getType() const;
};

#endif
