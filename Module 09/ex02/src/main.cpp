#include "../header/PmergeMe.hpp"

// COLORS
# define BLUE "\e[1;34m"
# define RESET "\033[0m"

int	main(int argc, char **argv)
{
	PmergeMe sort;

	(void) argc;

	try {
		// // Checks argumenta
		// checkInput(argc, argv);
	
		// Converts char** into string
		std::string str = argv[1];

		// Calculates Reverse Polish Notation
		std::vector<int> result = sort.vecJohnsonSort(str);
		// print the sorted vector
		for (int num : result)
			std::cout << num << " ";
		std::cout << std::endl;

	} catch(const std::exception& e) {
		std::cerr << RED << "Error: " << RESET <<  e.what() << std::endl;;
	}

	return 0;
}