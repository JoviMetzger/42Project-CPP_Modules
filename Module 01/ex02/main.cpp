#include <iostream>
#include <string>

// COLORS
# define L_BLUE "\e[1;36m"
# define RESET "\033[0m"

void main()
{
    std::string str = "HI THIS IS BRAIN";
    // stringPTR:
    // stringREF:

    std::cout << L_BLUE << "The memory address of the string variable" << RESET << std::endl;
    std::cout << L_BLUE << "The memory address held by stringPTR" << RESET << std::endl;
    std::cout << L_BLUE << "The memory address held by stringREF" << RESET << std::endl;

    std::cout << L_BLUE << "The value of the string variable" << RESET << std::endl;
    std::cout << L_BLUE << "The value pointed to by stringPTR" << RESET << std::endl;
    std::cout << L_BLUE << "The value pointed to by stringREF" << RESET << std::endl;
}