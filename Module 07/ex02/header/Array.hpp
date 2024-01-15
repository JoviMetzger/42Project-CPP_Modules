#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <cstdlib>
# include <string>

template <typename T>
class	Array
{
	private:
		T* _elements;
		unsigned int _arraySize; 
	public:
		// (1): Default Constructor - with no parameter: Creates an empty array
		Array() : _elements(NULL), _arraySize(0)
		{
			// std::cout << "Default constructor called" << std::endl;
		}

		// Destructor
		~Array()
		{
			// std::cout << "Destructor called" << std::endl;
			delete[] _elements;
		}

		// (2): Constructor - Construction with an unsigned int n as a parameter
		Array(unsigned int n)
		{
			_elements = new T[n];
			_arraySize = n;
		}

		// (3): Copy constructor 
		Array(const Array& value)
		{
			std::cout << "Copy constructor called" << std::endl;
			_arraySize = value._arraySize;
			_elements = new T[_arraySize];

			for (unsigned int i = 0; i < _arraySize; i++)
				_elements[i] = value._elements[i];
		}

		// (4): Assignment= operator
		Array &operator=(const Array& value)
		{
			std::cout << "Assignment operator called" << std::endl;
			if (this != &value)
			{
				delete[] _elements; // Release existing memory
				_arraySize = value._arraySize;
				_elements = new T[_arraySize];

				for (unsigned int i = 0; i < value._arraySize; i++)
					_elements[i] = value._elements[i];
			}
			return *this;
		}

		// (5): Subscript[] operator
		T& operator[](unsigned int index)
		{
			if (index >= _arraySize)
				throw std::out_of_range("Index out of bounds");
			return _elements[index];
		}

		// (6): Member function size()
		unsigned int size() const
		{
			return _arraySize;
		}
};




#endif
