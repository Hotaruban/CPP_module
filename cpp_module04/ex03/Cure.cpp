/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:06:57 by jhurpy            #+#    #+#             */
/*   Updated: 2024/04/27 17:28:45 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other)
{
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure::~Cure(void)
{
	std::cout << "Cure destructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &other)
{
	std::cout << "Cure assignation operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other.getType();
	}
	return (*this);
}

AMateria *Cure::clone(void) const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
