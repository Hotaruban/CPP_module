/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:22:40 by jhurpy            #+#    #+#             */
/*   Updated: 2024/07/19 21:26:24 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string const name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	this->_signed = false;
}

AForm::AForm(AForm const & src) : _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
	*this = src;
}

AForm::~AForm()
{
	std::cout << "Form " << _name << " is burned forever." << std::endl;
}

AForm & AForm::operator=(AForm const & src)
{
	this->_signed = src._signed;
	return (*this);
}

std::ostream & operator<<(std::ostream & os, AForm const & form)
{
	if (form.getSigned())
		os << "Form " << form.getName() << " is signed";
	else
		os << "Form " << form.getName() << " is not signed and requires grade " << form.getGradeToSign() << " or more to be signed and grade " << form.getGradeToExecute() << " or more to be executed.";
	return (os);
}

std::string const AForm::getName() const
{
	return (this->_name);
}

bool AForm::getSigned() const
{
	return (this->_signed);
}

int AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

void AForm::beSigned(const Bureaucrat & bureaucrat)
{
	// check if level of bureaucrat is high enough to sign the form
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw GradeTooHighException();
	this->_signed = true;
}
