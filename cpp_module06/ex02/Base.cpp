/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:18:48 by jhurpy            #+#    #+#             */
/*   Updated: 2024/07/22 23:17:15 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base()
{

}

Base	*generate(void)
{
	// instantiate a random class A, B or C
	int random = rand() % 3;

	if (random == 0)
	{
		std::cout << "A random class has been generated" << std::endl;
		return new A;
	}
	else if (random == 1)
	{
		std::cout << "B random class has been generated" << std::endl;
		return new B;
	}
	else
	{
		std::cout << "C random class has been generated" << std::endl;
		return new C;
	}
}

void	identify(Base *ptr)
{
	// identify the class pointed by p

	std::cout << "Pointer is pointing to a class of type ";
}

void 	identify(Base &ref)
{
	// identify the class pointed by p

	std::cout << "Pointer is pointing to a class of type ";
}
