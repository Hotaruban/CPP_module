/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 00:31:42 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/02 02:04:26 by jhurpy           ###   ########.fr       */
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

void	Harl::complain(std::string level)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->level[i] == level)
		{
			(this->*speak[i])();
			return ;
		}
	}
}

void	Harl::debug(void)
{
	std::cout << BCYAN << "I love having friends who doing an effort to speak in English. I really do!" << RESET << std::endl;
}

void	Harl::info(void)
{
	std::cout << BGREEN << "I cannot accept to heard people say we are friend when they ignor me! I really hate that!" << RESET << std::endl;
}

void	Harl::warning(void)
{
	std::cout << BPURPLE << "I think I deserve better friend, than the people arround me actualy. Yes I really deserve it for myself." << RESET << std::endl;
}

void	Harl::error(void)
{
	std::cout << BRED << "This is unacceptable! I don't want speak to anyone here." << RESET << std::endl;
}
