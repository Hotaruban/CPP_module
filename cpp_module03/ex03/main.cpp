/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:17:15 by jhurpy            #+#    #+#             */
/*   Updated: 2024/02/17 09:04:47 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	ClapTrap claptrap("Dark Knight");
	ScavTrap scavtrap("Scavenger");
	FragTrap fragtrap("Fragger");
	DiamondTrap diamondtrap("Diamond");

	claptrap.attack("Scavenger");
	scavtrap.takeDamage(0);
	scavtrap.beRepaired(5);
	scavtrap.guardGate();
	fragtrap.highFivesGuys();
	diamondtrap.attack("Fragger");
	diamondtrap.whoAmI();
	fragtrap.takeDamage(30);
	fragtrap.beRepaired(10);
	fragtrap.highFivesGuys();
	scavtrap.attack("Fragger");
	claptrap.takeDamage(20);
	claptrap.beRepaired(10);
	scavtrap.guardGate();
	return (0);
}
