#include "../header/MateriaSource.hpp"

// Constructor
MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource: Default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventoryMateria[i] = 0;
}

// Destructor
MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource: Destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		// if (_inventoryMateria[i])
		// 	delete _inventoryMateria[i];
		delete _inventoryMateria[i];
        _inventoryMateria[i] = NULL; // Ensure the pointer is null after deletion
    
	}
}

// Copy constructor
MateriaSource::MateriaSource(const MateriaSource& value)
{
	std::cout << "MateriaSource: Copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (value._inventoryMateria[i])	// deep copy
			_inventoryMateria[i] = value._inventoryMateria[i]->clone();
	}
}

// Copy assignment operator
MateriaSource	&MateriaSource::operator=(const MateriaSource& value)
{
	std::cout << "MateriaSource: Copy assignment operator called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_inventoryMateria[i])
			delete _inventoryMateria[i];
		if (value._inventoryMateria[i])
			_inventoryMateria[i] = value._inventoryMateria[i]->clone();
	}
	return *this;
}

// ----- Member function ------
// The learns the Materia (can only take 4)
void MateriaSource::learnMateria(AMateria* m)
{
	int i = 0;

	while (_inventoryMateria[i] != 0 && i < 4)
		i++;
	if (i >= 4)
	{
		std::cout << "❌ Can't learn more than 4 Materia" << std::endl;
		return ;
	}
	_inventoryMateria[i] = m;
	std::cout << "❇️  Materia '" << m->getType() << "' learned" << std::endl;
}

// Creates a new Materia
AMateria* MateriaSource::createMateria(std::string const & type)
{
    int i = 0;

	while (i < 4 && (_inventoryMateria[i] == NULL && _inventoryMateria[i]->getType() != type))
		i++;
	if (i >= 4 || !_inventoryMateria[i])
	{
		std::cout << "❌ " << type << " materia does not exist" << std::endl;
		return NULL;
	}
	std::cout << "🟢 Materia " << type << " created" << std::endl;
	// AMateria* clonedMateria = _inventoryMateria[i]->clone();
    // delete _inventoryMateria[i]; // Free the original object
    // _inventoryMateria[i] = NULL; // Set the pointer to null to avoid double deletion
    
    // return clonedMateria;
	return _inventoryMateria[i]->clone();
	
}