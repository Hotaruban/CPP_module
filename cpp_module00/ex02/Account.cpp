/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 03:16:40 by jhurpy            #+#    #+#             */
/*   Updated: 2023/11/17 04:36:49 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_amount = initial_deposit;
	this->_accountIndex = _nbAccounts;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_totalAmount += initial_deposit;
	_nbAccounts++;
	Account::_displayTimestamp();
	std::cout << " index:" << BBLUE << this->_accountIndex << RESET << ";"
		<< "amount:" << BBLUE << this->_amount << RESET << ";"
		<< "created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << " index:" << BBLUE << this->_accountIndex << RESET << ";"
		<< "amount:" << BBLUE << this->_amount << RESET << ";"
		<< "closed" << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << " index:" << BBLUE << this->_accountIndex << RESET << ";"
		<< "p_amount:" << BBLUE << this->_amount << RESET << ";"
		<< "deposit:" << BBLUE << deposit << RESET << ";";
	this->_amount += deposit;
	this->_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << "amount:" << BBLUE << this->_amount << RESET << ";"
		<< "nb_deposits:" << BBLUE << this->_nbDeposits << RESET << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	if (this->_amount - withdrawal < 0)
	{
		std::cout << " index:" << BBLUE << this->_accountIndex << RESET << ";"
			<< "p_amount:" << BBLUE << this->_amount << RESET << ";"
			<< "withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		std::cout << " index:" << BBLUE << this->_accountIndex << RESET << ";"
			<< "p_amount:" << BBLUE << this->_amount << RESET << ";"
			<< "withdrawal:" << BBLUE << withdrawal << RESET << ";";
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		std::cout << "amount:" << BBLUE << this->_amount << RESET << ";"
			<< "nb_withdrawals:" << BBLUE << this->_nbWithdrawals << RESET
			<< std::endl;
		return (true);
	}
}

int		Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << " index:" << BBLUE << this->_accountIndex << RESET << ";"
		<< "amount:" << BBLUE << this->_amount << RESET << ";"
		<< "deposits:" << BBLUE << this->_nbDeposits << RESET << ";"
		<< "withdrawals:" << BBLUE << this->_nbWithdrawals << RESET
		<< std::endl;
}

int		Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int		Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int		Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int		Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " accounts:" << BBLUE << Account::getNbAccounts() << RESET << ";"
		<< "total:" << BBLUE << Account::getTotalAmount() << RESET << ";"
		<< "deposits:" << BBLUE << Account::getNbDeposits() << RESET << ";"
		<< "withdrawals:" << BBLUE << Account::getNbWithdrawals() << RESET
		<< std::endl;
}

void	Account::_displayTimestamp(void)
{
	std::time_t			currentTime;
	std::tm				*timeInfo;
	std::ostringstream	oss;

	currentTime = std::time(NULL);
	timeInfo = std::localtime(&currentTime);
	oss	<< "["
		<< std::setw(4) << std::setfill('0') << (timeInfo->tm_year + 1900)
		<< std::setw(2) << std::setfill('0') << (timeInfo->tm_mon + 1)
		<< std::setw(2) << std::setfill('0') << (timeInfo->tm_mday)
		<< "_"
		<< std::setw(2) << std::setfill('0') << (timeInfo->tm_hour)
		<< std::setw(2) << std::setfill('0') << (timeInfo->tm_min)
		<< std::setw(2) << std::setfill('0') << (timeInfo->tm_sec)
		<< "]";
	std::string formattedTime = oss.str();
	std::cout << formattedTime;
}
