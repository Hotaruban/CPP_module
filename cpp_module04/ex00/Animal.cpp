/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:41:58 by jhurpy            #+#    #+#             */
/*   Updated: 2024/02/17 12:47:12 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Ceation of the living being of Animal" << std::endl;
}

Animal::Animal(const Animal& other)
{
	type = other.type;
	std::cout << "Copy of the living being of Animal" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Assignation of the living being of Animal" << std::endl;
	if (this != &other)
	{
		type = other.type;
	}
	return *this;
}

void Animal::makeSound() const
{

}

std::string Animal::getType() const
{
	return (type);
}

Animal::~Animal()
{
	std::cout << "Destruction of the living being of Animal" << std::endl;
}
