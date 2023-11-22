#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

// Base class
class	Brain
{
	private:
		std::string     _ideas[100];
	public:
		Brain();               			// Default constructor
		Brain(const Brain& value);		// Copy constructor
		Brain& operator=(const Brain& value);	// Copy assignment operator
		~Brain();				// Destructor 

		std::string	getIdea(unsigned int index) const;
		void		addIdea(std::string idea, int i);
};

#endif
