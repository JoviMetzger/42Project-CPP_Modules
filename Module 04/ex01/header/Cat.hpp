#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

// Derived class
class	Cat : public Animal 
{
	private:
		Brain*	_CatBrain;
	public:
		Cat();					// Default constructor
		Cat(const Cat& value);			// Copy constructor
		Cat& operator=(const Cat& value);	// Copy assignment operator
		~Cat();					// Destructor

		Brain&	getBrain() const;
};

#endif
