#include "Harl.hpp"

// Constructor
Harl::Harl()
{
    // Initialize the map with function pointers
	complainLevels["debug"] = &Harl::debug;
    complainLevels["info"] = &Harl::info;
    complainLevels["warning"] = &Harl::warning;
    complainLevels["error"] = &Harl::error;
}

// Destructor
Harl::~Harl() 
{
}

void Harl::complain( std::string level )
{
    std::map<std::string, void (Harl::*)()>::const_iterator it = complainLevels.find(level);
        if (it != complainLevels.end()) {
            (this->*it->second)(); // Call the member function using the function pointer
        } else {
            std::cout << "Unknown complaint level: " << level << std::endl;
        }
}

void debug( void )
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void info( void )
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void warning( void )
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void error( void )
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
