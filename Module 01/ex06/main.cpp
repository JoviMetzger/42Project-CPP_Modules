#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	harl;
	std::string debug_("DEBUG");
	std::string info_("INFO");
	std::string warning_("WARNING");
	std::string error_("ERROR");

	if (argc == 2 && (debug_.compare(argv[1]) == 0 || info_.compare(argv[1]) == 0 || warning_.compare(argv[1]) == 0 || error_.compare(argv[1]) == 0))
	{
		harlFilter(argv[1], harl);
	}
	else
	{
		std::cout << RED << "Wrong Input" << RESET << std::endl;
		std::cout << "Please try: DEBUG, INFO, WARNING, ERROR" << std::endl;
	}
	return 0;
}
