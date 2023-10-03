#include "phoneBook.hpp"

void ft_display_welcome()
{
  std::cout << " +--------------------------------------------+\n";
  std::cout << " |   " << BLUE"WELCOME TO MY CRAPPY AWESOME PHONEBOOK" << RESET"   |\n";
  std::cout << " +--------------------------------------------+\n";
  std::cout << " |                                            |\n";
  std::cout << " |   Command Options:                         |\n";
  std::cout << " |" << RED"                 1." << RESET " ADD,                    |\n";
  std::cout << " |" << RED"                 2." << RESET " SEARCH,                 |\n";
  std::cout << " |" << RED"                 3." << RESET " EXIT                    |\n";
  std::cout << " |                                            |\n";
  std::cout << " +--------------------------------------------+\n\n";
}

int main() 
{
    PhoneBook phonebook;
    std::string command;

    ft_display_welcome();
    while (1)
    {
      std::cout << "Enter a command "<< BLUE ">> " << RESET;
      getline(std::cin, command);
      if (command == "ADD")
          phonebook.ft_add();
      else if (command == "SEARCH")
        phonebook.ft_search();
      else if (command == "EXIT" || std::cin.eof())
      {
        std::cout << YELLOW "\n🌼 Good bye 🌼\n\n" << RESET;
        return 0;
      }
      else
        std::cout << RED"NOT A VALID COMMAND!\n" << RESET"Please try: "<< GREEN"ADD" << RESET", " << GREEN"SEARCH" << RESET", " << GREEN"EXIT\n" << RESET;
    }
    return 0;
}