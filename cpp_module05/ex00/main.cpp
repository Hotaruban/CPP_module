/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 22:21:43 by jhurpy            #+#    #+#             */
/*   Updated: 2024/07/17 18:42:39 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main(void)
{
		// Création d'un Bureaucrat avec un grade valide
		std::cout << "Create a Bureaucrat with a grade: 50" << std::endl;
		try {
			Bureaucrat bureaucrat1("John", 50);
			std::cout << bureaucrat1 << std::endl;
			bureaucrat1.incrementGrade();
			std::cout << bureaucrat1 << std::endl;
		} catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
		std::cout << "--------------------------" << std::endl;
		// Création d'un Bureaucrat avec un grade trop élevé (devrait générer une exception)
		std::cout << "Try to create a Bureaucrat with a grade too high: 0" << std::endl;
		try {
			Bureaucrat bureaucrat2("Jane", 0); // GradeTooHighException
			std::cout << bureaucrat2 << std::endl;
		} catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
		std::cout << "--------------------------" << std::endl;
		// Création d'un Bureaucrat avec une décrémentation de grade trop basse (devrait générer une exception)
		std::cout << "Try to decrement a Bureaucrat with a grade: 150" << std::endl;
		try {
			Bureaucrat bureaucrat3("Jack", 150); // GradeTooLowException
			std::cout << bureaucrat3 << std::endl;
			bureaucrat3.decrementGrade();
			std::cout << bureaucrat3 << std::endl;
		} catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
		std::cout << "--------------------------" << std::endl;
		// Création d'un Bureaucrat avec un grade trop bas (devrait générer une exception)
		std::cout << "Try to create a Bureaucrat with a grade too low: 151" << std::endl;
		try {
			Bureaucrat bureaucrat4("Jill", 151); // GradeTooLowException
			std::cout << bureaucrat4 << std::endl;
		} catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
		std::cout << "--------------------------" << std::endl;

	return 0;
}
