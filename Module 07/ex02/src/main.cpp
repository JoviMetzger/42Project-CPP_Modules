#include "../header/Array.hpp"

// COLORS
# define BLUE "\e[1;34m"
# define RESET "\033[0m"

int	main()
{
	std::cout << BLUE << "Testing different the constructors" << RESET << std::endl;
	try {
		// Test cases
		Array<int> arr1; // Construction with no parameter, creates an empty array
		std::cout << "arr1 size: " << arr1.size() << std::endl;

		Array<int> arr2(5); // Constructor, creates an array of 5 elements
		std::cout << "arr2 size: " << arr2.size() << std::endl;

		arr2[3] = 42; // Accessing elements through subscript operator
		std::cout << "arr2[3]: " << arr2[3] << std::endl;
		std::cout << std::endl;

		Array<int> arr3 = arr2; // Copy constructor
		std::cout << "arr3 size: " << arr3.size() << std::endl;
		std::cout << "arr3[3]: " << arr3[3] << std::endl;
		std::cout << std::endl;

		Array<int> arr4;
		arr4 = arr2; // Assignment operator
		std::cout << "arr4 size: " << arr4.size() << std::endl;
		std::cout << "arr4[3]: " << arr4[3] << std::endl;
		std::cout << std::endl;

		// Test: Subscript operator with out-of-bounds index
		std::cout << arr2[10] << std::endl;
	} catch (const std::exception& e) {
        	std::cerr << "Exception caught: " << e.what() << std::endl;
    	}

	std::cout << BLUE << "\nTesting different arrays (int, double, char)" << RESET << std::endl;
	try {
		// Test case <int>
		Array<int> arr1;	// Construction with no parameter, creates an empty array
		std::cout << "arr1 size: " << arr1.size() << std::endl;

        	// Test case <doule>>
        	Array<double> arr2(5); // Constructor, creates an array of 5 elements
		arr2[1] = 2.2;
        	std::cout << "arr2 size: " << arr2.size() << std::endl;
		std::cout << "arr2[1]: " << arr2[1] << std::endl;
		std::cout << std::endl;

        	// Test case <char>
       		Array<char> arr4(3);
       		arr4[1] = 'X';
		std::cout << "arr4 size: " << arr4.size() << std::endl;
        	std::cout << "arr4[1]: " << arr4[1] << std::endl;

    	} catch (const std::exception& e) {
        	std::cerr << "Exception caught: " << e.what() << std::endl;
    	}
	return 0;
}
