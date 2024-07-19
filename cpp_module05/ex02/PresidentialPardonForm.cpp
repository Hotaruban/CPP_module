/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 23:21:25 by jhurpy            #+#    #+#             */
/*   Updated: 2024/07/19 23:24:31 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & src) : AForm(src), _target(src._target)
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm & src)
{
	if (this != &src)
	{
		AForm::operator=(src);
	}
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << _target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
