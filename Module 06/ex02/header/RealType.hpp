#ifndef REALTYPE_HPP
# define REALTYPE_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>

// Base class
class	Base
{
	public:
		virtual ~Base() {};	// Virtual Destructor
};

// A class
class	A_Class : public Base {};

// B class
class	B_Class : public Base {};

// C class
class	C_Class : public Base {};


// Functions
Base *generate(void);
void identify(Base* p);
void identify(Base& p);

#endif