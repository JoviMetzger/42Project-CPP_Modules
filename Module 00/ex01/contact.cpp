#include "phoneBook.hpp"

Contact::Contact() 
{

}

Contact::~Contact() 
{
  
}

std::string Contact:: get_firstName()
{
    return (this->_firstName);
}

std::string Contact:: get_lastName()
{
    return (this->_lastName);
}

std::string Contact:: get_nickName()
{
    return (this->_nickName);
}

std::string Contact:: get_phoneNumber()
{
    return (this->_phoneNumber);
}

std::string Contact:: get_dSecret()
{
    return (this->_dSecret);
}

void Contact::set_firstName(std::string firstName)
{
    this->_firstName = firstName;
}

void Contact::set_lastName(std::string lastName)
{
    this->_lastName = lastName;
}

void Contact::set_nickName(std::string nickName)
{
    this->_nickName = nickName;
}

void Contact::set_phoneNumber(std::string phoneNumber)
{
    this->_phoneNumber = phoneNumber;
}

void Contact::set_dSecret(std::string dSecret)
{
    this->_dSecret = dSecret;
}