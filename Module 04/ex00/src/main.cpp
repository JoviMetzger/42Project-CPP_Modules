#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// COLORS
# define BLUE "\e[1;34m"
# define RESET "\033[0m"

int	main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << std::endl;

	std::cout << BLUE << "\n ----- Testing CorrectAnimal -----" << RESET << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();		// Outputs the cat sound
	j->makeSound();		// Outputs the dog sound
	meta->makeSound();	// Outputs the animal sound

	// Testing WrongCat
	std::cout << BLUE << "\n ----- Testing WrongAnimal -----" << RESET << std::endl;
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << std::endl;

	std::cout << wrongMeta->getType() << " " << std::endl;
	std::cout << wrongCat->getType() << " " << std::endl;
	wrongCat->makeSound();	// Outputs the WrongAnimal sound
	wrongMeta->makeSound();	// Outputs the WrongAnimal sound

	// Deleting dynamically allocated objects
	std::cout << std::endl;
	delete wrongCat;
	delete wrongMeta;
	delete i;
	delete j;
	delete meta;

	return 0;
}
