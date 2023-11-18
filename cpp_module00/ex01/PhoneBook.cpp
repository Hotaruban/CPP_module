/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 02:04:40 by jhurpy            #+#    #+#             */
/*   Updated: 2023/11/18 17:21:12 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	CountContacts = 0;
	CountContactsPhoneBook = 0;
	this->typeInfo[0] = "Enter first name:	";
	this->typeInfo[1] = "Enter last name:	";
	this->typeInfo[2] = "Enter nickname:		";
	this->typeInfo[3] = "Enter phone number:	";
	this->typeInfo[4] = "Enter darkest secret:	";
}

PhoneBook::~PhoneBook(void)
{
	std::cout << BGREEN "-- Phonebook destroyed --" << RESET << std::endl;
	std::cout << BRED "-- All contacts are lost --" << RESET << std::endl;
}

void	PhoneBook::addContact(void)
{
	Contact		contact;
	std::string	input[5];

	std::cout << BCYAN " -- Add contact -- " << RESET << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << BBLUE << this->typeInfo[i] << BPURPLE;
		std::getline(std::cin, input[i]);
		if (input[i].empty())
		{
			i--;
			std::cout << BRED " -- Wrong input can not be empty -- " << RESET << std::endl;
		}
	}
	contact.saveData(input);
	if (this->CountContacts < 8)
	{
		if (this->CountContacts < 8 && this->CountContactsPhoneBook < 8)
			CountContactsPhoneBook++;
		this->contacts[this->CountContacts] = contact;
		this->CountContacts++;
		if (this->CountContacts == 8)
			this->CountContacts = 0;
	}
	std::cout << BGREEN " -- Contact added -- " << RESET << std::endl;
}

void	PhoneBook::displayPhonebook(void)
{
	if (this->CountContacts == -1)
		return (std::cout << BRED " -- No contacts found -- " << RESET << std::endl, void());
	else
	{
		std::cout << RESET "O-------------------------------------------O" << std::endl;
		std::cout << "|  index   |first name| last name| nickname |" << std::endl;
		std::cout << "O----------+----------+----------+----------O" << std::endl;
		for(int i = 0; i < this->CountContactsPhoneBook; i++)
		{
			std::cout << "|" << std::setw(10) << std::right << i << "|";
			std::cout << std::setw(10) << std::right << maxWidth(this->contacts[i].getFirstName()) << "|";
			std::cout << std::setw(10) << std::right << maxWidth(this->contacts[i].getLastName()) << "|";
			std::cout << std::setw(10) << std::right << maxWidth(this->contacts[i].getNickname()) << "|" << std::endl;
		}
		std::cout << "O-------------------------------------------O" << std::endl;
	}
}

void	PhoneBook::displayContact(int index)
{
	std::cout << BCYAN " -- Contact info -- " << RESET << std::endl;
	std::cout << BBLUE "First name:	" << RESET << this->contacts[index].getFirstName() << std::endl;
	std::cout << BBLUE "Last name:	" << RESET << this->contacts[index].getLastName() << std::endl;
	std::cout << BBLUE "Nickname:	" << RESET << this->contacts[index].getNickname() << std::endl;
	std::cout << BBLUE "Phone number:	" << RESET << this->contacts[index].getPhoneNumber() << std::endl;
	std::cout << BBLUE "Darkest secret:	" << RESET << this->contacts[index].getDarkestSecret() << std::endl;
}

void	PhoneBook::searchContact(void)
{
	int	index;
	std::string	userInput;

	std::cout << BCYAN " -- Search contact -- " << RESET << std::endl;
	displayPhonebook();
	index = -1;
	for (int i = 0; i < 4; i++)
	{
		std::cout << BBLUE "Enter index:	" << RESET;
		std::getline(std::cin, userInput);
		if (userInput.empty() || !std::all_of(userInput.begin(), userInput.end(), ::isdigit))
		{
			if (i == 3)
				return (std::cin.clear(), void()) ;
			std::cout << BRED " 	-- Wrong index -- " << RESET << std::endl;
			std::cout << BRED " -- You have " << 3 - i << " more attempts -- " << RESET << std::endl;
		}
		else
		{
			std::istringstream iss(userInput);
			if (iss >> index && index >= 0 && index <= 8 & index < CountContactsPhoneBook)
				return (displayContact(index), void());
			else
			{
				if (i == 3)
					return (std::cin.clear(), void());
				std::cout << BRED " 	-- Wrong index -- " << RESET << std::endl;
				std::cout << BRED " -- You have " << 3 - i << " more attempts -- " << RESET << std::endl;
				std::cin.clear();
			}
		}
	}
}

std::string	PhoneBook::maxWidth(std::string str)
{
	if (str.length() > 10)
	{
		str.resize(9);
		str.append(".");
	}
	return (str);
}
