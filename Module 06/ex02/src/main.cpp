#include "../header/RealType.hpp"

#include <iostream>

// COLORS
# define BLUE "\e[1;34m"
# define RESET "\033[0m"

int	main(void)
{
    // prints the actual type of the object
    std::cout << BLUE << "Testing identify(Base* p)" << RESET << std::endl;
	{
        Base* obj = generate();
        identify(obj);

        delete obj;
        std::cout << std::endl;
    }
    // prints the actual type of the object
    std::cout << BLUE << "Testing identify(Base& p)" << RESET << std::endl;
    {
        Base* obj2 = generate();
        identify(*obj2);

        delete obj2;
        std::cout << std::endl;
    }

	return (0);
} 
