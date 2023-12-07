#include "../header/Character.hpp"

// Constructor
Character::Character()
{
	std::cout << "Character: Default constructor called" << std::endl;
	_name = "Default_Character";
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
		if (value._inventoryMateria[i])	// Deep copy
			_inventoryMateria[i] = value._inventoryMateria[i]->clone();
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

		// Delete existing _inventoryMateria
		for (int i = 0; i < 4; ++i) 
		{
			delete _inventoryMateria[i];
			_inventoryMateria[i] = NULL;
		}

		// Copy new _inventoryMateria
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
// get's the name of your character;
std::string const &Character:: getName() const
{
	return _name;
}

// Equips the materia (inventory of 4 slots);
void Character::equip(AMateria* m)
{
	if (!m)
	{
		std::cout << "❌ " << _name << " tried to equip nothing" << std::endl;
		return ;
	}

	int i = 0;
	while (i < 4 && _inventoryMateria[i] != 0)
		i++;
	if (i >= 4)
	{
		std::cout << "❌ " << _name << " can't equip more than 4 Materia" <<std::endl;
		return ;
	}
	_inventoryMateria[i] = m;
	if (_inventoryMateria[i] == NULL)
    {
        std::cout << "❌ " << _name << " attempted to equip a null pointer at slot " << i << std::endl;
        return;
    }
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
	// if (inventory_idx < 0 || inventory_idx >= 4 || !_inventoryMateria[inventory_idx])
	// {
	// 	std::cout << "❌ No Materia found to use at index " << inventory_idx << std::endl;
	// 	return ;
	// }
	// std::cout << getName(); // ----------------------> NOT displaying name -> fix

	// // Check if the pointer is valid before calling the use function
	// if (_inventoryMateria[inventory_idx])
	// {
	// 	_inventoryMateria[inventory_idx]->use(target);
	// }
	// else
	// {
	// 	std::cout << "❌ Materia at index " << inventory_idx << " is null" << std::endl;
	// }

	//--------------------------------
	// if (inventory_idx < 0 || inventory_idx >= 4 || !_inventoryMateria[inventory_idx])
    // {
    //     std::cout << "❌ No Materia found to use at index " << inventory_idx << std::endl;
    //     return;
    // }

    // if (_inventoryMateria[inventory_idx] == NULL)
    // {
    //     std::cout << "❌ Materia at index " << inventory_idx << " is null" << std::endl;
    //     return;
    // }

    // std::cout << getName() << " is using Materia at index " << inventory_idx << std::endl;
    // _inventoryMateria[inventory_idx]->use(target);

	// //-----------------------------------------
	// if (inventory_idx < 0 || inventory_idx >= 4)
    // {
    //     std::cout << "❌ Invalid index: " << inventory_idx << std::endl;
    //     return;
    // }

    // if (!_inventoryMateria[inventory_idx])
    // {
    //     std::cout << "❌ No Materia found to use at index " << inventory_idx << std::endl;
    //     return;
    // }

    // if (_inventoryMateria[inventory_idx] == NULL)
    // {
    //     std::cout << "❌ Materia at index " << inventory_idx << " is null" << std::endl;
    //     return;
    // }

    // std::cout << getName() << " is using Materia at index " << inventory_idx << std::endl;
    // _inventoryMateria[inventory_idx]->use(target);

	//-------------------------------------------------
	if (inventory_idx < 0 || inventory_idx >= 4) 
	{
        	std::cout << "❌ Invalid index: " << inventory_idx << std::endl;
       		return;
    	}
	if (!_inventoryMateria[inventory_idx])
	{
        	std::cout << "❌ No Materia found to use at index " << inventory_idx << std::endl;
        	return;
    	}

    	std::cout << getName() << " is using Materia at index " << inventory_idx << std::endl;
	_inventoryMateria[inventory_idx]->use(target);
}

// gets the Materia
AMateria   *Character::getMateria(int inventory_idx)
{
	return _inventoryMateria[inventory_idx];
}
