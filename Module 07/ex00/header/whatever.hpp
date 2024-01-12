#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

// ---------- Swap() ----------
template <typename T> 
void swap(T &a, T &b)	// Need to be the refrence, because you are returning nothing (void): any changes made to 'a' and 'b' inside the swap() will affect the original variables passed to the function. 
{
	T swp;

	swp = a;
	a = b;
	b = swp;
}

// ---------- Min() -----------
template <typename T> 
T min(T a, T b)
{
	if (a > b)
		return (b);
	else if (a < b)
		return (a);
	else
	{
		std::cout << "Equal";
		return (0);
	}	
}

// ---------- Max() -----------
template <typename T> 
T max(T a, T b)
{
	if (a > b)
		return (a);
	else if (a < b)
		return (b);
	else
	{
		std::cout << "Equal";
		return (0);
	}
}

#endif
