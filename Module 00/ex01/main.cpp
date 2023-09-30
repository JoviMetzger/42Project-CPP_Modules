#include "phoneBook.hpp"
#include "contact.hpp"

void ft_display()
{
  std::cout << "WELCOME TO MY PHONEBOOK";
}

int main() 
{
    PhoneBook phonebook;
  std::string command;

  ft_display();
  while (1)
  {
    std::cout << "Enter a command > ";
    getline(std::cin, command);
    if (command == "ADD")
    {
        phonebook.ft_add();
    }
    else if (command == "SEARCH")
    {
       phonebook.ft_search();
    }
    else if (command == "EXIT" || std::cin.eof())
    {
      return 0;
    }
    else
    {
      std::cout << RED"NOT A VALID COMMAND!\n" << RESET"Please try "<< GREEN"ADD" << RESET", " << GREEN"SEARCH" << RESET" or " << GREEN"EXIT\n" << RESET;
    }
  }
  return 0;
}