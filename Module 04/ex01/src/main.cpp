#include "../header/Animal.hpp"
#include "../header/Dog.hpp"
#include "../header/Cat.hpp"

// COLORS
# define BLUE "\e[1;34m"
# define RESET "\033[0m"

# define NumberAnimals 6

int	main()
{
	std::cout << BLUE << " ---------- Some basic test ----------" << RESET << std::endl;
	{
		Animal	*animal[NumberAnimals];
		Brain	*brain;

		// Constructing
		std::cout << BLUE << " ----- Creatig Animals' array -----" << RESET << std::endl;
		for (int i = 0; i < NumberAnimals; i++)	// Half Dog(3), Half Cat(3)
		{
			if (i % 2 == 0)
			{
				animal[i] = new Dog();
				std::cout << "I am: " << animal[i]->getType() << std::endl;

			}
			else
			{
				animal[i] = new Cat();
				std::cout << "I am: " << animal[i]->getType() << std::endl;
			}
			std::cout << std::endl;
		}

		// Testing Brain
		std::cout << std::endl;
		std::cout << BLUE << " ----- Assigning some ideas to animal[2] -----" << RESET << std::endl;
		brain = &animal[2]->getBrain();		// Getting animal[2] brain & adding ideas to it
		brain->addIdea("Ball!!!!!", 0);
		brain->addIdea("Feed me human!", 1);

		std::cout << "First idea of animal[2]: " << brain->getIdea(0) << std::endl;
		std::cout << "Second idea of animal[2]: " << brain->getIdea(1) << std::endl;

		// Testing deep copy
		std::cout << std::endl;
		std::cout << BLUE << " ----- Assigning animal[2] to animal[3] -----" << RESET << std::endl;
		Animal *temp = animal[3];
		animal[3] = animal[2];	// Copy

		std::cout << "First idea of animal[3]: " << animal[3]->getBrain().getIdea(0) << std::endl;
		std::cout << "Second idea of animal[3]: " << animal[3]->getBrain().getIdea(1) << std::endl;
		std::cout << "Third idea of animal[3] (is empty): " 
		<< animal[5]->getBrain().getIdea(2) << std::endl;		// Won't segfault

		std::cout << std::endl;
		std::cout << "First idea of animal[2]: " << animal[2]->getBrain().getIdea(0) << std::endl;
		std::cout << "Second idea of animal[2]: " << animal[2]->getBrain().getIdea(1) << std::endl;
		std::cout << "Third idea of animal[2] (is empty): " 
		<< animal[2]->getBrain().getIdea(2) << std::endl;		// Won't segfault
		
		// Deleting every Animal
		std::cout << BLUE << "\n ----- Destructing -----" << RESET << std::endl;
		for (int i = 0; i < NumberAnimals; i++)
		{
			if (i == 3)
				continue;
			delete animal[i];
			std::cout << std::endl;
		}
		delete temp;
	}
	// Testing copy constructor & copy assignment operator
	std::cout << BLUE << "\n ---------- Testing copy constructor & copy assignment operator ----------" << RESET << std::endl;
	{
		std::cout << BLUE << " ----- Copy constructor -----" << RESET << std::endl;
		{
			std::cout << " ----- DOG -----" << std::endl;
			Dog *dogA = new Dog;
			Dog *dogB = new Dog(*dogA);	// Copy of dog
			std::cout << std::endl;

			delete dogA;
			delete dogB;
			std::cout << std::endl;

			std::cout << " ----- CAT -----" << std::endl;
			Cat *catA = new Cat;
			Cat *catB = new Cat(*catA);	// Copy of cat
			std::cout << std::endl;

			delete catA;
			delete catB;
		}
		std::cout << BLUE << " ----- Copy assignment operator overload -----" << RESET << std::endl;
		{
			std::cout << " ----- DOG -----" << std::endl;
			Dog *dogA = new Dog;
			Dog *dogB = new Dog;
			std::cout << std::endl;

			*dogA = *dogB;		// Assignment of operator for dog
			delete dogA;
			delete dogB;
			std::cout << std::endl;

			std::cout << " ----- CAT -----" << std::endl;
			Cat *catA = new Cat;
			Cat *catB = new Cat;
			std::cout << std::endl;

			*catA = *catB;		// Assignment of operator for cat
			delete catA;
			delete catB;
		}
	}
	return (0);
}
