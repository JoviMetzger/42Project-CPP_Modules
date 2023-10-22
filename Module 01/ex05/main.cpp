#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl harl;
	std::string debug_("DEBUG");
	std::string info_("INFO");
	std::string warning_("WARNING");
	std::string error_("ERROR");

	if (argc == 2 && (debug_.compare(argv[1]) == 0 || info_.compare(argv[1]) == 0 || warning_.compare(argv[1]) == 0 || error_.compare(argv[1]) == 0))
	{
		harl.complain(argv[1]);
	}
	else
	{
		std::cout << RED << "Unknown complain" << RESET << std::endl;
		std::cout << "Please try: DEBUG, INFO, WARNING, ERROR" << std::endl;
	}
	return 0;
}

// -------- Different main(), but same output --------

// int	main() 
// {
// 	Harl	harl;

// 	harl.complain("DEBUG");
// 	harl.complain("INFO");
// 	harl.complain("WARNING");
// 	harl.complain("ERROR");
// 	harl.complain("invalid"); // wrong input
// 	return 0;
// }
