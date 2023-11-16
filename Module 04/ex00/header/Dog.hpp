#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"

// Derived class
class	Dog : public Animal
{
	public:
		Dog();					// Default constructor
		Dog(const Dog& value);			// Copy constructor
		Dog& operator=(const Dog& value);	// Copy assignment operator
		~Dog();					// Destructor

		// Member functions
		void    makeSound() const;
};

#endif
