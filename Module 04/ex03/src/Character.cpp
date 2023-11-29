#include "../header/Character.hpp"

// Constructor
Character::Character(): _name("Default Character")
{
	std::cout << "Character: Default constructor called" << std::endl;
}

Character::Character(std::string const name): _name(name)
{
	std::cout << "Character: Constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventoryMateria[i] = 0;
}

// Destructor
Character::~Character()
{
	std::cout << "Character: Destructor called" << std::endl;
	// for (int i = 0; i < 4; i++)
	// {
	// 	if (_inventoryMateria[i])
	// 		delete _inventoryMateria[i];
	// }
}

// Copy constructor
Character::Character(const Character& value)
{
	std::cout << "Character: Copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (value._inventoryMateria[i])	// Deep copy
			_inventoryMateria[i] = value._inventoryMateria[i]->clone();
	}
}

// Copy assignment operator
Character	&Character::operator=(const Character& value)
{
	std::cout << "Character: Copy assignment operator called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_inventoryMateria[i])
			delete _inventoryMateria[i];
		if (value._inventoryMateria[i])
			_inventoryMateria[i] = value._inventoryMateria[i]->clone();
	}
	return *this;
}

// ----- Member function -----
// get's the name of your character;
std::string const &Character:: getName() const
{
	return _name;
}

// Equips the materia (inventory of 4 slots);
void Character::equip(AMateria* m)
{
	int i = 0;

	if (!m)
	{
		std::cout << "❌ " << _name << " tried to equip nothing" << std::endl;
		return ;
	}
	while (_inventoryMateria[i] != 0 && i < 4)
		i++;
	if (i >= 4)
	{
		std::cout << "❌ " << _name << " can't equip more than 4 Materia" <<std::endl;
		return ;
	}
	_inventoryMateria[i] = m;
	std::cout << "✅ " << _name << " equipped materia '" << m->getType() << "'" << std::endl;
}

// Unequips the materia (inventory of 4 slots);
void Character::unequip(int inventory_idx)
{
	if (inventory_idx < 0 || inventory_idx >= 4)
		std::cout << "❌ " << _name << " tried to unequip nothing at slot " << inventory_idx << std::endl;
	else if (!_inventoryMateria[inventory_idx])
		std::cout << "❌ " << _name << " has nothing equipped at slot " << inventory_idx << std::endl;
	else
	{
		AMateria *ptr = _inventoryMateria[inventory_idx];
		std::cout << "✅ " << _name << " unequipped " << ptr->getType() << " at slot "<< inventory_idx << std::endl;
		_inventoryMateria[inventory_idx] = 0;
	}
}

// What index of the inventory (slot of Materias) has been used 
void Character::use(int inventory_idx, ICharacter& target)
{
	if (inventory_idx < 0 || inventory_idx >= 4 || !_inventoryMateria[inventory_idx])
	{
		std::cout << "⭕ " << "Nothing found to use at index " << inventory_idx << std::endl;
		return ;
	}
	std::cout << getName();
	_inventoryMateria[inventory_idx]->use(target);
}

// gets the Materia
AMateria   *Character::getMateria(int inventory_idx)
{
    return _inventoryMateria[inventory_idx];
}