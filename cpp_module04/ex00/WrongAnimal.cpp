/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:42:32 by jhurpy            #+#    #+#             */
/*   Updated: 2024/02/26 14:31:25 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongLiving being created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	type = other.type;
	std::cout << "Copy of the WrongLiving being" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "Assignation of the WrongLiving being" << std::endl;
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "I'm a wrong animal ..." << std::endl;
}

std::string WrongAnimal::getType() const
{
	return(type);
}

void WrongAnimal::setType(std::string type)
{
	this->type = type;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongLiving being destroyed" << std::endl;
}
