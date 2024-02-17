/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 00:04:10 by jhurpy            #+#    #+#             */
/*   Updated: 2024/02/17 09:21:03 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
{

}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
	{}
	return *this;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_name = name;
	_hitpoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (_hitpoints > 0)
		std::cout << _name << " high fives guys" << std::endl;
}

void FragTrap::attack(std::string const& target)
{
	if (_hitpoints > 0)
	{
		std::cout << _name << " get ready to attack " << target << std::endl;
		_energyPoints--;
		std::cout << _name << " attack " << target << " with is long sword, causing " << _attackDamage << " points of damage!" << std::endl;
	}
}
