#include "Account.hpp"
#include <iostream>
#include <ctime>

#define likely(_expr)	__builtin_expect(!!(_expr), 1)
#define unlikely(_expr)	__builtin_expect(!!(_expr), 0)

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(
	int initial_deposit
)
{
	Account::_displayTimestamp();
	std::cout	<< "index:" << Account::_nbAccounts \
				<< ";amount:" << initial_deposit \
				<< ";created" << std::endl;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
}

Account::Account(void)
{
	this->_accountIndex = 0;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
}

Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex \
				<< ";amount:" << this->_amount \
				<< ";closed" << std::endl;
	Account::_nbAccounts--;
	Account::_totalAmount -= this->_amount;
}

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

//accounts:8;total:12442;deposits:8;withdrawals:6
void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout	<< "accounts:" << Account::getNbAccounts() \
				<< ";total:" << Account::getTotalAmount() \
				<< ";deposits:" << Account::getNbDeposits() \
				<< ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit(
	int deposit
)
{
	Account::_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex \
				<< ";p_amount:" << this->_amount \
				<< ";deposit:" << deposit;
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	std::cout	<< ";amount:" << this->_amount \
				<< ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(
	int withdrawal
)
{
	Account::_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex \
				<< ";p_amount:" << this->_amount \
				<< ";withdrawal:";
	if (unlikely(withdrawal > this->_amount))
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout	<< withdrawal \
				<< ";amount:" << this->_amount \
				<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

int	Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex \
				<< ";amount:" << this->_amount \
				<< ";deposits:" << this->_nbDeposits \
				<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void)
{
	std::time_t now = std::time(0);
	std::tm *tm = std::localtime(&now);
	std::cout << "[" << (tm->tm_year + 1900) << (tm->tm_mon + 1) << tm->tm_mday << "_" << tm->tm_hour << tm->tm_min << tm->tm_sec << "] ";
}
