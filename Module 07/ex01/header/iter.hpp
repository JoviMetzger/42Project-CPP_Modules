#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

// ---------- iter() ----------
// array: Address of an array
// lenght: Length of the array
// func: Function that will be call on every element of the array
template <typename T, typename size_t, typename Function>
void	iter(T *array, size_t lenght, Function func)
{
	for (size_t i = 0; i < lenght; ++i)
		func(array[i]);
}

// ---------- printElement() ----------
// Example func 1: Function to be used with iter
template <typename T>
void	printElement(T& element) 
{
	std::cout << element << ", ";
}

// ---------- turnIntoA() ----------
// Example func 2: Function to be used with iter
template <typename T>
void	turnIntoA(T& element) 
{
	element = 'a';
}

#endif
