#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	Account::_totalNbDeposits++;
	_accountIndex = Account::_nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 1;
	_nbWithdrawals = 0;
}

Account::~Account()
{
}

int Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
	std::cout << Account::_nbAccounts << Account::_totalAmount << Account::_totalNbDeposits << Account::_totalNbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_amount += deposit;
	Account::_totalNbDeposits++;
	_nbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal)
{
	if (_amount > withdrawal)
	{
		_amount -= withdrawal;
		Account::_totalNbWithdrawals++;
		_nbWithdrawals++;
		return (true);
	}
	return (false);
}

int Account::checkAmount(void) const
{
	return (_amount);
}

void Account::displayStatus(void) const
{
	std::cout << _accountIndex << _amount << _nbDeposits << _nbWithdrawals << std::endl;
}
