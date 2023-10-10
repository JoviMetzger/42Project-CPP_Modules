#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// ---------- Constructor ----------
// [d_t] index: ;amount: ;created
Account::Account( int initial_deposit )
{
    _accountIndex = _nbAccounts;
    _nbAccounts++;
	_amount = initial_deposit;
    _totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

     _displayTimestamp();
    std::cout << "index:" <<_accountIndex << ";" 
    << "amount:" << _amount << ";"
    << "created:" << std::endl;
}

// ---------- Destructor ----------
// [d_t] index: ;amount: ;closed
Account::~Account( void )
{
     _displayTimestamp();
    std::cout << "index:" <<_accountIndex << ";" 
    << "amount:" << _amount << ";"
    << "closed:" << std::endl;
}


// ---------- DISPLAY FUNCTIONS ----------
// [d_t] accounts: ;total: ;deposits: ;withdrawals:
void	Account::displayAccountsInfos( void )
{
     _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";" 
    << "total:" << getTotalAmount() << ";"
    << "deposits:" << getNbDeposits() << ";"
    << "withdrawals:" << getNbWithdrawals() << std::endl;
}

// [d_t] index: ;amount: ;deposits: ;withdrawals:
void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:" <<_accountIndex << ";" 
    << "amount:" << _amount << ";"
    << "deposits:" << _nbDeposits << ";"
    << "withdrawals:" <<_nbWithdrawals << std::endl;
}


// ---------- GET FUNCTIONS ----------
int	Account::getNbAccounts( void )
{
    return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
    return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
    return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
    return (_totalNbWithdrawals);
}



int		Account::checkAmount( void ) const
{
    return (_amount);
}

void	Account::makeDeposit( int deposit )
{
    std::cout << "AAAAAA: " << deposit << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    std::cout << "QQQQQQ" << withdrawal << std::endl;
    return (true);
}

void	Account::_displayTimestamp( void )
{
    std::cout << "HHHHHHHH" << std::endl;
}
