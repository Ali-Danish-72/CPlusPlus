/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:35:46 by mdanish           #+#    #+#             */
/*   Updated: 2024/11/23 20:47:51 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Account.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
std::time_t times = std::time(NULL);
tm	*currentTime = localtime(&times);

Account::Account(void) {
	return;
}

Account::Account(int initial_deposit) {
	this->_accountIndex = Account::_nbAccounts++;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
	<< ";created\n";
	return;
}

Account::~Account(void) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
	<< ";closed\n";
	return;
}

int Account::getNbAccounts(void) {
	return Account::_nbAccounts;
}
int Account::getTotalAmount(void) {
	return Account::_totalAmount;
}
int Account::getNbDeposits(void) {
	return Account::_totalNbDeposits;
}
int Account::getNbWithdrawals(void) {
	return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos(void) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
	<< ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << '\n';
}

void Account::displayStatus(void) const {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
	<< ";deposits:" << this->_nbDeposits << ";withdrawals:"
	<< this->_nbWithdrawals << "\n";
}

void Account::makeDeposit(int deposit) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount
	<< ";deposit:" << deposit << ";amount:" << this->_amount + deposit
	<< ";nb_deposits:" << ++this->_nbDeposits << "\n";
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount
	<< ";withdrawal:";
	if (withdrawal > this->_amount) {
		std::cout << "refused\n";
		return false;
	}
	std::cout << withdrawal << ";amount:" << this->_amount - withdrawal
	<< ";nb_withdrawals:" << ++this->_nbWithdrawals << "\n";
	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	return true;
}

void Account::_displayTimestamp(void) {
	std::stringstream ss;
	ss << '[' << currentTime->tm_year + 1900
	<< std::setw(2) << std::setfill('0') << currentTime->tm_mon + 1
	<< std::setw(2) << std::setfill('0') << currentTime->tm_mday
	<< '_' << std::setw(2) << std::setfill('0') << currentTime->tm_hour
	<< std::setw(2) << std::setfill('0') << currentTime->tm_min
	<< std::setw(2) << std::setfill('0') << currentTime->tm_sec << "] ";
	std::cout << ss.str();
}
