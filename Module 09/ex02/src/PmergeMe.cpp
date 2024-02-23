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
	if (this != &value)	{}
	return *this;
}

//------------------------------------------------------------------------------
// -- Member function --

// Define a comparison function for sorting pairs based on the sum of their elements
bool comparePairs(const std::pair<int, int> &pair1, const std::pair<int, int> &pair2) 
{
    return pair1.first < pair2.first;
}

// Recursive function to sort pairs
void recursivePairSort(std::vector<std::pair<int, int>> &pairs, size_t startIdx = 0) 
{
    if (startIdx == pairs.size() - 1)
        return;

    for (size_t i = startIdx + 1; i < pairs.size(); ++i) 
	{
        if (!comparePairs(pairs[startIdx], pairs[i]))
            std::swap(pairs[startIdx], pairs[i]);
    }
    recursivePairSort(pairs, startIdx + 1);
}

int jacobsthalSequence(int n)
{
    if (n == 0)
        return (0);
    if (n == 1)
        return (1);
    
    int prev = 0;
    int current = 1;
    for (int i = 2; i < n; ++i)
    {
        int next = current + 2 *prev;
        prev = current;
        current = next;
    }
    return (current);
}

void    vecBinarySearch(std::vector<int>& main_chain, int start, int len, int value)
{
    if (start >= len)
    {
        main_chain.insert(main_chain.begin() + start, value);
        return ;
    }

    int mid = start + (len - start) / 2;
    
    if (main_chain[mid] < value)
        vecBinarySearch(main_chain, mid + 1, len, value);
    else if (main_chain[mid] > value)
        vecBinarySearch(main_chain, start, mid, value);
    else
    {
        main_chain.insert(main_chain.begin() + mid, value);
        return ;
    }
}

std::vector<int> PmergeMe::vecJohnsonSort(const std::string& str)
{
	std::cout << "STR: " << str << std::endl; // ---- RM
	std::vector<int> x;
	std::istringstream iss(str);

	int num;
	while (iss >> num)
		x.push_back(num);

	// Step 1: Group elements to pairs
	int struggler = -1;

	if  (x.size() % 2 != 0)
	{
		struggler = x.back();
		x.pop_back();
	}
	std::cout << std::endl;

	// Step 2: Determine larger elements of each pair
	int n = x.size();
	std::vector<std::pair<int, int>> pairs;
	for (int i = 0; i < n; i += 2)
	{
		int first = x[i];
		int second = x[i + 1];
		pairs.push_back(std::make_pair(std::max(first, second), std::min(first, second)));
	}

		// // Print pairs
		// std::cout << "\n-------------------------------------------------" << std::endl;
		// std::cout << "Pairs: ";
		// for (const auto& pair : pairs)
		// 	std::cout << "(" << pair.first << ", " << pair.second << ")";
		// std::cout << std::endl << std::endl;
		// std::cout << "-------------------------------------------------" << std::endl;

	// Step 3: recursively sort larger elements from each pair
	recursivePairSort(pairs);

		// // Print sorted pairs
		// std::cout << "Sorted Pairs: ";
		// for (const auto& pair : pairs) 
		// 	std::cout << "(" << pair.first << ", " << pair.second << ") ";
		// std::cout << std::endl << std::endl;
		// std::cout << "-------------------------------------------------" << std::endl;

	// Step 4: Create the main_chain and pend
	std::vector<int> main_chain;
    std::vector<int> pend;

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


	// Step 5: Generate order of insertion
	int i = 1;
    int ii = 1;
    int len = pend.size();
       
    main_chain.insert(main_chain.begin(), pend.front());

    while (i < len)
    {
        for (int j = jacobsthalSequence(ii); j > 0 && j > jacobsthalSequence(ii - 1); --j)
        {
            auto it = pend.begin();
            if (j >= len)
                j = len - 1;
            std::advance(it, j);
            vecBinarySearch(main_chain, 0, main_chain.size(), *it); // Step 6: use binary search to determine insertion positions
            ++i;
        }
        ++ii;
    }
	
	// Step 7: Insert the struggler
	if (struggler != -1)
		vecBinarySearch(main_chain, 0, main_chain.size(), struggler);

	return main_chain;
}

void checkInput(int argc, char **argv)
{
    if (argc == 1)
			throw std::runtime_error("./PmergeMe <positive integer sequence>");
    
    int i = 0;
    while (argv[i])
    {
        std::cout << i << std::endl;
        i++;
    }
    std::cout << "---------------------------------------------------" << std::endl;

}

