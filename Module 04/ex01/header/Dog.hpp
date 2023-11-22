#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

// Derived class
class	Dog : public Animal
{
	private:
		Brain*	_DogBrain;
	public:
		Dog();					// Default constructor
		Dog(const Dog& value);			// Copy constructor
		Dog& operator=(const Dog& value);	// Copy assignment operator
		~Dog();					// Destructor

		Brain&	getBrain() const;
};

#endif
