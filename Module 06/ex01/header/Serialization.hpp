#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

# include <iostream>

class	Serialization
{
	private:
		std::string	_name;
	public:
		Serialization();									          // Default constructor
		Serialization(const Serialization& value);					   // Copy constructor
		Serialization& operator=(const Serialization& value);		 // Copy assignment operator
		~Serialization();								          // Destructor

        // Member Function
};

#endif
