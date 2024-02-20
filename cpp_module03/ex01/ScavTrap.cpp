/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 21:32:07 by jhurpy            #+#    #+#             */
/*   Updated: 2024/02/20 17:45:52 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap operator= called" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return *this;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	_hitPoints = 100;
	_maxHitPoints = _hitPoints;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::guardGate()
{
	if (_hitPoints > 0)
		std::cout << "ScavTrap have enterred in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(std::string const& target)
{
	if (_hitPoints > 0)
	{
		std::cout << _name << " get ready to attack " << target << std::endl;
		_energyPoints--;
		std::cout << _name << " attack " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	}
}
