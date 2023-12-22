#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "../header/AForm.hpp"
# include "../header/PresidentialPardonForm.hpp"
# include "../header/ShrubberyCreationForm.hpp"
# include "../header/RobotomyRequestForm.hpp"

class	Intern
{
       	public:
		Intern();				// Default constructor
		Intern(const Intern& value);		// Copy constructor
		Intern& operator=(const Intern& value);	// Copy assignment operator
		~Intern();				// Destructor

		// Member Function
		AForm*	makeForm(const std::string &name, const std::string &target);
		AForm*	ShrubberyCreation(std::string target);
		AForm*	RobotomyRequest(std::string target);
		AForm*	PresidentialPardon(std::string target);

		// Exception classes that inherits from the standard std::exception class
		class InternException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif
