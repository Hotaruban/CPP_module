/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:18:48 by jhurpy            #+#    #+#             */
/*   Updated: 2024/07/24 11:55:44 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base()
{

}

Base	*generate(void)
{
	// instantiate a random class A, B or C
	srand(time(NULL));
	int random = rand() % 3;

	switch (random)
	{
		case 0:
		{
			std::cout << "A random class has been generated" << std::endl;
			return new A;
		}
		case 1:
		{
			std::cout << "B random class has been generated" << std::endl;
			return new B;
		}
		case 2:
		{
			std::cout << "C random class has been generated" << std::endl;
			return new C;
		}
	}
	return NULL;
}

void	identify(Base *ptr)
{
	// identify the class pointed by ptr
	if (dynamic_cast<A*>(ptr))
		std::cout << "It's an A" << std::endl;
	else if (dynamic_cast<B*>(ptr))
		std::cout << "It's a B" << std::endl;
	else if (dynamic_cast<C*>(ptr))
		std::cout << "It's a C" << std::endl;
	else
		std::cout << "Itsumi Mario!, and it's not A, B or C" << std::endl;
}

void 	identify(Base &ref)
{
	// identify the class referenced by ref
	identify(&ref);
}
