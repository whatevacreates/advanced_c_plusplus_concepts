#include "Account.hpp"
#include <iomanip>
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
int MAX = 0;

static int accountArray[100] = {0}; 


Account::Account(int initial_deposit) : _amount(initial_deposit),
	_nbDeposits(0), _nbWithdrawals(0)
{
	
    accountArray[MAX] =  _amount;
    MAX += 1;
	_displayTimestamp();
	_accountIndex = _nbAccounts++;
	_totalAmount += initial_deposit;
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}

Account::~Account() {
    int i = 0;
    _nbAccounts--;
    _totalAmount -= _amount;
    
    if(_accountIndex == MAX -1)
    {
        while(MAX > i)
        {
            _displayTimestamp();
            std::cout << "index:" << i << ";amount:" << accountArray[i] << ";closed" << std::endl;
            i++;
        }
    }
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
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
	std::time_t currentTime = std::time(NULL);
    std::tm *localTime = std::localtime(&currentTime);

    
    char buffer[20]; 

    std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", localTime);


    std::cout << buffer;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit << ";amount:" << _amount;
	_amount += deposit;
    accountArray[_accountIndex] = _amount;
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	if(deposit > 0)
	std::cout << ";amount:" << _amount << ";nb_deposits:1"<< std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();

	if (withdrawal > _amount)
	{
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << std::endl;
		return (false);
	}
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:" << _nbWithdrawals;
    
	_amount -= withdrawal; 
    accountArray[_accountIndex] = _amount;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;
	std::cout << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

int Account::checkAmount(void) const
{
	return (_amount);
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}
