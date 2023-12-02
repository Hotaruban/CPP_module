/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 22:21:45 by jhurpy            #+#    #+#             */
/*   Updated: 2023/11/19 13:34:15 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon)
{
	return;
}

HumanA::~HumanA(void)
{
	std::cout << BRED << this->_name << " is dead" << RESET << std::endl;
	return;
}

void	HumanA::attack(void)
{
	std::cout << BBLUE << this->_name << " attacks with their " << this->_weapon.getType() << RESET << std::endl;
}
