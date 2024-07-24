/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:14:37 by jhurpy            #+#    #+#             */
/*   Updated: 2024/07/24 11:54:52 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int	main(void)
{
	// test the Base class
	std::cout << "--------------------------------------" << std::endl;
	Base *base = generate();
	identify(base);
	identify(*base);
	delete base;
	std::cout << "--------------------------------------" << std::endl;
	return 0;
}

// https://cplusplus.com/doc/oldtutorial/typecasting/
