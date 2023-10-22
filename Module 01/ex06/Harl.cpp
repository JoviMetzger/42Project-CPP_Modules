#include "Harl.hpp"

// Constructor
Harl::Harl()
{
}

// Destructor
Harl::~Harl() 
{
}

void Harl::harlFilter( std::string level )
{
    switch (level) 
    {
        case 1:
            debug();
            break;
        case 2:
            info();
            break;
        case 3:
            warning();
            break;
        case 4:
            error();
            break;
    }
}

void debug( void )
{
    std::cout << "[DEBUG]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl
    << std::endl;
}

void info( void )
{
    std::cout << "[INFO]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl
    << std::endl;
}

void warning( void )
{
    std::cout << "[WARNING]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl
    << std::endl;
}

void error( void )
{
    std::cout << "[ERROR]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl
    << std::endl;
}
