#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

// Base class
class	AAnimal
{
	protected:
		std::string	_type;
	public:
		AAnimal();					// Default constructor
		AAnimal(const AAnimal& value);			// Copy constructor
		AAnimal& operator=(const AAnimal& value);	// Copy assignment operator
		virtual ~AAnimal();				// Destructor

		AAnimal(const std::string& type);

		// Member Functions
		std::string	getType() const;
		virtual void	makeSound() const;
		virtual Brain	&getBrain(void) const = 0;
};

#endif
