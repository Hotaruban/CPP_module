/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 09:54:27 by jhurpy            #+#    #+#             */
/*   Updated: 2024/04/27 18:29:44 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int	main(void)
{
	IMateriaSource* src = new MateriaSource();

	std::cout << "-----------------------------" << std::endl;

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << "-----------------------------" << std::endl;

	ICharacter* me = new Character("me");

	std::cout << "-----------------------------" << std::endl;

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout << "-----------------------------" << std::endl;

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << "-----------------------------" << std::endl;

	delete bob;

	std::cout << "-----------------------------" << std::endl;

	delete me;

	std::cout << "-----------------------------" << std::endl;

	delete src;

	return (0);
}
