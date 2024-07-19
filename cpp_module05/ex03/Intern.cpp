/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 23:42:24 by jhurpy            #+#    #+#             */
/*   Updated: 2024/07/19 23:52:33 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{

}

Intern::Intern(const Intern & intern)
{
	(void)intern;
}

Intern::~Intern()
{

}

Intern & Intern::operator=(const Intern & intern)
{
	(void)intern;
	return *this;
}

AForm * Intern::makeForm(std::string formName, std::string target)
{
	if (formName == "shrubbery creation")
	{
		std::cout << "Intern creates " << formName << " form" << std::endl;
		return (new ShrubberyCreationForm(target));
	}
	else if (formName == "robotomy request")
	{
		std::cout << "Intern creates " << formName << " form" << std::endl;
		return (new RobotomyRequestForm(target));
	}
	else if (formName == "presidential pardon")
	{
		std::cout << "Intern creates " << formName << " form" << std::endl;
		return (new PresidentialPardonForm(target));
	}
	else
		throw Intern::UnknownFormException();
}
