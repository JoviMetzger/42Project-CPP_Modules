#include "../header/AMateria.hpp"
#include "../header/ICharacter.hpp"
#include "../header/IceCure.hpp"
#include "../header/MateriaSource.hpp"
#include "../header/IMateriaSource.hpp"
#include "../header/Character.hpp"

// COLORS
# define BLUE "\e[1;34m"
# define RESET "\033[0m"

int main()
{
	std::cout << BLUE << " ---------- Main given in the subject ----------" RESET << std::endl;
    {
		IMateriaSource* src = new MateriaSource();

		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		
		std::cout <<std::endl;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);

		std::cout <<std::endl;
		delete bob;
		delete me;
		delete src;
	}
	std::cout << BLUE << "\n ---------- Extra test ----------" RESET << std::endl;
	{
		// Create a Character
		Character character("Alice");

		// Create Materias: Ice and Cure
		AMateria *ice = new Ice();
		AMateria *cure = new Cure();

		// Create a MateriaSource
		IMateriaSource *source = new MateriaSource();

		// Learn Materias in MateriaSource
		source->learnMateria(ice);
		source->learnMateria(cure);
		std::cout << std::endl; // --------------------->

		// Equip Materias to the Character
		character.equip(ice);
		character.equip(cure);

		// Use Materias
		ICharacter *target = new Character("Bob");
		character.use(0, *target); // Use Materia at slot 0 on Bob
		character.use(1, *target); // Use Materia at slot 1 on Bob

		// Clone a Materia using MateriaSource
		AMateria *clonedIce = source->createMateria("ice");

		// Cleanup
		std::cout << std::endl; // --------------------->
		delete target;
		delete clonedIce;
		delete source;

		// // Display Character's name
		std::cout << "Character's name: " << character.getName() << std::endl;
	}
    return 0;
}


