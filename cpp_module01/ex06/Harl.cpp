/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 00:31:42 by jhurpy            #+#    #+#             */
/*   Updated: 2024/02/15 17:10:27 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	std::cout << BBLUE << "Harl is here!" << RESET << std::endl;
	this->level[0] = "DEBUG";
	this->level[1] = "INFO";
	this->level[2] = "WARNING";
	this->level[3] = "ERROR";
	this->speak[0] = &Harl::debug;
	this->speak[1] = &Harl::info;
	this->speak[2] = &Harl::warning;
	this->speak[3] = &Harl::error;
}

Harl::~Harl(void)
{
	std::cout << BBLUE << "Harl is gone!" << RESET << std::endl;
}

int	Harl::complain(std::string level)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->level[i] == level)
			return (i);
	}
	return (-1);
}

void	Harl::complainFilter(std::string level)
{
	switch (Harl::complain(level))
	{
		case 0:
			(this->*speak[0])();
		case 1:
			(this->*speak[1])();
		case 2:
			(this->*speak[2])();
		case 3:
			(this->*speak[3])();
			break;
		default:
			std::cout << BRED << "Usage: ./harl [level] => {DEBUG, INFO, WARNING, ERROR}" << RESET << std::endl;
			break;
	}
}

void	Harl::debug(void)
{
	std::cout << BCYAN << "[DEBUG]" << RESET << std::endl;
	std::cout << BCYAN << "I love having friends who doing an effort to speak in English." << RESET << std::endl;
	std::cout << BCYAN << "I really do!" << RESET << std::endl;
}

void	Harl::info(void)
{
	std::cout << BGREEN << "[INFO]" << RESET << std::endl;
	std::cout << BGREEN << "I cannot accept to heard people say we are friend when they ignor me!" << RESET << std::endl;
	std::cout << BGREEN << "I really hate that!" << RESET << std::endl;
}

void	Harl::warning(void)
{
	std::cout << BPURPLE << "[WARNING]" << RESET << std::endl;
	std::cout << BPURPLE << "I think I deserve better friend, than the people arround me actualy. Yes I really deserve it for myself." << RESET << std::endl;
	std::cout << BPURPLE << "I'm not a bad person, I'm just a person who is tired of being ignored." << RESET << std::endl;
}

void	Harl::error(void)
{
	std::cout << BRED << "[ERROR]" << RESET << std::endl;
	std::cout << BRED << "This is unacceptable!" << RESET << std::endl;
	std::cout << BRED << "I don't want to be here anymore!" << RESET << std::endl;
}
