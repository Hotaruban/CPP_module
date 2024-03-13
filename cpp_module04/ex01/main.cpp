/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:42:25 by jhurpy            #+#    #+#             */
/*   Updated: 2024/03/12 17:45:25 by jhurpy           ###   ########.fr       */
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
	//const Animal* meta = new Animal();
	//std::cout << "-----------------------------------" << std::endl;
	//const Animal* j = new Dog();
	//const Animal* i = new Cat();

	//std::cout << "---------META ANIMAL---------" << std::endl;
	//meta->makeSound(); // Will output the animal sound!
	//std::cout << "---------DOG---------" << std::endl;
	//std::cout << j->getType() << std::endl; // Returns "Dog"
	//j->makeSound(); // Returns "Dog"
	//std::cout << "---------CAT---------" << std::endl;
	//std::cout << i->getType() << std::endl; // Returns "Cat"
	//i->makeSound(); // Returns "Cat"
	//std::cout << "-----------------------------------" << std::endl;

	//delete meta;
	//delete j;
	//delete i;

	//std::cout << "-----------------------------------" << std::endl;

	const Animal* arrayAnimal[4];

	for (int i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
			arrayAnimal[i] = new Cat();
		else
			arrayAnimal[i] = new Dog();
	}
	for (int i = 0; i < 4; i++)
	{
		std::cout << arrayAnimal[i]->getType() << std::endl;
		arrayAnimal[i]->makeSound();
		delete arrayAnimal[i];
	}

	//std::cout << bigcat.getType() << std::endl; // Returns "Cat"
	//std::cout << bigcat.getBrain()->getIdea(5) << std::endl; // Returns "Idea 0"
	//bigcat.makeSound(); // Returns "Meow Meow"
	//std::cout << bigdog.getType() << std::endl; // Returns "Dog"
	//std::cout << bigdog.getBrain()->getIdea(5) << std::endl; // Returns "Idea 0"
	//bigdog.getBrain()->setIdea(5, "Where is that fucking Cat?");
	//std::cout << "Dog change is idea!" << std::endl;
	//std::cout << bigdog.getBrain()->getIdea(5) << std::endl;
	//bigdog.makeSound(); // Returns "Woof Woof"

	//const WrongAnimal* wrongMeta = new WrongAnimal();
	//const WrongAnimal* wrongJ = new WrongCat();

	//std::cout << wrongJ->getType() << std::endl; // Returns "WrongCat"
	//wrongJ->makeSound(); // Returns "WrongCat"
	//wrongMeta->makeSound(); // Will output the animal sound!

	//delete wrongMeta;
	//delete wrongJ;

	return (0);
}
