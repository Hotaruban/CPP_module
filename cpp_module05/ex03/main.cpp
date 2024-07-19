/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 22:21:43 by jhurpy            #+#    #+#             */
/*   Updated: 2024/07/20 00:00:44 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	//std::cout << "----------------------" << std::endl;
	//try {
	//	Bureaucrat bureaucrat1("Asterix", 1);
	//	std::cout << bureaucrat1 << std::endl;
	//	ShrubberyCreationForm form1("A38");
	//	std::cout << form1 << std::endl;
	//	bureaucrat1.signForm(form1);
	//	bureaucrat1.executeForm(form1);
	//} catch (std::exception & e) {
	//	std::cout << e.what() << std::endl;
	//}
	//std::cout << "----------------------" << std::endl;
	//try {
	//	Bureaucrat bureaucrat1("Obelix", 138);
	//	std::cout << bureaucrat1 << std::endl;
	//	ShrubberyCreationForm form1("A37");
	//	std::cout << form1 << std::endl;
	//	bureaucrat1.signForm(form1);
	//	bureaucrat1.executeForm(form1);
	//} catch (std::exception & e) {
	//	std::cout << e.what() << std::endl;
	//}
	//std::cout << "----------------------" << std::endl;
	//try {
	//	Bureaucrat bureaucrat1("Gelbin Mekkanivelle", 1);
	//	std::cout << bureaucrat1 << std::endl;
	//	RobotomyRequestForm form1("Mechanical chicken");
	//	std::cout << form1 << std::endl;
	//	bureaucrat1.signForm(form1);
	//	bureaucrat1.executeForm(form1);
	//} catch (std::exception & e) {
	//	std::cout << e.what() << std::endl;
	//}
	//std::cout << "----------------------" << std::endl;
	//try {
	//	Bureaucrat bureaucrat1("Bureaucrat Vogon Junior", 42);
	//	std::cout << bureaucrat1 << std::endl;
	//	PresidentialPardonForm form1("Arthur Dent");
	//	std::cout << form1 << std::endl;
	//	bureaucrat1.signForm(form1);
	//	bureaucrat1.executeForm(form1);
	//} catch (std::exception & e) {
	//	std::cout << e.what() << std::endl;
	//}
	//std::cout << "----------------------" << std::endl;
	//try {
	//	Bureaucrat bureaucrat1("Bureaucrat Vogon Senior", 1);
	//	std::cout << bureaucrat1 << std::endl;
	//	PresidentialPardonForm form1("Ford Prefect");
	//	std::cout << form1 << std::endl;
	//	bureaucrat1.signForm(form1);
	//	bureaucrat1.executeForm(form1);
	//} catch (std::exception & e) {
	//	std::cout << e.what() << std::endl;
	//}
	//std::cout << "----------------------" << std::endl;

	Intern randomSlave;
	AForm *form1;
	AForm *form2;
	AForm *form3;

	try {
		std::cout << "----------------------" << std::endl;
		form1 = randomSlave.makeForm("shrubbery creation", "A38");
		std::cout << *form1 << std::endl;
		std::cout << "----------------------" << std::endl;
		form2 = randomSlave.makeForm("robotomy request", "Mechanical chicken");
		std::cout << *form2 << std::endl;
		std::cout << "----------------------" << std::endl;
		form3 = randomSlave.makeForm("presidential pardon", "Arthur Dent");
		std::cout << *form3 << std::endl;
		std::cout << "----------------------" << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat bureaucrat1("Asterix", 1);
		std::cout << bureaucrat1 << std::endl;
		Bureaucrat bureaucrat2("Gelbin Mekkanivelle", 1);
		std::cout << bureaucrat2 << std::endl;
		Bureaucrat bureaucrat3("Bureaucrat Vogon Senior", 1);
		std::cout << bureaucrat3 << std::endl;
		std::cout << "----------------------" << std::endl;
		bureaucrat1.signForm(*form1);
		bureaucrat2.signForm(*form2);
		bureaucrat3.signForm(*form3);
		std::cout << "----------------------" << std::endl;
		bureaucrat1.executeForm(*form1);
		bureaucrat2.executeForm(*form2);
		bureaucrat3.executeForm(*form3);
		std::cout << "----------------------" << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	delete form1;
	delete form2;
	delete form3;
	return (0);
}
