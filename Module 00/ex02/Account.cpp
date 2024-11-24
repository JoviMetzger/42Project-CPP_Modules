#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// ---------- Constructor ----------
/* Account();
 *	Assining all the variables.
 *	Display for: [d_t] index: ;amount: ;created
 */
Account::Account( int initial_deposit )
{
    _accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	// Print log;
	_displayTimestamp();
	std::cout << "index:" <<_accountIndex << ";" 
	<< "amount:" << _amount << ";"
	<< "created" << std::endl;
}

// ---------- Destructor ----------
/* ~Account();
 *	Display For: [d_t] index: ;amount: ;closed
 */
Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" <<_accountIndex << ";" 
	<< "amount:" << _amount << ";"
	<< "closed" << std::endl;
}

// ---------- DISPLAY FUNCTIONS ----------
/* displayAccountsInfos();
 *	Display for: [d_t] accounts: ;total: ;deposits: ;withdrawals:
 */
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";" 
	<< "total:" << getTotalAmount() << ";"
	<< "deposits:" << getNbDeposits() << ";"
	<< "withdrawals:" << getNbWithdrawals() << std::endl;
}

/* displayStatus();
 *	Display for: [d_t] index: ;amount: ;deposits: ;withdrawals:
 */
void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" <<_accountIndex << ";" 
	<< "amount:" << _amount << ";"
	<< "deposits:" << _nbDeposits << ";"
	<< "withdrawals:" <<_nbWithdrawals << std::endl;
}

/* _displayTimestamp();
 *	Gets the current time.
 *	strftime(): displays it in [Year,Month,Day_Hour,Minute,Second] order.
 */
void	Account::_displayTimestamp( void )
{
	time_t	UnixEpoch;
	time(&UnixEpoch);								//number of seconds elapsed since the Unix epoch (January 1, 1970).
	struct	tm *tm_struct = localtime(&UnixEpoch);	//convert this UnixEpoch timestamp in the local time zone.
	char	buffer[20];

	strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", tm_struct);
	std::cout << buffer;
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

// ---------- Check Amount Function ----------
int	Account::checkAmount( void ) const
{
	return (_amount);
}

/* makeDeposit();
 *	Adds the given deposit to amount.
 *	Display fot: [d_t] index: ;p_amount: ;deposit: ;amount: ;nb_deposits:
 */
void	Account::makeDeposit( int deposit )
{
	int	newAmount = this->_amount + deposit;
	this->_nbDeposits++;

	// Print log;
	_displayTimestamp();
	std::cout << "index:" <<_accountIndex << ";"
	<< "p_amount:" << _amount << ";"
	<< "deposit:" << deposit << ";"
	<< "amount:" << newAmount << ";"
	<< "nb_deposit:" << _nbDeposits << ";" << std::endl;

	this->_amount = newAmount;
	_totalNbDeposits++;
	_totalAmount += deposit;
}

/* makeWithdrawal();
 *	Checks if withdrawal is bigger than amount
 *	If yes, it refuses.
 *	Otherwise, it subtracts the withdrawal from amount.
 *	Display for:  [d_t] index: ;p_amount: ;withdrawals: ;amount: ;nb_withdrawals: 
 */
bool	Account::makeWithdrawal( int withdrawal )
{
	if (withdrawal > this->_amount)
	{
		// Print log for 'refused';
		_displayTimestamp();
		std::cout << "index:" <<_accountIndex << ";" 
		<< "p_amount:" << _amount << ";"
		<< "withdrawals:refused" << std::endl;
		return (false);
	}
	else
	{
		int	newAmount = this->_amount - withdrawal;
		this->_nbWithdrawals++;

		// Print log;
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";" 
		<< "p_amount:" << _amount << ";"
		<< "withdrawals:" << withdrawal << ";"
		<< "amount:" << newAmount << ";"
		<< "nb_withdrawals:" <<_nbWithdrawals << std::endl;

		this->_amount = newAmount;
		_totalNbWithdrawals++;
		_totalAmount = _totalAmount - withdrawal;
		return (true);
	}
}
