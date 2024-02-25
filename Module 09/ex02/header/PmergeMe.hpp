#ifndef PMEGREME_HPP
# define PMEGREME_HPP

# include <iostream>
# include <algorithm>
# include <sstream>
# include <chrono>
# include <vector>
# include <list>


// COLORS
# define RED "\e[1;91m"
# define RESET "\033[0m"

class	PmergeMe
{
	public:
		PmergeMe();					// Default constructor
		PmergeMe(const PmergeMe& value);		// Copy constructor
		PmergeMe& operator=(const PmergeMe& value);	// Copy assignment operator
		~PmergeMe();					// Destructor

		// Member functions
		std::vector<int> vecJohnsonSort(const std::string& str);
		std::list<int> listJohnsonSort(const std::string& str);


};
std::string checkInput(int argc, char **argv);


#endif