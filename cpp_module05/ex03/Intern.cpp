/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 23:42:24 by jhurpy            #+#    #+#             */
/*   Updated: 2024/07/24 14:28:11 by jhurpy           ###   ########.fr       */
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

Intern::FormType Intern::getFormType(const std::string formName)
{
	if (formName == "shrubbery creation")
		return (SHRUBBERY);
	if (formName == "robotomy request")
		return (ROBOTOMY);
	if (formName == "presidential pardon")
		return (PRESIDENTIAL);
	return (UNKNOWFORM);
}

AForm * Intern::makeForm(std::string formName, std::string target)
{
	FormType formType = getFormType(formName);

	switch (formType)
	{
		case SHRUBBERY:
			std::cout << "Intern creates " << formName << " form" << std::endl;
			return (new ShrubberyCreationForm(target));
		case ROBOTOMY:
			std::cout << "Intern creates " << formName << " form" << std::endl;
			return (new RobotomyRequestForm(target));
		case PRESIDENTIAL:
			std::cout << "Intern creates " << formName << " form" << std::endl;
			return (new PresidentialPardonForm(target));
		default:
			throw Intern::UnknownFormException();
	}
}
