/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:06:54 by jhurpy            #+#    #+#             */
/*   Updated: 2024/04/27 19:53:50 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const& name) : _name(name)
{
	for(int i = 0; i < SLOT; i++)
		this->_inventory[i] = NULL;
	for(int i = 0; i < 500; i++)
		this->_remainMateria[i] = NULL;
	std::cout << "Character " << this->_name << " constructor called" << std::endl;
}

Character::Character(const Character& other) : _name(other.getName())
{
	for(int i = 0; i < SLOT; i++)
	{
		if (other._inventory[i])
			this->_inventory[i] = other._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	std::cout << "Character copy constructor called" << std::endl;
}

Character::~Character(void)
{
	for(int i = 0; i < SLOT; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
	}
	for(int i = 0; i < 500; i++)
	{
		if (this->_remainMateria[i])
			delete this->_remainMateria[i];
		this->_remainMateria[i] = NULL;
	}
	std::cout << "Character " << this->_name << " destructor called" << std::endl;
}

Character& Character::operator=(const Character& other)
{
	if (this == &other)
		return (*this);
	this->_name = other._name;
	for(int i = 0; i < SLOT; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		if (other._inventory[i])
			this->_inventory[i] = other._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	std::cout << "Character assignation operator called" << std::endl;
	return (*this);
}

const std::string& Character::getName(void) const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	for(int i = 0; i < SLOT; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			std::cout << "Materia equipped" << std::endl;
			return ;
		}
	}
	std::cout << "Character inventory is full" << std::endl;
}

void Character::unequip(int index)
{
	if (index >= 0 && index < SLOT && this->_inventory[index])
	{
		for (int i = 0; i < 500; i++)
		{
			if (this->_remainMateria[i] == NULL)
			{
				this->_remainMateria[i] = this->_inventory[index];
				this->_inventory[index] = NULL;
				break ;
			}
		}
		this->_inventory[index] = NULL;
		std::cout << "Materia unequipped" << std::endl;
	}
}

void Character::use(int index, ICharacter& target)
{
	if (index < 0 || index >= SLOT)
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	else if (!this->_inventory[index])
	{
		std::cout << "No materia in this slot" << std::endl;
		return ;
	}
	this->_inventory[index]->use(target);
}
