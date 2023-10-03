#include "phoneBook.hpp"

PhoneBook::PhoneBook() 
{

}

PhoneBook::~PhoneBook() 
{
  
}

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

  if (this->_currentPos < 8)
  {
    this->_contact[this->_currentPos] = temp;
    this->_index = this->_currentPos;
    this->_currentPos++;
  }
  else
  {
    std::cout << RED "WARNING: " << RESET "overwriting contact" <<std::endl;
    this->_contact[this->_currentPos % 8] = temp;
    this->_index = this->_currentPos % 8;
    this->_currentPos++;
  }
  std::cout << "Contact has been added "<< GREEN"SUCCESSFUL" << RESET << std::endl;
}

void ft_display_contacts()
{
  std::cout << " +---------------------------------------------------+" << std::endl;
  std::cout << " |  " << BLUE "Index" << RESET"  |  " << BLUE "First Name" << RESET"  |  " << BLUE "Last Name" << RESET"  |  " << BLUE "Nickname" << RESET"  |" << std::endl;
  std::cout << " +---------|--------------|-------------|------------+" << std::endl;
 
  std::cout << " +---------------------------------------------------+\n\n";
}

void PhoneBook::ft_search()
{
  int index;

  ft_display_contacts();
  std::cout << "Enter index "<< L_BLUE ">> " << RESET;
  std::cin >> index;
  std::cout << "TEST";
  return ;
  

}