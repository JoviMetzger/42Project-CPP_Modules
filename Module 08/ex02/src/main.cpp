#include "../header/MutantStack.hpp"

// COLORS
# define BLUE "\e[1;34m"
# define RESET "\033[0m"

int main()
{
	std::cout << BLUE << "main() from subject" << RESET << std::endl;
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl << std::endl; // Printing the top element
		mstack.pop();
		std::cout << mstack.size() << std::endl << std::endl; // After popping an element and printing the size
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);

		// Iterating over MutantStack and printing each element
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		// Testing with std::stack
		std::stack<int> s(mstack);
		std::cout << std::endl;
	}
	std::cout << BLUE << "Testing the iterators" << RESET << std::endl;
	{
		MutantStack<int> mstack;

		mstack.push(1);
		mstack.push(2);
		mstack.push(3);
		mstack.push(4);
		mstack.push(5);

		std::cout << mstack.size() << std::endl << std::endl; // Printing the size

		// Iterating over MutantStack and printing each element
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << std::endl;

		// Printing the top element
		MutantStack<int>::iterator it_begin = mstack.begin();
		std::cout << "original top: " << *it_begin << std::endl;
		
		// Test if ++ work with iterator - printing the top element +1
		++it_begin;
		std::cout << "++ top: " << *it_begin << std::endl;

		// Test if -- work with iterator - printing the top element -1
		--it_begin;
		std::cout << "-- top: " << *it_begin << std::endl;
	}
	std::cout << BLUE << "\nTesting strings" << RESET << std::endl;
	{
		MutantStack<std::string> mstack;

		mstack.push("Gustav");
		mstack.push("Steve");
		mstack.push("Bob");
	
		std::cout << mstack.size() << std::endl << std::endl; // Printing the size

		// Iterating over MutantStack and printing each element
		MutantStack<std::string>::iterator it = mstack.begin();
		MutantStack<std::string>::iterator ite = mstack.end();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << std::endl;

		// Printing the top element
		MutantStack<std::string>::iterator it_begin = mstack.begin();
		std::cout << "original top: " << *it_begin << std::endl;

		// Test if ++ work with iterator - printing the top element +1
		++it_begin;
		std::cout << "++ top: " << *it_begin << std::endl;

		// Test if -- work with iterator - printing the top element -1
		--it_begin;
		std::cout << "-- top: " << *it_begin << std::endl;
	}

	return 0;
}

