/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:17:20 by jhurpy            #+#    #+#             */
/*   Updated: 2024/02/17 16:00:52 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constructor" << std::endl;
	_name = "ClapTrap";
	_hitPoints = 10;
	_maxHitPoints = _hitPoints;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap parameterized constructor" << std::endl;
	_name = name;
	_hitPoints = 10;
	_maxHitPoints = _hitPoints;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "ClapTrap copy constructor" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		_name = other._name;
		_maxHitPoints = other._maxHitPoints;
		_hitPoints = other._hitPoints;
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
		std::cout << _name << " attack " << target << " with a water gun, causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
		std::cout << _name << " has " << _energyPoints << " energy points left!" << std::endl;
	}
	else
		std::cout << _name << " has no energy points to attack!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		std::cout << _name << " take " << amount << " points of damage!" << std::endl;
		_hitPoints -= amount;
		if (_hitPoints <= 0)
			std::cout << _name << " is dead!" << std::endl;
		else
			std::cout << _name << " has " << _hitPoints << " hitpoints left!" << std::endl;
	}
	else
		std::cout << _name << " is already dead!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints > 0 && _hitPoints < _maxHitPoints && _energyPoints > 0)
	{
		std::cout << _name << " be repaired " << amount << " points of damage!" << std::endl;
		_hitPoints += amount;
		if (_hitPoints > _maxHitPoints)
			_hitPoints = _maxHitPoints;
		_energyPoints--;
		std::cout << _name << " has " << _hitPoints << " hitpoints left!" << std::endl;
		std::cout << _name << " has " << _energyPoints << " energy points left!" << std::endl;
	}
	else if (_hitPoints == _maxHitPoints)
		std::cout << _name << " has already full hitpoints!" << std::endl;
	else if (_hitPoints > 0)
		std::cout << _name << " has no energy points to be repaired!" << std::endl;
}
