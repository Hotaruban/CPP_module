/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:41:58 by jhurpy            #+#    #+#             */
/*   Updated: 2024/02/20 12:36:19 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Ceation of the living being of Animal" << std::endl;
}

Animal::Animal(const Animal& other)
{
	std::cout << "Copy of the living being of Animal" << std::endl;
	*this = other;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Assignation of the living being of Animal" << std::endl;
	if (this != &other)
	{
		this->setType(other.getType());
	}
	return (*this);
}

void Animal::makeSound() const
{

}

std::string Animal::getType() const
{
	return (type);
}

void Animal::setType(std::string type)
{
	this->type = type;
}

Animal::~Animal()
{
	std::cout << "Destruction of the living being of Animal" << std::endl;
}
