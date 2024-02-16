/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:17:15 by jhurpy            #+#    #+#             */
/*   Updated: 2024/02/17 00:18:32 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap claptrap("Dark Knight");
	ScavTrap scavtrap("Scavenger");
	FragTrap fragtrap("Fragger");

	scavtrap.guardGate();
	claptrap.attack("Scavenger");
	scavtrap.takeDamage(0);
	scavtrap.beRepaired(5);
	fragtrap.highFivesGuys();
	fragtrap.attack("Scavenger");
	scavtrap.takeDamage(30);
	scavtrap.beRepaired(5);
	scavtrap.attack("Fragger");
	fragtrap.takeDamage(20);
	fragtrap.beRepaired(5);
	fragtrap.highFivesGuys();
	fragtrap.attack("Scavenger");
	scavtrap.takeDamage(30);
	scavtrap.beRepaired(5);
	scavtrap.attack("Fragger");
	fragtrap.takeDamage(20);
	fragtrap.beRepaired(5);
	fragtrap.attack("Scavenger");
	scavtrap.takeDamage(30);
	scavtrap.beRepaired(5);
	scavtrap.attack("Fragger");
	fragtrap.takeDamage(20);
	fragtrap.beRepaired(5);
	fragtrap.attack("Scavenger");
	scavtrap.takeDamage(30);
	scavtrap.beRepaired(5);
	fragtrap.highFivesGuys();
	scavtrap.guardGate();
	return (0);
}
