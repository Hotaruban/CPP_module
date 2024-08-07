/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:12:19 by jhurpy            #+#    #+#             */
/*   Updated: 2024/08/07 14:32:40 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"

int	main(void)
{
	class span span(5);

	try {
		span.addNumber(5);
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

	std::cout << "----------------" << std::endl;
	std::cout << span.longestSpan() << std::endl;
	std::cout << span.shortestSpan() << std::endl;
	std::cout << "----------------" << std::endl;

	try {
		span.addNumber(13);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
