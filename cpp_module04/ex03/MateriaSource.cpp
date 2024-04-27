/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:14:03 by jhurpy            #+#    #+#             */
/*   Updated: 2024/04/27 20:04:10 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		this->_stockMateria[i] = NULL;
	std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	*this = other;
	std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		if (this->_stockMateria[i])
			delete this->_stockMateria[i];
	std::cout << "MateriaSource destructor called" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
		for (int i = 0; i < 4; i++)
		{
			delete this->_stockMateria[i];
			if (other._stockMateria[i])
				this->_stockMateria[i] = other._stockMateria[i]->clone();
			else
				this->_stockMateria[i] = NULL;
		}
	std::cout << "MateriaSource assignation operator called" << std::endl;
	return (*this);
}

void MateriaSource::learnMateria(AMateria *materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->_stockMateria[i])
		{
			this->_stockMateria[i] = materia;
			std::cout << "Materia learned " << this->_stockMateria[i]->getType() << std::endl;
			return ;
		}
	}
	std::cout << "MateriaSource is full" << std::endl;
	delete materia;
}

AMateria *MateriaSource::createMateria(std::string const& type)
{
	for(int i = 0; i < 4; i++)
	{
		if (this->_stockMateria[i] && this->_stockMateria[i]->getType() == type)
			return (this->_stockMateria[i]->clone());
	}
	std::cout << "Materia not found" << std::endl;
	return (NULL);
}
