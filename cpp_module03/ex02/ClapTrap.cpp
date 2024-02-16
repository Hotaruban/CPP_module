/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:17:20 by jhurpy            #+#    #+#             */
/*   Updated: 2024/02/17 00:39:15 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap parameterized constructor" << std::endl;
	_name = name;
	_hitpoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	_name = other._name;
	_hitpoints = other._hitpoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	std::cout << "ClapTrap copy constructor" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		_name = other._name;
		_hitpoints = other._hitpoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor" << std::endl;
}

void ClapTrap::attack(std::string const& target)
{
	if (_energyPoints > 0)
	{
		std::cout << _name << " attack " << target << "with a spire, causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
		std::cout << _name << " has " << _energyPoints << " energy points left!" << std::endl;
	}
	else
		std::cout << _name << " has no energy points to attack!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitpoints > 0)
	{
		std::cout << _name << " take " << amount << " points of damage!" << std::endl;
		_hitpoints -= amount;
		if (_hitpoints <= 0)
			std::cout << _name << " is dead!" << std::endl;
		else
			std::cout << _name << " has " << _hitpoints << " hitpoints left!" << std::endl;
	}
	else
		std::cout << _name << " is already dead!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitpoints > 0 && _energyPoints > 0)
	{
		std::cout << _name << " be repaired " << amount << " points of damage!" << std::endl;
		_hitpoints += amount;
		_energyPoints--;
		std::cout << _name << " has " << _hitpoints << " hitpoints left!" << std::endl;
		std::cout << _name << " has " << _energyPoints << " energy points left!" << std::endl;
	}
	else if (_hitpoints > 0)
		std::cout << _name << " has no energy points to be repaired!" << std::endl;
}
