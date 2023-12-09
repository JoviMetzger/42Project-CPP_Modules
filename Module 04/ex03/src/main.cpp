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
		std::cout << std::endl;

		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		std::cout << std::endl;

		ICharacter* me = new Character("me");
		std::cout << std::endl; 
		
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		std::cout << std::endl;

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		std::cout << std::endl;
		delete bob;
		delete me;
		delete src;
	}
	std::cout << BLUE << "\n\n -------------------- Extra Test -------------------- \n" RESET << std::endl;
	{
		// Constructors
		std::cout << BLUE << " ---------- CONSTRUCTORS ----------" << RESET << std::endl;
		IMateriaSource* src = new MateriaSource();
		ICharacter* frank = new Character("Frank");
		std::cout << std::endl;

		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		std::cout << std::endl;

		// Create Materia
		std::cout << BLUE << "\n ---------- CREATE MATERIA ----------" << RESET << std::endl;

		AMateria *tmp = src->createMateria("ice");
		frank->equip(tmp);
		std::cout << std::endl;

		AMateria *tmp1 = src->createMateria("cure");
		frank->equip(tmp1);
		std::cout << std::endl;

		tmp = src->createMateria("fire");	// wrong Materia
		frank->equip(tmp);
		std::cout << std::endl;

		// Use Materia
		std::cout << BLUE << "\n ---------- USE MATERIA ----------" << RESET << std::endl;
		ICharacter* bob = new Character("Bob");
		std::cout << std::endl;

		frank->use(0, *bob);
		frank->use(1, *bob);
		frank->use(2, *bob);			// Use an empty slot
		frank->use(-4, *bob);			// Use an non existing slot in inventory
		frank->use(18, *bob);			// Use an non existing slot in inventory
		std::cout << std::endl;

		// Deep copy
		std::cout << BLUE << "\n ---------- DEEP COPY ----------" << RESET << std::endl;
		std::cout << " ----- Creating a new character -----" << std::endl;

		// Creating a new Character + creating materia
		Character	*mia = new Character("Mia");
		std::cout << std::endl;

		AMateria *tmp2 = src->createMateria("cure");
		mia->equip(tmp2);
		std::cout << std::endl;

		AMateria *tmp3 = src->createMateria("ice");
		mia->equip(tmp3);
		std::cout << std::endl;

		tmp = src->createMateria("earth");	// wrong Materia
		mia->equip(tmp);
		std::cout << std::endl;

		// Testing Copy Constructor
		Character	*mia_copy = new Character(*mia);
		std::cout << std::endl;

		// Testing the deep copy with its original source character
		std::cout << "\n ----- Testing the deep copy with its original source character -----" << std::endl;
		AMateria *tmp4 = mia_copy->getMateria(1);
		mia->unequip(0);			// this shows that they have different materia pointers equipped
		mia_copy->unequip(1);
		std::cout << std::endl;

		tmp = src->createMateria("cure");
		mia_copy->equip(tmp);
		std::cout << std::endl;

		tmp = src->createMateria("ice");
		mia_copy->equip(tmp);
		std::cout << std::endl;

		mia->use(0, *bob);			// empty, because we unequip it above
		mia->use(1, *bob); 
		mia->use(2, *bob);
		mia->use(3, *bob);
		std::cout << std::endl;

		mia_copy->use(0, *bob);
		mia_copy->use(1, *bob);
		mia_copy->use(2, *bob);
		mia_copy->use(3, *bob);
		std::cout << std::endl;

		// Unequip
		std::cout << BLUE << "\n ---------- UNEQUIP ----------" << RESET << std::endl;
		frank->unequip(-1);			// non existing slot in inventory
		frank->unequip(18);			// non existing slot in inventory
		frank->unequip(3);			// unequip an empty
		std::cout << std::endl;

		frank->use(1, *mia);
		frank->unequip(1);			// Unequip a valid slot
		frank->use(1, *mia);			// try to use it
		std::cout << std::endl;

		// Destructors
		std::cout << BLUE << "\n ---------- DESTRUCTORS ----------" << RESET << std::endl;
		delete tmp4;
		delete tmp2;
		delete tmp1;
		delete mia_copy;
		delete mia;
		delete bob;
		delete frank;
		delete src;
	}
}
