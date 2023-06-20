// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	_nbAccounts = 0;
int	_totalAmount = 0;
int	_totalNbDeposits = 0;
int	_totalNbWithdrawals = 0;

void ft_time() 
{
    char buffer[20];

    std::time_t now = std::time(nullptr);
    std::tm* current_time = std::localtime(&now);
    std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", current_time);
    std::cout << "[" << buffer << "]";
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
	this->_totalNbDeposits++;
	this->_amount = initial_deposit;
	this->_nbDeposits++;
	this->_accountIndex = this->_nbAccounts;
	this->_nbAccounts++;
	ft_time();
	std::cout << "Index:" << this->_accountIndex << ";amount:" << this->_amount << ";created";
}

void Account::makeDeposit(int deposit)
{
	
}

Account::~Account()
{
	ft_time();
	std::cout << "Index:" << this->_accountIndex << ";amount:" << this->_amount << ";close";
}

void Account::displayAccountsInfos()
{
	ft_time;
	std::cout << "accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount;
	std::cout << ";deposits:" << Account::_totalNbDeposits << ";withdrawals:" << Account::_totalNbWithdrawals;
}
	
