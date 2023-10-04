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

  while (std::cin)
  {
    std::cout << BLUE "First name: " << RESET;
    if (std::getline(std::cin, _firstName))
    {
      temp.set_firstName(_firstName);
      break ;
    }
    else 
      std::cout << RED "!"<< RESET " Can't be empty" << std::endl;
  }
  while (std::cin)
  {
    std::cout << BLUE "Last name: " << RESET;
    if (std::getline(std::cin, _lastName))
    {
      temp.set_lastName(_lastName);
      break ;
    }
    else
      std::cout << RED "!" << RESET " Can't be empty" << std::endl;
  }
  while (std::cin)
  {
    std::cout << BLUE "Nickname: " << RESET;
    if (std::getline(std::cin, _nickName))
    {
      temp.set_nickName(_nickName);
      break ;
    }
    else
      std::cout << RED "!" << RESET " Can't be empty" << std::endl;
  }
  while (std::cin)
  {
    std::cout << BLUE "Phone number: " << RESET;
    if (std::getline(std::cin, _phoneNumber))
    {
      temp.set_phoneNumber(_phoneNumber);
      break ;
    }
    else
      std::cout << RED "!" << RESET " Can't be empty" << std::endl;
  }
  while (std::cin)
  {
    std::cout << BLUE "Darkest secret: " << RESET;
    if (std::getline(std::cin, _dSecret))
    {
      temp.set_dSecret(_dSecret);
      break ;
    }
    else
      std::cout << RED "!" << RESET " Can't be empty" << std::endl;
  }
  this->_contact[_currentPos % 8] = temp;
  this->_currentPos++;
  if (this->_currentPos <= 8)
    this->_index = this->_currentPos;
  std::cout << "Contact has been added "<< GREEN"SUCCESSFUL" << RESET << std::endl;
}

std::string ft_size(std::string contact)
{
  if (contact.length() > 10)
  {
    contact.erase(contact.begin() + 9, contact.end());
    contact.append(".");
  }
  return (contact);
}

int ft_display_contacts(Contact _contact[8])
{
  int i = 0;
  std::cout << " +---------------------------------------------------+" << std::endl;
  std::cout << " |    " << BLUE "Index" << RESET"   | " << BLUE "First Name" << RESET" |  " << BLUE "Last Name" << RESET" |  " << BLUE "Nickname" << RESET"  |" << std::endl;
  std::cout << " +------------|------------|------------|------------+" << std::endl;

  while (++i <= '8')
  {
    std::cout 
    << " | " << std::setw(10) << i 
    << " | " << std::setw(10) << ft_size(_contact[i].get_firstName())
    << " | " << std::setw(10) << ft_size(_contact[i].get_lastName())
    << " | " << std::setw(10) << ft_size(_contact[i].get_nickName())
    << " |" << std::endl;
  }
  std::cout << " +---------------------------------------------------+\n\n";
  return (0);
}

void PhoneBook::ft_search()
{
  int index;

  if (!ft_display_contacts(this->_contact))
  {
    std::cout << RED "Phonebook is empty" << RESET << std::endl;
    return ;
  }
  std::cout << "Enter index "<< L_BLUE ">> " << RESET;
  std::cin >> index;
  if (index < this->_index && std::cin.eof())
  {
    std::cout << " Contact Information about: " << L_BLUE << this->_contact[index].get_firstName() << this->_contact[index].get_lastName() << RESET << std::endl;
    std::cout << " +---------------------------------------------------+" << std::endl;
    std::cout << "   First Name     : " << this->_contact[index].get_firstName() << std::endl;
    std::cout << "   Last Name      : " << this->_contact[index].get_lastName() << std::endl;
    std::cout << "   Nickame        : " << this->_contact[index].get_nickName() << std::endl;
    std::cout << "   Phone Number   : " << this->_contact[index].get_phoneNumber() << std::endl;
    std::cout << "   Darkest Secret : " << this->_contact[index].get_dSecret() << std::endl;
    std::cout << " +---------------------------------------------------+" << std::endl;
  }
    else
      std::cout << RED "INDEX INVALID" << RESET << std::endl;
}