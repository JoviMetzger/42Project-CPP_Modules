#include "phoneBook.hpp"

void PhoneBook::ft_add()
{
  Contact temp;

  std::cout << BLUE "First name: " << RESET;
  std::getline(std::cin, _firstName);
  temp.set_firstName(_firstName);
  std::cout << BLUE "Last name: " << RESET;
  std::getline(std::cin, _lastName);
  temp.set_lastName(_lastName);
  std::cout << BLUE "Nickname: " << RESET;
  std::getline(std::cin, _nickName);
  temp.set_nickName(_nickName);
  std::cout << BLUE "Phone number: " << RESET;
  std::getline(std::cin, _phoneNumber);
  temp.set_phoneNumber(_phoneNumber);
  std::cout << BLUE "Darkest secret: " << RESET;
  std::getline(std::cin, _dSecret);
  temp.set_dSecret(_dSecret);
}

void PhoneBook::ft_search()
{
  std::cout << "search ";
}

PhoneBook::PhoneBook() 
{

}

PhoneBook::~PhoneBook() 
{
  
}