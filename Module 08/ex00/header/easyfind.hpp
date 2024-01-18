#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>

/*	- Function template to find a value in a container
	- 'T::iterator' is accessing a nested type named 'iterator' within the type 'T'
	- You use typename to indicate that the nested name is a type. This is necessary because 
	  the compiler might not know whether T::iterator is a type, a variable, or a function 
	  without the typename keyword.
*/
template <typename T>
typename	T::iterator easyfind(T& container, int value)
{
	typename T::iterator indexValue = std::find(container.begin(), container.end(), value);

	// Check if the value is found
	if (indexValue != container.end())
		return indexValue;
	else
		throw std::runtime_error("Value not found in container");
}

#endif
