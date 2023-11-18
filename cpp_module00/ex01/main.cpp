/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:33:12 by jhurpy            #+#    #+#             */
/*   Updated: 2023/11/14 02:13:02 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook phonebook;
	std::string	command;

	while (true && !std::cin.eof())
	{
		std::cout << BBLUE "Enter a command: " << BPURPLE;
		getline(std::cin, command);
		if (command.compare("ADD") == 0)
			phonebook.addContact();
		else if (command.compare("SEARCH") == 0)
			phonebook.searchContact();
		else if (command.compare("EXIT") == 0 || std::cin.eof())
			break ;
		else
			std::cout << BRED " -- Wrong command -- " << RESET << std::endl;
	}
	std::cout << BGREEN "\n 	-- EXIT -- \n" << RESET << std::endl;
	return (0);
}
