#include "Harl.hpp"

int main(int argc, char **argv)
{
    std::string debug_("DEBUG");
    std::string info_("INFO");
    std::string warning_("WARNING");
    std::string error_("ERROR");
    Harl harl;

    if (argc == 2 && (debug_.compare(argv[1]) == 0 || info_.compare(argv[1]) == 0 || warning_.compare(argv[1]) == 0 || error_.compare(argv[1]) == 0))
    {
        harl.harlFilter(argv[1]);
    }
    else
    {
        std::cout << RED << "Wrong Input" << RESET << std::endl; 
        std::cout << "Please try: DEBUG, INFO, WARNING, ERROR" << std::endl; 

    }
    return 0;
}