/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 23:41:25 by jhurpy            #+#    #+#             */
/*   Updated: 2024/07/19 23:52:06 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern & intern);
		~Intern();
		Intern & operator=(const Intern & intern);

		AForm * makeForm(std::string formName, std::string target);

		class UnknownFormException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Intern can't create unknown form.");
				}
		};
};

#endif
