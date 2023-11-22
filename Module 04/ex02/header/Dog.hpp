#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "AAnimal.hpp"
# include "Brain.hpp"

// Derived class
class	Dog : public AAnimal
{
	private:
		Brain*	_DogBrain;
	public:
		Dog();					// Default constructor
		Dog(const Dog& value);			// Copy constructor
		Dog& operator=(const Dog& value);	// Copy assignment operator
		~Dog();					// Destructor

		// Member Functions
		void	makeSound() const;
		Brain&	getBrain() const;
};

#endif
