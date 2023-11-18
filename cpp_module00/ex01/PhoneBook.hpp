/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 02:04:43 by jhurpy            #+#    #+#             */
/*   Updated: 2023/11/18 17:23:20 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define RESET		"\033[0m"
# define BBLUE		"\033[1;34m"
# define BRED		"\033[1;31m"
# define BGREEN		"\033[1;32m"
# define BYELLOW	"\033[1;33m"
# define BCYAN		"\033[1;36m"
# define BPURPLE	"\033[1;35m"

class PhoneBook
{
	private:
		Contact			contacts[8];
		std::string		typeInfo[5];
	public:
		PhoneBook();
		~PhoneBook();
		int				CountContacts;
		int				CountContactsPhoneBook;
		void			addContact(void);
		void			searchContact(void);
		void			displayPhonebook(void);
		void			displayContact(int index);
		int				errorIndex(int index);
		std::string		maxWidth(std::string str);
};

#endif
