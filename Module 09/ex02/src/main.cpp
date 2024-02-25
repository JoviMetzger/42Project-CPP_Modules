#include "../header/PmergeMe.hpp"

// COLORS
# define BLUE "\e[1;34m"
# define RESET "\033[0m"

int	main(int argc, char **argv)
{
	PmergeMe sort;

	(void) argc;

	try {
		// --- Checks arguments ---
		std::string str = checkInput(argc, argv);
	
		// --- Sorting algorithm ---
		clock_t	vec_startTime, vec_endTime;
		clock_t	list_startTime, list_endTime;

		// VECTOR
		vec_startTime = clock();
		std::vector<int> vecResult = sort.vecJohnsonSort(str);
		vec_endTime = clock();

		// LIST
		list_startTime = clock();
		std::list<int> listResult = sort.listJohnsonSort(str);
		list_endTime = clock();

    	// --- Printing ---
		std::cout << "Before    : " << str << std::endl;

		std::cout << "VEC After : ";
		for (int num : vecResult)
			std::cout << num << " ";
		std::cout << std::endl;
		
		std::cout << "LST After : ";
		for (int num : listResult)
			std::cout << num << " ";
		std::cout << std::endl << std::endl;

		std::cout << "VEC : Time to process a range of " << vecResult.size() << " elements with std::[..] : " << vec_endTime - vec_startTime << " us" << std::endl;
		std::cout << "LST : Time to process a range of " << listResult.size() << " elements with std::[..] : " << list_endTime - list_startTime << " us" << std::endl;
	
	} catch(const std::exception& e) {
		std::cerr << RED << "Error: " << RESET <<  e.what() << std::endl;;
	}

	return 0;
}