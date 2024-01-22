#include "../header/Span.hpp"

// Default Constructor
Span::Span() : _maxSize(0), _vecNumbers(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

// Constructor
Span::Span(unsigned int N)
{
	// std::cout << "Constructor called" << std::endl;
	 _maxSize = N;
	 _vecNumbers.reserve(N);
}

// Destructor
Span::~Span()
{
	// std::cout << "Destructor called" << std::endl;
}

// Copy constructor
Span::Span(const Span& value)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = value;
}

// Assignment= operator
Span &Span::operator=(const Span& value)
{
	// std::cout << "Assignment operator called" << std::endl;
	if (this != &value)
	{
		// Perform a deep copy
		_maxSize = value._maxSize;
		_vecNumbers = value._vecNumbers;
	}
	return *this;
}

// Member function
// Adds a new number to the Span.
void Span::addNumber(int num)
{
	if (_vecNumbers.size() >= _maxSize)
		throw std::runtime_error("Span is full!");

	_vecNumbers.push_back(num);				// Adds um to the _vecNumbers vector.
}

// Finds the shortest span (difference) between any two numbers stored in the Span.
int Span::shortestSpan() const
{
	if (_vecNumbers.size() < 2)
		throw std::runtime_error("Insufficient numbers to find span!");

	std::vector<int> copyVecNum = _vecNumbers;		// Copy to avoid modifying the original vector.
	std::sort(copyVecNum.begin(), copyVecNum.end());	// Sorts in ascending order.

	int minSpan = copyVecNum[1] - copyVecNum[0];
	for (size_t i = 1; i < copyVecNum.size(); i++)
	{
		int span = copyVecNum[i] - copyVecNum[i - 1];
		minSpan = std::min(minSpan, span);		// Updates minSpan to be the minimum.
	}
	return (minSpan);
}

// This function finds the longest span (difference) between any two numbers stored in the Span.
int Span::longestSpan() const          
{
	if (_vecNumbers.size() < 2)
		throw std::runtime_error("Insufficient numbers to find span!");

	/*	//std::vector<int>::iterator result = std::minmax_element(_vecNumbers.begin(), _vecNumbers.end());
	 *	 'std::minmax_element' returns a pair of iterators, not a single iterator. 
	 *	 'auto' automatically deducted from its initializer: the return type is auto. 
	 */
	auto result = std::minmax_element(_vecNumbers.begin(), _vecNumbers.end());	// Find terators to min/max elements.
	if (result.first == _vecNumbers.end() || result.second == _vecNumbers.end())
		throw std::runtime_error("Invalid iterators returned by std::minmax_element");

	return (*result.second - *result.first);		// Returns the difference between max and min values.
}
