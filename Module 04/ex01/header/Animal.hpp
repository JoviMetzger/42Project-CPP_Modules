#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

// Base class
class	Animal
{
	protected:
		std::string     _type;
	public:
		Animal();       			// Default constructor
		Animal(const Animal& value);    	// Copy constructor
		Animal& operator=(const Animal& value);	// Copy assignment operator
		virtual ~Animal();			// Destructor

		Animal(const std::string& type);

		virtual Brain	&getBrain(void) const = 0;
		std::string	getType() const;
};

#endif
