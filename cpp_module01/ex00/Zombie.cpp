/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 05:48:35 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/11 11:53:22 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << BGREEN "A new zombie is born" << RESET << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << BRED << getName() << ": is dead for ever" << RESET << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}

std::string	Zombie::getName(void)
{
	return (this->_name);
}

void	Zombie::announce(void)
{
	std::cout << BBLUE << this->_name << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}
