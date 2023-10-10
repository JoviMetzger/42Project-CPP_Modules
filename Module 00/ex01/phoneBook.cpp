#include "phoneBook.hpp"

// Constructor
PhoneBook::PhoneBook() 
{
	this->_index = 0;
}

// Destructor
PhoneBook::~PhoneBook() 
{

}

// --------- ADD ---------
/* ft_add();
 *  Lets the user add the wanted information (no empty strings).
 *  Keeps track of how many users are already added.
 *  If users exceed 8, it warns of overwriting.
 */
void	PhoneBook::ft_add()
{
	Contact	temp;

	if (this->_index > 7)
		std::cout << RED "WARNING! " << RESET << "overwriting contact" << std::endl;

	while (1)	// First Name
	{
		std::cout << BLUE "First name: " << RESET;
		std::getline(std::cin, _firstName);
		if (_firstName.empty())
			std::cout << RED "!" << RESET << "can't be empty. Try again" << std::endl;
		else
			break ;
	}
	temp.set_firstName(_firstName);

	while (1)	// Last Name
	{
		std::cout << BLUE "Last name: " << RESET;
		std::getline(std::cin, _lastName);
		if (_lastName.empty())
			std::cout << RED "!" << RESET << "can't be empty. Try again" << std::endl;
		else
			break ;
	}
	temp.set_lastName(_lastName);

	while (1)	// Nickname
	{
		std::cout << BLUE "Nickname: " << RESET;
		std::getline(std::cin, _nickName);
		if (_nickName.empty())
			std::cout << RED "!" << RESET << "can't be empty. Try again" << std::endl;
		else
			break ;
	}
	temp.set_nickName(_nickName);

	while (1)	// Phone Number
	{
		std::cout << BLUE "Phone number: " << RESET;
		std::getline(std::cin, _phoneNumber);
		if (_phoneNumber.empty())
			std::cout << RED "!" << RESET << "can't be empty. Try again" << std::endl;
		else
			break ;
	}
	temp.set_phoneNumber(_phoneNumber);

	while (1)	// Darkest Secret
	{
		std::cout << BLUE "Darkest secret: " << RESET;
		std::getline(std::cin, _dSecret);
		if (_dSecret.empty())
			std::cout << RED "!" << RESET << "can't be empty. Try again" << std::endl;
		else
			break ;
	}
	temp.set_dSecret(_dSecret);

	this->_contact[this->_index % 8] = temp;
	this->_index++;
}

// --------- SEARCH ---------
/* ft_size();
 *  If the string is longer than 10 characters, 
 *  it will return a modified string that contains the first 9 characters 
 *  of the original string followed by a ".". 
 */
std::string	ft_size(std::string contact)
{
	if (contact.length() > 10)
	{
		contact.erase(contact.begin() + 9, contact.end());
		contact.append(".");
	}
	return (contact);
}

/* ft_display_contacts();
 *  Prints the contacts list. (First Name, Last Name, Nickname).
 */
int	ft_display_contacts(Contact _contact[8])
{
	int	i = 0;
	std::cout << " +---------------------------------------------------+" << std::endl;
	std::cout << " |    " << BLUE "Index" << RESET"   | " << BLUE "First Name" << RESET" |  "
	<< BLUE "Last Name" << RESET" |  " << BLUE "Nickname" << RESET"  |" << std::endl;
	std::cout << " +------------|------------|------------|------------+" << std::endl;

	while (++i <= 8)
	{
		std::cout
		<< " | " << std::setw(10) << i
		<< " | " << std::setw(10) << ft_size(_contact[i - 1].get_firstName())
		<< " | " << std::setw(10) << ft_size(_contact[i - 1].get_lastName())
		<< " | " << std::setw(10) << ft_size(_contact[i - 1].get_nickName())
		<< " |" << std::endl;
	}
	std::cout << " +---------------------------------------------------+\n\n";
	return (0);
}

/* ft_search();
 *  Checks if the phonebook is not empty.
 *  Displays all the contacts.
 *  Choose a valid index (contact).
 *  Display chosen contact with all information.
 */
void	PhoneBook::ft_search()
{
	int		i = -1;
	std::string	index;

	if (this->_contact[0].get_firstName().empty())
	{
		std::cout << RED "Phonebook is empty" << RESET << std::endl;
		return ;
	}
	else
		ft_display_contacts(this->_contact);

	std::cout << "What Contact would you like to view?" << std::endl;
	std::cout << "Enter index "<< L_BLUE ">> " << RESET;
	std::getline(std::cin, index);
	i = index[0] - 48 - 1;	// Converts string into int

	if (i > -1 && i < 9 && !this->_contact[i].get_firstName().empty())
	{
		std::cout << "\n Contact Information about: " << L_BLUE << this->_contact[i].get_firstName() 
		<< " " << this->_contact[i].get_lastName() << RESET << std::endl;
		std::cout << " +---------------------------------------------------+" << std::endl;
		std::cout << "   First Name     : " << this->_contact[i].get_firstName() << std::endl;
		std::cout << "   Last Name      : " << this->_contact[i].get_lastName() << std::endl;
		std::cout << "   Nickame        : " << this->_contact[i].get_nickName() << std::endl;
		std::cout << "   Phone Number   : " << this->_contact[i].get_phoneNumber() << std::endl;
		std::cout << "   Darkest Secret : " << this->_contact[i].get_dSecret() << std::endl;
		std::cout << " +---------------------------------------------------+" << std::endl << std::endl;
	}
	else
		std::cout << RED "INDEX INVALID" << RESET << std::endl;
}
