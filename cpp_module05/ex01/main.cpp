/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 22:21:43 by jhurpy            #+#    #+#             */
/*   Updated: 2024/05/02 13:05:27 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	//try
	//{
	//	// Création d'un Bureaucrat avec un grade valide
	//	Bureaucrat bureaucrat1("Asterix", 50);
	//	std::cout << "Aterix : " << bureaucrat1 << std::endl;

	//	// Création d'un Bureaucrat avec un grade trop élevé (devrait générer une exception)
	//	Bureaucrat bureaucrat2("Obelix", 0); // GradeTooHighException
	//} catch (std::exception &e)
	//{
	//	std::cerr << "Exception caught: " << e.what() << std::endl;
	//}

	//try
	//{
	//	// Création d'un Bureaucrat avec un grade trop bas (devrait générer une exception)
	//	Bureaucrat bureaucrat3("Panoramix", 151); // GradeTooLowException
	//} catch (std::exception &e)
	//{
	//	std::cerr << "Exception caught: " << e.what() << std::endl;
	//}
	Bureaucrat bureaucrat1("Asterix", 50);
	Form form1("A38", 50, 50);
	std::cout << form1 << std::endl;
	form1.beSigned(bureaucrat1);
	std::cout << form1 << std::endl;

	return 0;
}
