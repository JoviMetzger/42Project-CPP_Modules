#include "../header/Character.hpp"

AMateria* Character::_floor[100] = {NULL};
int Character::_index = 0;

// Default Constructor
Character::Character()
{
	std::cout << "Character: Default constructor called" << std::endl;
	_name = "Default_Character";

	// Sets inventory slots for materia to null
	for (int i = 0; i < 4; i++)
		_inventoryMateria[i] = 0;
}

// Constructor
Character::Character(std::string const name)
{
	std::cout << "Character: Constructor called" << std::endl;
	_name = name;

	// Sets inventory slots for materia to null
	for (int i = 0; i < 4; i++)
		_inventoryMateria[i] = 0;
}

// Destructor
Character::~Character()
{
	std::cout << "Character: Destructor called" << std::endl;

	// Deletes allocated memory for each materia inventory
	for (int i = 0; i < 4; i++)
	{
		if (_inventoryMateria[i])
			delete _inventoryMateria[i];
	}
}

// Copy constructor
Character::Character(const Character& value)
{
	std::cout << "Character: Copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		// Deep copy & cloning each materia to the new character
		if (value._inventoryMateria[i])
		{
			_inventoryMateria[i] = value._inventoryMateria[i]->clone();
			_name = value._name;
		}
		else
			_inventoryMateria[i] = NULL;
	}
}

// Copy assignment operator
Character	&Character::operator=(const Character& value)
{
	std::cout << "Character: Copy assignment operator called" << std::endl;
	if (this != &value) 
	{
		_name = value._name;

		// Delete existing inventory
		for (int i = 0; i < 4; ++i) 
		{
			delete _inventoryMateria[i];
			_inventoryMateria[i] = NULL;
		}

		// Deep Copy new inventory
		for (int i = 0; i < 4; ++i) 
		{
			if (value._inventoryMateria[i])
				_inventoryMateria[i] = value._inventoryMateria[i]->clone();
			else
				_inventoryMateria[i] = NULL;
		}
	}
	return *this;
}

// ----- Member function -----
// Retrieves the name of the character
std::string const &Character:: getName() const
{
	return _name;
}

// Equips a materia to the character's inventory slots (4 slots)
void Character::equip(AMateria* m)
{
	int i = 0;

	if (!m)
	{
		std::cout << "❌ " << _name << " tried to equip nothing" << std::endl;
		return ;
	}

	while (i < 4 && _inventoryMateria[i] != 0)
		i++;

	if (i >= 4)
	{
		std::cout << "❌ " << _name << " can't equip more than 4 Materia" <<std::endl;
		return ;
	}
	_inventoryMateria[i] = m;
	std::cout << "✅ " << _name << " equipped materia '" << m->getType() << "'" << std::endl;
}

// Unequips/removes a materia from a specified inventory slot
void Character::unequip(int inventory_idx)
{
	if (inventory_idx < 0 || inventory_idx >= 4)
		std::cout << "❌ " << _name << " tried to unequip nothing at slot " << inventory_idx << std::endl;
	else if (!_inventoryMateria[inventory_idx])
		std::cout << "❌ " << _name << " has nothing equipped at slot " << inventory_idx << std::endl;
	else
	{
		 _floor[_index] = _inventoryMateria[inventory_idx];	// storing it in _floor
		std::cout << "✅ " << _name << " unequipped " << _inventoryMateria[inventory_idx]->getType() << " at slot " << inventory_idx << std::endl;
		_inventoryMateria[inventory_idx] = NULL;		// setting _inventoryMateria[inventory_idx] to NULL, because we are not allowed to delete it
	}
}

// Uses the materia present in a specified inventory slot on a target character
void Character::use(int inventory_idx, ICharacter& target)
{
	if (inventory_idx < 0 || inventory_idx >= 4)
	{
		std::cout << "❌ No Materia found to use at index " << inventory_idx << std::endl;
		return ;
	}
	if (!_inventoryMateria[inventory_idx])
	{
		std::cout << "❌ Materia at index " << inventory_idx << " is null" << std::endl;
		return ;
	}

	// Just for displaying messages
	_inventoryMateria[inventory_idx]->AMateria::use(target);	// Uses AMateria::use()
	std::cout << " at index " << inventory_idx << std::endl;
	std::cout << getName();
	_inventoryMateria[inventory_idx]->use(target);			// Uses Ice::use() OR Cure::use()
}

// Retrieves the materia present in a specified inventory slot
AMateria   *Character::getMateria(int inventory_idx)
{
	return _inventoryMateria[inventory_idx];
}
