#include "../header/RealType.hpp"

// Destructor
Base::~Base()
{
	std::cout << "Destructor called" << std::endl;
}

// It randomly instanciates A, B or C and returns the instance as a Base pointer.
Base *generate(void)
{
	srand(static_cast<unsigned int>(time(NULL)));
	int random_num = rand() % 3;

	switch (random_num)
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
void identify(Base* p)
{
	if (dynamic_cast<A_Class*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B_Class*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C_Class*>(p))
		std::cout << "C" << std::endl;
}

// It prints the actual type of the object pointed to by p: "A", "B" or "C".
void identify(Base& p)
{
	identify(&p); // Calls the pointer version
}
