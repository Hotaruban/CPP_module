/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 22:21:43 by jhurpy            #+#    #+#             */
/*   Updated: 2024/05/03 01:55:33 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << "----------------------" << std::endl;
	{
		Bureaucrat bureaucrat1("Asterix", 1);
		std::cout << bureaucrat1 << std::endl;
		Form form1("A38", 50, 50);
		std::cout << form1 << std::endl;
		form1.signForm(bureaucrat1);
		std::cout << form1 << std::endl;
	}
	std::cout << "----------------------" << std::endl;
	{
		Bureaucrat bureaucrat2("Obelix", 51);
		std::cout << bureaucrat2 << std::endl;
		Form form2("A38", 50, 50);
		std::cout << form2 << std::endl;
		form2.signForm(bureaucrat2);
		bureaucrat2.incrementGrade();
		form2.signForm(bureaucrat2);
		std::cout << form2 << std::endl;
	}
	std::cout << "----------------------" << std::endl;
	{
		Bureaucrat bureaucrat3("Panoramix", 0);
		std::cout << bureaucrat3 << std::endl;
		Form form3("A38", 50, 50);
		std::cout << form3 << std::endl;
		form3.signForm(bureaucrat3);
	}

	return (0);
}
