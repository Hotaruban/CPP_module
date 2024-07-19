/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 22:14:46 by jhurpy            #+#    #+#             */
/*   Updated: 2024/07/19 22:39:25 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm(src), _target(src._target)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src)
{
	if (this != &src)
	{
		AForm::operator=(src);
	}
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	try {
		if (this->getSigned() == false)
			throw AForm::FormNotSignedException();
		if (executor.getGrade() > this->getGradeToExecute())
			throw AForm::GradeTooLowException();
		std::ofstream file(this->_target + "_shrubbery");
		if (file.fail())
			throw FileNotAccessException();
		file << "ASCII trees" << std::endl;
		file.close();
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}
