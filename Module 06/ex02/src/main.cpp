#include "../header/RealType.hpp"

#include <iostream>

// COLORS
# define BLUE "\e[1;34m"
# define RESET "\033[0m"

int	main(void)
{
	Base* obj = generate();
	identify(obj);

	Base* obj2 = generate();
	identify(*obj2);

	delete obj;
	delete obj2;

	return (0);
} 
