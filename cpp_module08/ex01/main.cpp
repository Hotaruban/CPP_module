/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:12:19 by jhurpy            #+#    #+#             */
/*   Updated: 2024/08/15 20:27:30 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"

int	main(void)
{
	std::cout << "----------------" << std::endl;
	std::cout << "Try test from the subject" << std::endl;
	class span span(5);
	try {
		span.addNumber(6);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		span.addNumber(3);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		span.addNumber(17);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		span.addNumber(9);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		span.addNumber(11);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "Shortest span:\t" << span.shortestSpan() << std::endl;
	std::cout << "Longest span:\t" << span.longestSpan() << std::endl;
	std::cout << "Try to add a number to a full span" << std::endl;
	try {
		span.addNumber(13);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "----------------" << std::endl;
	std::cout << "Try to get span with only one number" << std::endl;
	class span span2(1);
	try {
		span2.shortestSpan();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		span2.longestSpan();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "----------------" << std::endl;


	int number = 10000;
	std::cout << "Try span with " << number << " number" << std::endl;

	class span span3(number);
	span3.forAddNumber(number);
	std::cout << "Shortest span:\t" << span3.shortestSpan() << std::endl;
	std::cout << "Longest span:\t" << span3.longestSpan() << std::endl;
	std::cout << "----------------" << std::endl;


	return 0;
}
