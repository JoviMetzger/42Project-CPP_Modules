#include "Harl.hpp"

// Constructor
Harl::Harl()
{

}

// Destructor
Harl::~Harl() 
{

}

/* complain():
 *  - Defined an array of member function pointers (*ptr_function).
 *  - Defined and an array of corresponding level strings (l_str).
 *  - Loop through the levels, compare the level parameter to each level string,
 *    and call the associated member function if there's a match.
 */
void	Harl::complain( std::string level )
{
	void	(Harl::*ptr_function[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	l_str[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = -1;
	bool found = false;

	while (++i < 4)
	{
		if (l_str[i] == level)
		{
			(this->*ptr_function[i])();
			found = true;
			break ;
		}
	}
	if (!found)
		std::cout << RED << "Unknown complain" << RESET << std::endl;
}

// DEBUG message
void	Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

// INFO message
void	Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

// WARNING message
void	Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

// ERROR message
void	Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
