#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <algorithm>
# include <stack>

template <class T, class Container= std::deque <T>>
class	MutantStack : public std::stack<T>
{
	private:
	public:
		// Default Constructor
		MutantStack() : std::stack<T>() {};

		// Destructor
		~MutantStack() {};

		// Copy constructor
		MutantStack(const MutantStack& value)
		{
			// std::cout << "Copy constructor called" << std::endl;
			*this = value;
		}

		// Assignment= operator
		MutantStack<T> &operator=(const MutantStack<T>& value)
		{
			// std::cout << "Assignment operator called" << std::endl;
			if (this != &value)
			{
				this->c = value.c;
			}
			return *this;
		}

		// Constructor
		MutantStack(const std::stack<T> &value) : std::stack<T>(value) {};
	
		// Member function
		/* Alias for iterator
		 * 	- Type alias iterator for the iterator type of the underlying container of std::stack<T>. 
		 *	- This is using the typename keyword to specify that container_type::iterator is a type. 
		 *	- 'container_type' A type that provides the base container to be adapted by a stack. */
		using iterator = typename std::stack<T>::container_type::iterator;

		// Iterator functions
		// 'this->c' refers to the underlying container of the inherited 'std::stack<T>'
		iterator begin()
		{
			return (this->c.begin());
		}

		iterator end()
		{
			return (this->c.end());
		}
};

#endif
