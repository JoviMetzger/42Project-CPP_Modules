#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include "WrongAnimal.hpp"

// Derived class
class	WrongCat : public WrongAnimal 
{
	public:
		WrongCat();					// Default constructor
		WrongCat(const WrongCat& value);		// Copy constructor
		WrongCat& operator=(const WrongCat& value);	// Copy assignment operator
		~WrongCat();					// Destructor

		// Member function
		void	makeSound() const;
};

#endif
