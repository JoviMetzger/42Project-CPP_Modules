#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

// Base class
class	Animal
{
	protected:
		std::string	_type;
	public:
		Animal();				// Default constructor
		Animal(const Animal& value);		// Copy constructor
		Animal& operator=(const Animal& value);	// Copy assignment operator
		virtual ~Animal();			// Destructor: Needs virtual, because it has virtual function. 

		// Member Functions
		virtual void	makeSound() const;	// virtual, otherwise the derived class 'makeSound()' not being called.
		std::string	getType() const;
};

#endif
