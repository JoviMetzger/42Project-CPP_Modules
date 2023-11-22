#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "AAnimal.hpp"
# include "Brain.hpp"

// Derived class
class	Cat : public AAnimal 
{
	private:
		Brain*	_CatBrain;
	public:
		Cat();					// Default constructor
		Cat(const Cat& value);			// Copy constructor
		Cat& operator=(const Cat& value);	// Copy assignment operator
		~Cat();					// Destructor

		// Member Functions
		void	makeSound() const;
		Brain&	getBrain() const;
};

#endif
