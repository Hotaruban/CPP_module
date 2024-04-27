/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 09:56:58 by jhurpy            #+#    #+#             */
/*   Updated: 2024/04/27 18:24:17 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(const std::string &type) : _type(type)
{
	std::cout << "AMateria " << this->_type << " parameter constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other)
{
	std::cout << "AMateria copy constructor called" << std::endl;
	*this = other;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}

const std::string &AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter &target)
{
	std::cout << this->_type << " has been cast on " << target.getName() << "." << std::endl;
}
