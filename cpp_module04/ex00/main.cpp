/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:42:25 by jhurpy            #+#    #+#             */
/*   Updated: 2024/02/26 14:30:50 by jhurpy           ###   ########.fr       */
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
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const Animal k = Cat();
	Cat l = Cat();

	std::cout << j->getType() << std::endl; // Returns "Dog"
	j->makeSound(); // Returns "Dog"
	std::cout << i->getType() << std::endl; // Returns "Cat"
	i->makeSound(); // Returns "Cat"
	meta->makeSound(); // Will output the animal sound!
	std::cout << k.getType() << std::endl; // Returns "Cat"
	k.makeSound(); // Returns "Cat"
	std::cout << l.getType() << std::endl; // Returns "Cat"
	l.makeSound(); // Returns "Cat"

	delete meta;
	delete j;
	delete i;

	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongJ = new WrongCat();

	std::cout << wrongJ->getType() << std::endl; // Returns "WrongCat"
	wrongJ->makeSound(); // Returns "WrongCat"
	wrongMeta->makeSound(); // Will output the animal sound!

	delete wrongMeta;
	delete wrongJ;

	return (0);
}
