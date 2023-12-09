#include "../header/AAnimal.hpp"
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
		AAnimal	*animal[NumberAnimals];
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
		AAnimal *temp = animal[3];
		animal[3] = animal[2];	// Copy

		std::cout << "First idea of animal[3]: " << animal[3]->getBrain().getIdea(0) << std::endl;
		std::cout << "Second idea of animal[3]: " << animal[3]->getBrain().getIdea(1) << std::endl;
		std::cout << "Third idea of animal[3] (is empty): " << animal[5]->getBrain().getIdea(2) << std::endl;

		std::cout << std::endl;
		std::cout << "First idea of animal[2]: " << animal[2]->getBrain().getIdea(0) << std::endl;
		std::cout << "Second idea of animal[2]: " << animal[2]->getBrain().getIdea(1) << std::endl;
		std::cout << "Third idea of animal[2] (is empty): " << animal[2]->getBrain().getIdea(2) << std::endl;

		std::cout << std::endl;
		std::cout << "First idea of animal[4]: " << animal[4]->getBrain().getIdea(0) << std::endl;
		std::cout << "Second idea of animal[4]: " << animal[4]->getBrain().getIdea(1) << std::endl;
		
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
	// Testing makSound()
	std::cout << BLUE << "\n ---------- Testing makeSound() ----------" << RESET << std::endl;
	{
		//const AAnimal* meta = new AAnimal();	// pure virtual: cannot be instantiated directly
		const AAnimal* dog = new Dog();
		const AAnimal* cat = new Cat();
		std::cout << std::endl;

		std::cout << "I am " << dog->getType() << std::endl;
		std::cout << "I am " << cat->getType() << std::endl;
		dog->makeSound();		// Outputs the dog sound
		cat->makeSound();		// Outputs the cat sound
		std::cout << std::endl;

		delete cat;
		delete dog;
	}
	return (0);
}
