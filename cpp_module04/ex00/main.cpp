/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:42:25 by jhurpy            #+#    #+#             */
/*   Updated: 2024/03/11 01:42:33 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int	main(void)
{
	const Animal* meta = new Animal();
	std::cout << "-----------------------------------" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "---------META ANIMAL---------" << std::endl;
	meta->makeSound(); // Will output the animal sound!
	std::cout << "---------DOG---------" << std::endl;
	std::cout << j->getType() << std::endl; // Returns "Dog"
	j->makeSound(); // Returns "Dog"
	std::cout << "---------CAT---------" << std::endl;
	std::cout << i->getType() << std::endl; // Returns "Cat"
	i->makeSound(); // Returns "Cat"
	std::cout << "-----------------------------------" << std::endl;

	delete meta;
	delete j;
	delete i;

	std::cout << "-----------------------------------" << std::endl;

	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongJ = new WrongCat();

	std::cout << wrongJ->getType() << std::endl; // Returns "WrongCat"
	wrongJ->makeSound(); // Returns "WrongCat"
	wrongMeta->makeSound(); // Will output the animal sound!

	delete wrongMeta;
	delete wrongJ;

	return (0);
}
