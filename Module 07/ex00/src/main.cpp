#include "../header/whatever.hpp"

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

// ---------- Main() ----------
int main( void ) 
{
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::cout << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	std::cout << std::endl;

	char j = 'w';
	char k = 'w';

	::swap(j, k);
	std::cout << "j = " << j << ", k = " << k << std::endl;
	std::cout << "min( j, k ) = " << ::min( j, k ) << std::endl;
	std::cout << "max( j, k ) = " << ::max( j, k ) << std::endl;

	return 0;
}
