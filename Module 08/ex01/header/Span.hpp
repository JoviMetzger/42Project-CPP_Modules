#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>

class	Span
{
	private:
		unsigned int		_maxSize;
		std::vector<int>	_vecNumbers;
	public:
		Span();					// Default Constructor
		~Span();				// Destructor 
		Span(const Span& value);		// Copy constructor
		Span &operator=(const Span& value);	// Assignment= operator

		Span(unsigned int N);			// Constructor

		// Member function
		void	addNumber(int num);
		int	shortestSpan() const;
		int	longestSpan() const;
};

#endif
