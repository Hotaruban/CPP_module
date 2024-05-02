/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 22:21:43 by jhurpy            #+#    #+#             */
/*   Updated: 2024/05/03 00:56:32 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main(void)
{
		// Création d'un Bureaucrat avec un grade valide
		Bureaucrat bureaucrat1("John", 50);
		std::cout << "Bureaucrat 1: " << bureaucrat1 << std::endl;

		// Création d'un Bureaucrat avec un grade trop élevé (devrait générer une exception)
		Bureaucrat bureaucrat2("Jane", 0); // GradeTooHighException
		std::cout << "Bureaucrat 2: " << bureaucrat2 << std::endl;
		
	return 0;
}
