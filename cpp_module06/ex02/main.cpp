/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:14:37 by jhurpy            #+#    #+#             */
/*   Updated: 2024/07/22 23:08:04 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2 && (argv[1][0] < '1' || argv[1][0] > '7'))
	{
		std::cerr << "Enter a number between 1 and 7 has argument" << std::endl;
	}
	int n = argv[1][0] - '0';
	// test the Base class
	for (int i = 0; i < n; i++)
	{
		Base *base = generate();
		std::cout << "Pointer is pointing to a class of type";
		identify(base);
		std::cout << "Reference is pointing to a class of type";
		identify(*base);
		delete base;
	}
	return 0;
}

// https://cplusplus.com/doc/oldtutorial/typecasting/
