#include "Account.hpp"

static int	_nbAccounts = 0;
static int	_totalAmount = 0;
static int	_totalNbDeposits = 0;
static int	_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	static int	_nbAccounts = 10;
	static int	_totalAmount = initial_deposit;
	static int	_totalNbDeposits = 1;
	static int	_totalNbWithdrawals = 0;
	std::cout << _nbAccounts << _totalAmount << _totalNbDeposits << _totalNbWithdrawals << std::endl;
}

Account::~Account()
{
}

int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
}

void Account::makeDeposit(int deposit)
{
	_amount += deposit;
	_nbDeposits++;
}
bool Account::makeWithdrawal(int withdrawal)
{
	if (_amount > withdrawal)
	{
		_amount -= withdrawal;
		_nbWithdrawals++;
		return (true);
	}
	return (false);
}
int Account::checkAmount(void) const
{
	return (_totalAmount);
}
void Account::displayStatus(void) const
{

}