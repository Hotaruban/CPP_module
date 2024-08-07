/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 22:21:43 by jhurpy            #+#    #+#             */
/*   Updated: 2024/07/19 23:31:24 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	std::cout << "----------------------" << std::endl;
	try {
		Bureaucrat bureaucrat1("Asterix", 1);
		std::cout << bureaucrat1 << std::endl;
		ShrubberyCreationForm form1("A38");
		std::cout << form1 << std::endl;
		bureaucrat1.signForm(form1);
		bureaucrat1.executeForm(form1);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "----------------------" << std::endl;
	try {
		Bureaucrat bureaucrat1("Obelix", 138);
		std::cout << bureaucrat1 << std::endl;
		ShrubberyCreationForm form1("A37");
		std::cout << form1 << std::endl;
		bureaucrat1.signForm(form1);
		bureaucrat1.executeForm(form1);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "----------------------" << std::endl;
	try {
		Bureaucrat bureaucrat1("Gelbin Mekkanivelle", 1);
		std::cout << bureaucrat1 << std::endl;
		RobotomyRequestForm form1("Mechanical chicken");
		std::cout << form1 << std::endl;
		bureaucrat1.signForm(form1);
		bureaucrat1.executeForm(form1);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "----------------------" << std::endl;
	try {
		Bureaucrat bureaucrat1("Bureaucrat Vogon Junior", 42);
		std::cout << bureaucrat1 << std::endl;
		PresidentialPardonForm form1("Arthur Dent");
		std::cout << form1 << std::endl;
		bureaucrat1.signForm(form1);
		bureaucrat1.executeForm(form1);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "----------------------" << std::endl;
	try {
		Bureaucrat bureaucrat1("Bureaucrat Vogon Senior", 1);
		std::cout << bureaucrat1 << std::endl;
		PresidentialPardonForm form1("Ford Prefect");
		std::cout << form1 << std::endl;
		bureaucrat1.signForm(form1);
		bureaucrat1.executeForm(form1);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "----------------------" << std::endl;
	return (0);
}
