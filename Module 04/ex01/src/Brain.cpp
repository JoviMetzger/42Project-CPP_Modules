#include "../header/Brain.hpp"

// Constructor
Brain::Brain()
{
	std::cout << "Brain: Default constructor called" << std::endl;
}

// Destructor
Brain::~Brain()
{
	std::cout << "Brain: Destructor called" << std::endl;
}

// Copy constructor
Brain::Brain(const Brain& value)
{
	std::cout << "Brain: Copy constructor called" << std::endl; 
	*this = value;
}

// Copy assignment operator
Brain	&Brain::operator=(const Brain& value)
{
	std::cout << "Brain: Copy assignment operator called" << std::endl;
	if (this != &value)
	{
		for (int i = 0; i < 100; i++)
			_ideas[i] = value._ideas[i];	// Perform a deep copy
	}
	return *this;
}

// Member functions
std::string	Brain::getIdea(unsigned int index) const
{
	if (index >= 0 && index < 100)
		return (this->_ideas[index]);
	return (_ideas[0]);
}

void	Brain::addIdea(std::string idea, int i)
{
	if (i >= 0 && i < 100)
		_ideas[i] = idea;
}
