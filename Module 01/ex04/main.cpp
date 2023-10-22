#include <iostream>
#include <string>

// COLORS
# define RED "\e[1;91m"
# define L_BLUE "\e[1;36m"
# define RESET "\033[0m"


int main(int argc, char **argv)
{
    if (argc == 4)
    {
        std::cout << argv << std::endl;
    }
    else
    {
        std::cout << RED << "Wrong Input" << RESET << std::endl; 
        std::cout << "Please try: ./replace " L_BLUE << "<" RESET 
        << "filename" << L_BLUE "> <" << RESET << "string_to_replace" 
        << L_BLUE << "> <" RESET << "string_to_replace_with" << L_BLUE 
        << ">" << RESET << std::endl; 

    }
    return 0;
}