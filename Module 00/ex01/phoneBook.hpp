#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>
#include <string>

# define RED "\e[1;91m"
# define YELLOW "\e[1;33m"
# define BLUE "\e[1;34m"
# define GREEN "\e[1;32m"
# define PURPLE "\e[0;35m"
# define L_BLUE "\e[1;36m"
# define RESET "\033[0m"

class Contact
{
  private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickName;
    std::string _phoneNumber;
    std::string _dSecret;

  public:
    Contact();            // Constructor
    ~Contact();           // Destructor
    std::string get_firstName();
    std::string get_lastName();
    std::string get_nickName();
    std::string get_phoneNumber();
    std::string get_dSecret();

    void set_firstName(std::string firstName);
    void set_lastName(std::string lastName);
    void set_nickName(std::string nickName);
    void set_phoneNumber(std::string phoneNumber);
    void set_dSecret(std::string dSecret);
  
};

class PhoneBook
{
  private:
    Contact _contact[8];
    int _index;
    int _currentPos;
    std::string _firstName;
   std::string _lastName;
   std::string _nickName;
   std::string _phoneNumber;
   std::string _dSecret;


  public:
    PhoneBook();    // Constructor
    ~PhoneBook();   // Destructor
    void ft_search();
    void ft_add();
} ;


#endif