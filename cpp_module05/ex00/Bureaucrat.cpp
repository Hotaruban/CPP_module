/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 22:21:48 by jhurpy            #+#    #+#             */
/*   Updated: 2024/05/03 01:37:37 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
	std::cout << "Bureaucrat " << name << " is born." << std::endl;
	try
	{
		if (grade < 1)
			throw GradeTooHighException();
		if (grade > 150)
			throw GradeTooLowException();
		this->_grade = grade;
	} catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src._name)
{
	*this = src;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << _name << " is dead." << std::endl;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & src)
{
	this->_grade = src._grade;
	return (*this);
}

std::ostream & operator<<(std::ostream & os, Bureaucrat const & bureaucrat)
{
	try
	{
		if (bureaucrat.getGrade() < 1)
			throw Bureaucrat::GradeTooHighException();
		if (bureaucrat.getGrade() > 150)
			throw Bureaucrat::GradeTooLowException();
		os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	} catch(const std::exception& e)
	{
		std::cerr << bureaucrat.getName() << " is " << e.what();
	}
	return (os);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

void Bureaucrat::incrementGrade()
{
	std::cout << this->_name << " get promoted." << std::endl;
	try
	{
		if (this->_grade == 150)
			throw GradeTooLowException();
		this->_grade--;
	} catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void Bureaucrat::decrementGrade()
{
	std::cout << this->_name << " get demoted." << std::endl;
	try
	{
		if (this->_grade == 1)
			throw GradeTooHighException();
		this->_grade++;
	} catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
