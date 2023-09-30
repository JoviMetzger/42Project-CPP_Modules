#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>
#include <string>

# define RED "\e[1;31m" 
// # define RED "\e[1;91m"
// # define YELLOW "\e[1;33m"
// # define PURPLE "\e[1;35m"
# define CYAN "\e[1;36m"
# define BLUE "\e[1;34m"
# define GREEN "\e[1;32m"
# define YELLOW "\e[0;33m"
# define PURPLE "\e[0;35m"
# define L_BLUE "\e[1;36m"
# define RESET "\033[0m"

class PhoneBook
{
  private:

  public:
    PhoneBook();    // Constructor
    ~PhoneBook();   // Destructor
    void ft_search();
    void ft_add();
};

#endif