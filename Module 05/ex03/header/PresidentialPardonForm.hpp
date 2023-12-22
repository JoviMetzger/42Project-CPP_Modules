#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "../header/AForm.hpp"

class	AForm;

class	PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;
	public:
		PresidentialPardonForm();						// Default constructor
		PresidentialPardonForm(const PresidentialPardonForm& value);		// Copy constructor
		PresidentialPardonForm& operator=(const PresidentialPardonForm& value);	// Copy assignment operator
		~PresidentialPardonForm();						// Destructor

		PresidentialPardonForm(const std::string& target); 			// Constructor

		// Member Function
		void execute(Bureaucrat const &executor) const;
};

#endif
