#include "../header/PmergeMe.hpp"

// Default Constructor
PmergeMe::PmergeMe()
{
	std::cout << "Default constructor called" << std::endl;
}

// Destructor
PmergeMe::~PmergeMe()
{
	std::cout << "Destructor called" << std::endl;
}

// Copy constructor
PmergeMe::PmergeMe(const PmergeMe& value)
{
	std::cout << "Copy constructor called" << std::endl; 
	*this = value;
}

// Copy assignment operator
PmergeMe	&PmergeMe::operator=(const PmergeMe& value)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &value) {}
	return *this;
}

//------------------------------------------------------------------------------
// --- Member function ---
// Compares two pairs of integers based on their first elements
bool	comparePairs(const std::pair<int, int> &pair1, const std::pair<int, int> &pair2) 
{
	return (pair1.first < pair2.first);
}

// Compute the n-th term in the Jacobsthal sequence based on the previous two terms, following the defined recurrence relation.
int		jacobsthalSequence(int n)
{
	// Base Cases 0 & 1
	if (n == 0)		// 0th term in the Jacobsthal sequence is 0
		return (0);
	if (n == 1)		// 1st term in the Jacobsthal sequence is 1
		return (1);

	// Recurrence Relation
	int prev = 0;		// Previous term ('J(n-2)')
	int current = 1;	// Current term ('J(n-1)')
	for (int i = 2; i < n; ++i)
	{
		// Calculates the next term in the sequence using the Jacobsthal sequence
		int next = current + 2 *prev;	// ('J(n) = J(n-1) + 2 * J(n-2)')
		prev = current;
		current = next;
	}
	return (current);	// Return the n-th term in the Jacobsthal sequence
}

//------------------------------------------------------------------------------
// VECTOR
//------------------------------------------------------------------------------
// Recursive function to sort pairs
void	vecRecursivePairSort(std::vector<std::pair<int, int>> &pairs, size_t startIdx) 
{
	// If 'startIdx' reaches the last index, the vector is sorted
	if (startIdx == pairs.size() - 1)
		return ;

	for (size_t it = startIdx + 1; it < pairs.size(); ++it) 
	{
		// Compare the pair at 'startIdx' with the current pair at index 'it'
		if (!comparePairs(pairs[startIdx], pairs[it]))
			std::swap(pairs[startIdx], pairs[it]);
	}
	// Recursively sort the remaining elements of the vector
	vecRecursivePairSort(pairs, startIdx + 1);
}

// Searches for the appropriate position to insert a value into a sorted vector (main_chain) of integers.
void	vecBinarySearch(std::vector<int>& main_chain, int start, int len, int value)
{
	if (start == len || start >= len)
	{
		// insert the value at the specified start index and return.
		main_chain.insert(main_chain.begin() + start, value);
		return ;
	}

	// Calculate the mid index of the range.
	int mid = start + (len - start) / 2;
	
	if (main_chain[mid] < value)					// If the middle element is less than the value,
		vecBinarySearch(main_chain, mid + 1, len, value);	// search the upper half of the range.
	else if (main_chain[mid] > value)				// If the middle element is greater than the value,
		vecBinarySearch(main_chain, start, mid, value);		// search the lower half of the range.
	else								// If the middle element is equal to the value,
	{
		main_chain.insert(main_chain.begin() + mid, value);	// insert the value at the mid index.
		return ;
	}
}

// Ford-Johnson-Sort for vector
std::vector<int>	PmergeMe::vecJohnsonSort(const std::string& str)
{
	std::vector<int> x;
	std::istringstream iss(str);

	// Parse the string to extract integers
	int num;
	while (iss >> num)
		x.push_back(num);

	// Step 1: Handle a possible remaining element if the size of x is odd
	int struggler = -1;

	if  (x.size() % 2 != 0)
	{
		struggler = x.back();
		x.pop_back();
	}

	// Step 2: Group elements to pairs & determine larger elements of each pair
	int n = x.size();
	std::vector<std::pair<int, int>> pairs;
	for (int i = 0; i < n; i += 2)
	{
		int first = x[i];
		int second = x[i + 1];
		pairs.push_back(std::make_pair(std::max(first, second), std::min(first, second))); // make pair and put lager element first
	}

		// // Print pairs
		// std::cout << "\n-------------------------------------------------" << std::endl;
		// std::cout << "Pairs: ";
		// for (const auto& pair : pairs)
		// 	std::cout << "(" << pair.first << ", " << pair.second << ")";
		// std::cout << std::endl << std::endl;
		// std::cout << "-------------------------------------------------" << std::endl;

	// Step 3: Recursively sort larger elements from each pair
	size_t startIdx = 0;
	vecRecursivePairSort(pairs, startIdx);

		// // Print sorted pairs
		// std::cout << "Sorted Pairs: ";
		// for (const auto& pair : pairs) 
		// 	std::cout << "(" << pair.first << ", " << pair.second << ") ";
		// std::cout << std::endl << std::endl;
		// std::cout << "-------------------------------------------------" << std::endl;

	// Step 4: Create main_chain and pend
	std::vector<int> main_chain;
    std::vector<int> pend;

    for (const auto& pair : pairs) 
	{
        main_chain.push_back(pair.first);	// main_chain: first element of the pair
        pend.push_back(pair.second);		// pend: second element of the pair
    }

		// // Print main_chain elements & print pend elements
		// std::cout << "main_chain: ";
		// for (const auto& element : main_chain)
		// 	std::cout << element << " ";
		// std::cout << std::endl;

		// std::cout << "pend: ";
		// for (const auto& element : pend)
		// 	std::cout << element << " ";
		// std::cout << std::endl << std::endl;
		// std::cout << "-------------------------------------------------" << std::endl;


	// Step 5: Generate order of insertion using Jacobsthal sequence
	int i = 1;
    int k = 1;
    int pendSize = pend.size();
       
    main_chain.insert(main_chain.begin(), pend.front());

    while (i < pendSize)
    {
        for (int j = jacobsthalSequence(k); j > 0 && j > jacobsthalSequence(k - 1); --j)
        {
            auto it = pend.begin();
            if (j >= pendSize)
                j = pendSize - 1;
            std::advance(it, j);

			// Step 6: Use binary search for insertion positions
            vecBinarySearch(main_chain, 0, main_chain.size(), *it);
            ++i;
        }
        ++k;
    }
	
	// Step 7: Insert the struggler
	if (struggler != -1)
		vecBinarySearch(main_chain, 0, main_chain.size(), struggler);

	return main_chain;	// Return sorted vector
}

//------------------------------------------------------------------------------
// LIST
//------------------------------------------------------------------------------
// Recursive function to sort pairs
void	listRecursivePairSort(std::list<std::pair<int, int>> &pairs, std::list<std::pair<int, int>>::iterator startIdx) 
{
	// If 'startIdx' reaches the last index, the list is sorted
	if (startIdx == std::prev(pairs.end()))
		return ;

	for (std::list<std::pair<int, int>>::iterator it = std::next(startIdx); it != pairs.end(); ++it) 
	{
		// Compare the pair at 'startIdx' with the current pair at index 'it'
		if (!comparePairs(*startIdx, *it))
			std::iter_swap(startIdx, it);
	}
	// Recursively sort the remaining elements of the list
	listRecursivePairSort(pairs, std::next(startIdx));
}

// Searches for the appropriate position to insert a value into a sorted list (main_chain) of integers.
void	listBinarySearch(std::list<int>& main_chain, std::list<int>::iterator start, std::list<int>::iterator len, int value)
{
	if (start == len || *start >= value)
	{
		// insert the value at the specified start index and return.
		main_chain.insert(start, value);
		return ;
	}

	// Calculate the mid index of the range.
	auto mid = std::next(start, std::distance(start, len) / 2);
	
	if (*mid < value)							// If the middle element is less than the value,
		listBinarySearch(main_chain, std::next(mid), len, value);	// search the upper half of the range.
	else if (*mid > value)							// If the middle element is greater than the value,
		listBinarySearch(main_chain, start, mid, value);		// search the lower half of the range.
	else									// If the middle element is equal to the value,
	{
		main_chain.insert(mid, value);					// insert the value at the mid index.
		return ;
	}
}

