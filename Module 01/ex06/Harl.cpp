#include "Harl.hpp"

// Constructor
Harl::Harl()
{

}

// Destructor
Harl::~Harl() 
{

}

/* ft_convert();
 *	- Initializes an array of four strings (l_str).
 *	- Compares each element with the input argv to find a match.
 *	- If it finds a match, it returns the index of the matching log level
 *	- otherwise, it returns -1.
 */
int	ft_convert(char *argv)
{
	std::string	l_str[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i = -1;

	while (++i < 4)
	{
		if (l_str[i] == argv)
			return i;
	}
	return (-1);
}

/* harlFilter();
 *	- Results of ft_convert() to determine the log level.
 *	- Uses switch statement to compare the log level with the available log levels.
 */
void	harlFilter(char *argv, Harl harl)
{
	int	logLevel = ft_convert(argv);

	switch (logLevel)
	{
		case 0:
			harl.complain("DEBUG");
		case 1:
			harl.complain("INFO");
		case 2:
			harl.complain("WARNING");
		case 3:
			harl.complain("ERROR");
			break ;
	}
}

/* complain():
 *	- Defined an array of member function pointers (*ptr_function).
 *	- Defined and an array of corresponding level strings (l_str).
 *	- Loop through the levels, compare the level parameter to each level string,
 *	and call the associated member function if there's a match.
 */
void	Harl::complain( std::string level )
{
	void	(Harl::*ptr_function[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	l_str[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i = -1;

	while (++i < 4)
	{
		if (l_str[i] == level)
		{
			(this->*ptr_function[i])();
			break ;
		}
	}
}

// DEBUG message
void	Harl::debug( void )
{
	std::cout << PURPLE << "[DEBUG]" << RESET << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl
	<< std::endl;
}

// INFO message
void	Harl::info( void )
{
	std::cout << PURPLE << "[INFO]" << RESET << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl
	<< std::endl;
}

// WARNING message
void	Harl::warning( void )
{
	std::cout << PURPLE << "[WARNING]" << RESET << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl
	<< std::endl;
}

// ERROR message
void	Harl::error( void )
{
	std::cout << PURPLE << "[ERROR]" << RESET << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl
	<< std::endl;
}
