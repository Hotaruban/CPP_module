/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:22:40 by jhurpy            #+#    #+#             */
/*   Updated: 2024/05/03 02:19:51 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string const name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	this->_signed = false;
}

Form::Form(Form const & src) : _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
	*this = src;
}

Form::~Form()
{
	std::cout << "Form " << _name << " is burned forever." << std::endl;
}

Form & Form::operator=(Form const & src)
{
	this->_signed = src._signed;
	return (*this);
}

std::string const Form::getName() const
{
	return (this->_name);
}

bool Form::getSigned() const
{
	return (this->_signed);
}

int Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

void Form::beSigned(Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	std::cout << bureaucrat.getName() << " signs form: " << this->_name << std::endl;
	this->_signed = true;
}

void Form::signForm(Bureaucrat const & bureaucrat)
{
	try
	{
		if (bureaucrat.getGrade() < 1 || bureaucrat.getGrade() > 150)
			throw "Grade is out of range.";
		else if (bureaucrat.getGrade() > this->_gradeToSign)
			throw Bureaucrat::GradeTooLowException();
		this->beSigned(bureaucrat);
	}
	catch (std::exception & e)
	{
		std::cerr << bureaucrat.getName() << " couldn't sign form: " << this->_name << " because " << e.what() << std::endl;
	}
	catch (const char* msg)
	{
		std::cerr << bureaucrat.getName() << " couldn't sign form: " << this->_name << " because " << msg << std::endl;
	}
}

std::ostream & operator<<(std::ostream & os, Form const & form)
{
	if (form.getSigned())
		os << "Form " << form.getName() << " is signed";
	else
		os << "Form " << form.getName() << " is not signed and requires grade " << form.getGradeToSign() << " or more to be signed and grade " << form.getGradeToExecute() << " or more to be executed.";
	return (os);
}