// Ford-Johnson-Sort for list
std::list<int>	PmergeMe::listJohnsonSort(const std::string& str)
{
	std::list<int> x;
	std::istringstream iss(str);

	// Parse the string to extract integers
	int num;
	while (iss >> num)
		x.push_back(num);

	// Step 1: Handle a possible remaining element if the size of x is odd
	int struggler = -1;

	if  (x.size() % 2 != 0)
	{
		struggler = x.back();
		x.pop_back();
	}

	// Step 2: Group elements to pairs & determine larger elements of each pair
	std::list<std::pair<int, int>> pairs;
	auto it = x.begin();
	while (it != x.end())
	{
		int first = *it;
		++it;
		int second = *it;
		++it;
		pairs.push_back(std::make_pair(std::max(first, second), std::min(first, second))); // make pair and put lager element first
	}

		// // Print pairs
		// std::cout << "\n-------------------------------------------------" << std::endl;
		// std::cout << "Pairs: ";
		// for (const auto& pair : pairs)
		// 	std::cout << "(" << pair.first << ", " << pair.second << ")";
		// std::cout << std::endl << std::endl;
		// std::cout << "-------------------------------------------------" << std::endl;

	// Step 3: Recursively sort larger elements from each pair
	auto startIdx = pairs.begin();
	listRecursivePairSort(pairs, startIdx);

		// // Print sorted pairs
		// std::cout << "Sorted Pairs: ";
		// for (const auto& pair : pairs) 
		// 	std::cout << "(" << pair.first << ", " << pair.second << ") ";
		// std::cout << std::endl << std::endl;
		// std::cout << "-------------------------------------------------" << std::endl;

	// Step 4: Create main_chain and pend
	std::list<int> main_chain;
	std::list<int> pend;

	for (const auto& pair : pairs) 
	{
		main_chain.push_back(pair.first);
		pend.push_back(pair.second);
	}

		// // Print main_chain elements & print pend elements
		// std::cout << "main_chain: ";
		// for (const auto& element : main_chain)
		// 	std::cout << element << " ";
		// std::cout << std::endl;

		// std::cout << "pend: ";
		// for (const auto& element : pend)
		// 	std::cout << element << " ";
		// std::cout << std::endl << std::endl;
		// std::cout << "-------------------------------------------------" << std::endl;

	// Step 5: Generate order of insertion using Jacobsthal sequence
	int i = 1;
	int k = 1;
	int len = pend.size();
	
	main_chain.push_front(pend.front());

	while (i < len)
	{
		for (int j = jacobsthalSequence(k); j > 0 && j > jacobsthalSequence(k - 1); --j)
		{
			auto it = pend.begin();
			if (j >= len)
				j = len - 1;
			std::advance(it, j);

			// Step 6: Use binary search for insertion positions
			listBinarySearch(main_chain, main_chain.begin(), main_chain.end(), *it);
			++i;
		}
		++k;
	}
	
	// Step 7: Insert the struggler
	if (struggler != -1)
		listBinarySearch(main_chain, main_chain.begin(), main_chain.end(), struggler);

	return main_chain;	// Return sorted list
}

//------------------------------------------------------------------------------
// INPUT CHECK
//------------------------------------------------------------------------------
std::string	checkInput(int argc, char **argv)
{
	if (argc <= 2)
			throw std::runtime_error("./PmergeMe <positive integer sequence>");
	
	std::string str;
	for (int i = 1; i < argc; ++i) 
	{
		// Check if the argument contains non-digit characters
		for (char *c = argv[i]; *c != '\0'; ++c)
		{
			if (!isdigit(*c))
				throw(std::runtime_error("Invalid input: Arguments must be positive integers"));
		}
		str += argv[i];
		if (i != argc - 1)
			str += " "; // Add space if it's not the last argument
	}
	return str;
}
