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


// int main()
// {
// 	// Constructors
// 	std::cout << std::endl;
// 	std::cout << "CONSTRUCTORS:" << std::endl;
// 	std::cout << "-----------------------" << std::endl;
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	ICharacter* me = new Character("me");
// 	std::cout << std::endl;

// 	// Create Materia
// 	std::cout << "CREATE MATERIA:" << std::endl;
// 	std::cout << "-----------------------" << std::endl;
// 	AMateria	*tmp;
	
// 	AMateria	*tmp1;
// 	AMateria	*tmp2;
// 	AMateria	*tmp3;
// 	AMateria	*tmp4;

// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp1 = src->createMateria("cure");
// 	me->equip(tmp1);
// 	tmp = src->createMateria("fire"); // null
// 	me->equip(tmp);
// 	std::cout << std::endl;

// 	// Use on a new character
// 	std::cout << "USE ON A NEW CHARACTER:" << std::endl;
// 	std::cout << "-----------------------" << std::endl;
// 	ICharacter* bob = new Character("bob");
// 	me->use(0, *bob);
// 	me->use(1, *bob);
// 	std::cout << std::endl;
// 	me->use(2, *bob); // Use an empty / non existing slot in inventory
// 	me->use(-4, *bob);
// 	me->use(18, *bob);
// 	std::cout << std::endl;

// 	// Deep copy character
// 	std::cout << "DEEP COPY CHARACTER:" << std::endl;
// 	std::cout << "-----------------------" << std::endl;
// 	Character	*charles = new Character("Charles");
// 	tmp2 = src->createMateria("cure");
// 	charles->equip(tmp2);
// 	tmp3 = src->createMateria("ice");
// 	charles->equip(tmp3);
// 	tmp = src->createMateria("earth");
// 	charles->equip(tmp);
// 	Character	*charles_copy = new Character(*charles);
// 	std::cout << std::endl;

// 	// Deep copy vs its source character
// 	std::cout << "DEEP COPY VS SOURCE:" << std::endl;
// 	std::cout << "-----------------------" << std::endl;
// 	charles->unequip(0); // this shows that they have different materia pointers equipped
// 	tmp4 = charles_copy->getMateria(1);
// 	std::cout << "----- TEST -----" <<std::endl;
// 	charles_copy->unequip(1); //this will produce a leak if we don't store the address somewhere else before
// 	delete tmp4;
// 	tmp = src->createMateria("cure");
// 	charles_copy->equip(tmp);
// 	tmp = src->createMateria("ice");
// 	charles_copy->equip(tmp);
// 	std::cout << std::endl;

// 	charles->use(0, *bob);
// 	charles->use(1, *bob);
// 	charles->use(2, *bob);
// 	charles->use(3, *bob);
// 	std::cout << std::endl;
// 	charles_copy->use(0, *bob);
// 	charles_copy->use(1, *bob);
// 	charles_copy->use(2, *bob);
// 	charles_copy->use(3, *bob);
// 	std::cout << std::endl;

// 	// Unequip tests:
// 	std::cout << "UNEQUIP:" << std::endl;
// 	std::cout << "-----------------------" << std::endl;
// 	me->unequip(-1); // unequip an empty / non existing slot in inventory
// 	me->unequip(18);
// 	me->unequip(3);
// 	std::cout << std::endl;
// 	me->use(1, *charles);
// 	me->unequip(1); // Unequip a valid slot in inventory (cure unequipped)
// 	me->use(1, *charles); // try to use it
// 	std::cout << std::endl;

// 	// Destructors
// 	std::cout << "DESTRUCTORS:" << std::endl;
// 	std::cout << "-----------------------" << std::endl;
// 	delete bob;
// 	delete me;
// 	delete src;
// 	delete charles;
// 	delete charles_copy;
// 	delete tmp1;
// 	delete tmp2;
// 	std::cout << std::endl;
// }

// int main() 
// {
// 	// {
// 	// 	IMateriaSource* src = new MateriaSource();
// 	// 	src->learnMateria(new Ice());
// 	// 	src->learnMateria(new Cure());
// 	// 	ICharacter* me = new Character("me");
// 	// 	AMateria* tmp;
// 	// 	tmp = src->createMateria("ice");
// 	// 	me->equip(tmp);
// 	// 	tmp = src->createMateria("cure");
// 	// 	me->equip(tmp);
// 	// 	ICharacter* bob = new Character("bob");
// 	// 	me->use(0, *bob);
// 	// 	me->use(1, *bob);
// 	// 	std::cout << std::endl;

// 	// 	delete bob;
// 	// 	delete me;
// 	// 	delete src;
// 	// }
// 	{
// 		std::cout << "1. Create new MateriaSource and learn materias (check maximum too):" << std::endl;
// 		std::cout << std::endl; // --------------------->
//         IMateriaSource* src = new MateriaSource();
// 		src->learnMateria(new Ice());
// 		src->learnMateria(new Cure());
// 		src->learnMateria(new Ice());
// 		src->learnMateria(new Cure());
// 		AMateria *mat = new Cure();
// 		src->learnMateria(mat);
// 		std::cout << std::endl;
		
// 		std::cout << "2. Create 2 new characters and test deep copy:" << std::endl;
// 		Character *dur0 = new Character("Alice");
// 		ICharacter *dur1 = new Character(*dur0);
// 		delete dur0;
// 		delete dur1;
// 		std::cout << std::endl;

// 		std::cout << "3. Create materias and equip them (also check unknown materias):" << std::endl;
// 		AMateria* tmp;
// 		ICharacter *dur2 = new Character("Alice");
// 		tmp = src->createMateria("ice");
// 		dur2->equip(tmp);
// 		tmp = src->createMateria("cure");
// 		dur2->equip(tmp);
// 		tmp = src->createMateria("hi");
// 		dur2->equip(tmp);
// 		delete src;
// 		std::cout << std::endl;

// 		std::cout << "4. Check maximum equipped too:" << std::endl;
// 		AMateria *cure = new Cure();
// 		AMateria *ice = new Ice();
// 		dur2->equip(cure);
// 		dur2->equip(cure);
// 		dur2->equip(ice);
// 		dur2->unequip(2);
// 		delete cure; // Cure must be deleted manually when unequipped
// 		dur2->unequip(2);
// 		dur2->unequip(6);
// 		std::cout << std::endl;

// 		std::cout << "5. Use materias on new chacarter:" << std::endl;
// 		ICharacter* bob = new Character("Bob");
// 		dur2->use(0, *bob);
// 		dur2->use(1, *bob);
// 		dur2->use(2, *bob);
// 		dur2->use(6, *bob);
// 		dur2->use(-4, *bob);
// 		dur2->use(3, *bob);
// 		delete bob;
// 		std::cout << std::endl;

// 		delete dur2;

// 		return (0); 
// 	}
// }

