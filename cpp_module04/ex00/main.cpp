/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:42:25 by jhurpy            #+#    #+#             */
/*   Updated: 2024/02/17 12:50:27 by jhurpy           ###   ########.fr       */
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

	std::cout << j->getType() << std::endl; // Returns "Dog"
	j->makeSound(); // Returns "Dog"
	std::cout << i->getType() << std::endl; // Returns "Cat"
	i->makeSound(); // Returns "Cat"
	meta->makeSound(); // Will output the animal sound!

	delete meta;
	delete j;
	delete i;

	return (0);
}
