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
    while (1)
    {
        bool valid = true;
        for (size_t i = 0; i < phoneNumber.length(); ++i)
        {
            if (!std::isdigit(phoneNumber[i]))
            {
                std::cout << RED"Input is not valid!\n" << RESET "Only numbers are valid\n";
                std::cout << "Please enter a valid phone number\n";
                valid = false;
                break;
            }
        }
        if (valid)
        {
            this->_phoneNumber = phoneNumber;
            break;
        }
        
        // Prompt the user for input again
        std::cout << BLUE "Phone number: " << RESET;
        std::cin >> phoneNumber; //used to read input from the standard input stream
    }
}

void Contact::set_dSecret(std::string dSecret)
{
    this->_dSecret = dSecret;
}