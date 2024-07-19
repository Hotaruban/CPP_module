/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 22:21:43 by jhurpy            #+#    #+#             */
/*   Updated: 2024/07/19 21:26:34 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main(void)
{
	std::cout << "----------------------" << std::endl;
	try {
		Bureaucrat bureaucrat1("Asterix", 1);
		std::cout << bureaucrat1 << std::endl;
		AForm form1("A38", 50, 50);
		std::cout << form1 << std::endl;
		bureaucrat1.signForm(form1);
		std::cout << form1 << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "----------------------" << std::endl;






	return (0);
}
