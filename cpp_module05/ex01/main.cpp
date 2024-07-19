/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 22:21:43 by jhurpy            #+#    #+#             */
/*   Updated: 2024/07/19 19:17:55 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << "----------------------" << std::endl;
	try {
		Bureaucrat bureaucrat1("Asterix", 1);
		std::cout << bureaucrat1 << std::endl;
		Form form1("A38", 50, 50);
		std::cout << form1 << std::endl;
		bureaucrat1.signForm(form1);
		std::cout << form1 << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "----------------------" << std::endl;
	try {
		Bureaucrat bureaucrat2("Obelix", 51);
		std::cout << bureaucrat2 << std::endl;
		Form form2("A38", 50, 50);
		std::cout << form2 << std::endl;
		bureaucrat2.signForm(form2);
		bureaucrat2.incrementGrade();
		bureaucrat2.signForm(form2);
		std::cout << form2 << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "----------------------" << std::endl;
	try {
		Bureaucrat bureaucrat3("Panoramix", 0);
		std::cout << bureaucrat3 << std::endl;
		Form form3("A38", 50, 50);
		std::cout << form3 << std::endl;
		bureaucrat3.signForm(form3);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "----------------------" << std::endl;
	try {
		Bureaucrat bureaucrat4("Idefix", 150);
		std::cout << bureaucrat4 << std::endl;
		Form form4("A38", 150, 151);
		std::cout << form4 << std::endl;
		bureaucrat4.signForm(form4);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "----------------------" << std::endl;
	return (0);
}
