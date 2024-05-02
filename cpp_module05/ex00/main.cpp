/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 22:21:43 by jhurpy            #+#    #+#             */
/*   Updated: 2024/05/03 01:30:59 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main(void)
{
		// Création d'un Bureaucrat avec un grade valide
		Bureaucrat bureaucrat1("John", 50);
		std::cout << "Bureaucrat 1: " << bureaucrat1 << std::endl;
		bureaucrat1.incrementGrade();
		std::cout << "Bureaucrat 1: " << bureaucrat1 << std::endl;
		std::cout << "--------------------------" << std::endl;
		// Création d'un Bureaucrat avec un grade trop élevé (devrait générer une exception)
		Bureaucrat bureaucrat2("Jane", 0); // GradeTooHighException
		std::cout << "Bureaucrat 2: " << bureaucrat2 << std::endl;
		std::cout << "--------------------------" << std::endl;
		// Création d'un Bureaucrat avec une décrémentation de grade trop basse (devrait générer une exception)
		Bureaucrat bureaucrat3("Jack", 150); // GradeTooLowException
		std::cout << "Bureaucrat 3: " << bureaucrat3 << std::endl;
		bureaucrat3.decrementGrade();
		std::cout << "Bureaucrat 3: " << bureaucrat3 << std::endl;
		std::cout << "--------------------------" << std::endl;
		// Création d'un Bureaucrat avec un grade trop bas (devrait générer une exception)
		Bureaucrat bureaucrat4("Jill", 151); // GradeTooLowException
		std::cout << "Bureaucrat 4: " << bureaucrat4 << std::endl;
		std::cout << "--------------------------" << std::endl;

	return 0;
}
