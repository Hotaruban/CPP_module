/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 13:28:12 by jhurpy            #+#    #+#             */
/*   Updated: 2024/09/13 20:37:20 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"

// Use containers std::stack because it is a container adapter that gives the programmer the functionality of a stack
// - specifically, a LIFO (last-in, first-out) data structure who is the most suitable for the Reverse Polish Notation

int	main(int ac, char **av)
{
	try {
		if (ac != 2)
			throw std::invalid_argument("Usage: ./RPN \"[expression]\"");

		RPN rpn(av[1]);

	} catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
