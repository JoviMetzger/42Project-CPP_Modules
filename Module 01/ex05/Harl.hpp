#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>
#include <map>

// COLORS
# define RED "\e[1;91m"
# define RESET "\033[0m"

class   Harl
{
    private:
        // Mapping of complaint levels to member function pointers
        std::map<std::string, void (Harl::*)()> complainLevels;
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
    public:
        Harl(); // Constructor
        ~Harl();    // Destructor
        void complain( std::string level );
}; 

#endif