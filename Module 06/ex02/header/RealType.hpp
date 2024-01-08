#ifndef REALTYPE_HPP
# define REALTYPE_HPP

# include <iostream>

class	Realtype
{
	private:
		std::string	_name;
	public:
		Realtype();									// Default constructor
		Realtype(const Realtype& value);			// Copy constructor
		Realtype& operator=(const Realtype& value);	// Copy assignment operator
		~Realtype();									// Destructor

		// Member Functions

};

#endif
