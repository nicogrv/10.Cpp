// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include "../Include/Account.hpp"
#include <iostream>
#include <ctime>
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp() 
{
	time_t now = time(0);

    char buffer[16];
    struct tm* timeinfo = localtime(&now);
    strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", timeinfo);
    std::cout << "[" << buffer << "] ";
    return ;
}

int	Account::getNbAccounts()
{	return (Account::_nbAccounts);}

int	Account::getTotalAmount()
{	return (Account::_totalAmount);}

int	Account::getNbDeposits()
{	return (Account::_totalNbDeposits);}

int	Account::getNbWithdrawals()
{	return (Account::_totalNbWithdrawals);}

Account::Account(int initial_deposit)
{
	this->_totalAmount += initial_deposit;
	this->_amount = initial_deposit;
	this->_accountIndex = this->_nbAccounts;
	this->_nbAccounts++;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
	this->_totalAmount += deposit;
	this->_amount += deposit;
	this->_totalNbDeposits++;
	this->_nbDeposits++;
	std::cout << ";deposit:" << deposit << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;

}

bool Account::makeWithdrawal(int withdrawal)
{

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
	if (this->_amount < withdrawal)
	{
		std::cout << ";withdrawal:" << "refused" << std::endl;
		return (false);
	}	
	this->_totalAmount -= withdrawal;
	this->_amount -= withdrawal;
	this->_totalNbWithdrawals++;
	this->_nbWithdrawals++;
	std::cout << ";withdrawal:" << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbDeposits << std::endl;
	return (true);
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount;
	std::cout << ";deposits:" << Account::_totalNbDeposits << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

int	Account::checkAmount()
const {
	return (1);
}
void Account::displayStatus()
const {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}
// [19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
