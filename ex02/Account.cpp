/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpizarro <jpizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:38:32 by jpizarro          #+#    #+#             */
/*   Updated: 2023/03/21 20:51:15 by jpizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int accountIndex = 0;

Account::Account( void ) :
_accountIndex(accountIndex++),
_amount(0),
_nbDeposits(0),
_nbWithdrawals(0)
{
	this->_nbAccounts++;
	this->_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";created"
		<< std::endl;
	return;
}

Account::Account(int initial_deposit) :
_accountIndex(accountIndex++),
_amount(initial_deposit),
_nbDeposits(0),
_nbWithdrawals(0)
{
	this->_nbAccounts++;
	this->_totalAmount += this->_amount;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this ->_amount << ";created" << std::endl;
	return;
}

Account::~Account( void ) {
	Account::_nbAccounts--;
	Account::_totalAmount -= this->_amount;
	Account::_totalNbDeposits -= this->_nbDeposits;
	Account::_totalNbWithdrawals -= this->_nbWithdrawals;
	this->_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";closed"
		<< std::endl;
	return;
}

int		Account::getNbAccounts( void ) {
	return Account::_nbAccounts;
}

int		Account::getTotalAmount( void ) {
	return Account::_totalAmount;
}

int		Account::getNbDeposits( void ) {
	return Account::_totalNbDeposits;
}

int		Account::getNbWithdrawals( void ) {
	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void ) {
	Account::_displayTimestamp();
	std::cout
		<< "accounts:" << Account::_nbAccounts
		<< ";total:" << Account::_totalAmount
		<< ";deposits:" << Account::_totalNbDeposits
		<< ";withdrawals:" << Account::_totalNbWithdrawals
		<< std::endl;
	return;
}

void	Account::makeDeposit( int deposit ) {
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	return;
}

bool	Account::makeWithdrawal(int withdrawal) {
	bool doable = this->_amount - withdrawal >= 0;

	if (doable) {
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
	}
	return doable;
}

int		Account::checkAmount( void ) const {
	return this->_amount;
}

void	Account::displayStatus( void ) const {
	Account::_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";deposits:" << this->_nbDeposits
		<< ";withdrawals:" << this->_nbWithdrawals
		<< std::endl;
	return;
}

void    Account::_displayTimestamp(void)
{
    time_t      tt;
    struct tm   *ti;

    std::time(&tt);
    ti = localtime(&tt);
    std::cout << "[";
    std::cout << ti->tm_year + 1900;
    std::cout << std::setw(2) << std::setfill('0') << ti->tm_mon + 1;
    std::cout << std::setw(2) << std::setfill('0') << ti->tm_mday << "_";
    std::cout << std::setw(2) << std::setfill('0') << ti->tm_hour;
    std::cout << std::setw(2) << std::setfill('0') << ti->tm_min;
    std::cout << std::setw(2) << std::setfill('0') << ti->tm_sec;
    std::cout <<"] ";
}
