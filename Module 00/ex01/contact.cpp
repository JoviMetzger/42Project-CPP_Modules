#include "phoneBook.hpp"

// Constructor
Contact::Contact()
{

}

// Destructor
Contact::~Contact() 
{

}


// ---------- GET FUNCTIONS ---------- 
std::string	Contact:: get_firstName()
{
	return (this->firstName_);
}

std::string	Contact:: get_lastName()
{
	return (this->lastName_);
}

std::string	Contact:: get_nickName()
{
	return (this->nickName_);
}

std::string	Contact:: get_phoneNumber()
{
	return (this->phoneNumber_);
}

std::string	Contact:: get_dSecret()
{
	return (this->dSecret_);
}


// ---------- SET FUNCTIONS ---------- 
void	 Contact::set_firstName(std::string firstName)
{
	this->firstName_ = firstName;
}

void	Contact::set_lastName(std::string lastName)
{
	this->lastName_ = lastName;
}

void	Contact::set_nickName(std::string nickName)
{
	this->nickName_ = nickName;
}

void	Contact::set_phoneNumber(std::string phoneNumber)
{
	this->phoneNumber_ = phoneNumber;
}

void	Contact::set_dSecret(std::string dSecret)
{
	this->dSecret_ = dSecret;
}
