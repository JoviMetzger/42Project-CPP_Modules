#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

// Base class
class	WrongAnimal 
{
	protected:
		std::string	_type;
	public:
		WrongAnimal();						// Default constructor
		WrongAnimal(const WrongAnimal& value);			// Copy constructor
		WrongAnimal& operator=(const WrongAnimal& value);	// Copy assignment operator
		~WrongAnimal();						// Destructor

		// Member function
		void		makeSound() const;			// No virtual, to show the difference
		std::string	getType() const;
};

#endif
