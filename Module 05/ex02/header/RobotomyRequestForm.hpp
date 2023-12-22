#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "../header/AForm.hpp"

class	AForm;

class	RobotomyRequestForm:  public AForm
{
	private:
		std::string	_target;
	public:
		RobotomyRequestForm();							// Default constructor
		RobotomyRequestForm(const RobotomyRequestForm& value);			// Copy constructor
		RobotomyRequestForm& operator=(const RobotomyRequestForm& value);	// Copy assignment operator
		~RobotomyRequestForm();							// Destructor

		RobotomyRequestForm(const std::string& target);				// Constructor

		// Member Function
		void execute(Bureaucrat const &executor) const;
};

#endif
