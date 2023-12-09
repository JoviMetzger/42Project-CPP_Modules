#include "../header/MateriaSource.hpp"

// Constructor
MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource: Default constructor called" << std::endl;

	// Sets all inventory slots null
	for (int i = 0; i < 4; i++)
		_inventoryMateria[i] = 0;
}

// Destructor
MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource: Destructor called" << std::endl;

	// Deletes allocated memory for each materia inventory
	for (int i = 0; i < 4; i++)
	{
		if (_inventoryMateria[i])
		{
			delete _inventoryMateria[i];
			_inventoryMateria[i] = NULL;
		}
	}
}

// Copy constructor
MateriaSource::MateriaSource(const MateriaSource& value)
{
	std::cout << "MateriaSource: Copy constructor called" << std::endl;

	// Deep copy & cloning each materia to the new character
	for (int i = 0; i < 4; i++)
	{
		if (value._inventoryMateria[i])
			_inventoryMateria[i] = value._inventoryMateria[i]->clone();
	}
}

// Copy assignment operator
MateriaSource	&MateriaSource::operator=(const MateriaSource& value)
{
	std::cout << "MateriaSource: Copy assignment operator called" << std::endl;
	if (this != &value) 
	{
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

// ----- Member function ------
// Learns/adds a new Materia (only 4)
void MateriaSource::learnMateria(AMateria* m)
{
	int i = 0;

	while (i < 4 && _inventoryMateria[i] != 0)
		i++;
	if (i >= 4)
	{
		std::cout << "❌ Can't learn more than 4 Materia" << std::endl;
		return ;
	}
	_inventoryMateria[i] = m;
	std::cout << "❇️  Materia '" << m->getType() << "' learned" << std::endl;
}

// Creates a new Materia of a specified type
AMateria* MateriaSource::createMateria(std::string const & type)
{
	int i = 0;

	while (i < 4 && (!_inventoryMateria[i] || _inventoryMateria[i]->getType() != type))
		i++;
	if (i >= 4 || !_inventoryMateria[i])
	{
		std::cout << "❌ " << type << " materia does not exist" << std::endl;
		return NULL;
	}

	// If found, creates a copy of the found materia using its clone() method and returns it
	std::cout << "🟢 Materia " << type << " created" << std::endl;
	return _inventoryMateria[i]->clone();
}
