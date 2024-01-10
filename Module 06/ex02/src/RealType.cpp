#include "../header/RealType.hpp"

// It randomly instanciates A, B or C and returns the instance as a Base pointer.
Base *generate(void)
{
	srand(time(0)); // Need to call this before calling std::rand()

	switch ((std::rand() % 4))
	{
		case 0:
			return (new A_Class());
		case 1:
			return (new B_Class());
		case 2:
			return (new C_Class());
		default:
			return (NULL);
	}
}

// It prints the actual type of the object pointed to by p: "A", "B" or "C".
// dynamic_cast returns nullptr for pointers if the conversion is not possible (attempting to cast to an incorrect derived type).
void identify(Base* p)
{
	if (dynamic_cast<A_Class*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B_Class*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C_Class*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Wrong value!" << std::endl;
}

// It prints the actual type of the object pointed to by p: "A", "B" or "C".
// dynamic_cast throws a std::bad_cast exception for references if the conversion is not possible (attempting to cast to an incorrect derived type).
void identify(Base& p)
{
	// Class A
	try {
		(void) dynamic_cast<A_Class&>(p);
		std::cout << "A" << std::endl;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	// Class B
	try {
		(void) dynamic_cast<B_Class&>(p);
		std::cout << "B" << std::endl;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	// Class C
	try {
		(void) dynamic_cast<C_Class&>(p);
		std::cout << "C" << std::endl;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
}
