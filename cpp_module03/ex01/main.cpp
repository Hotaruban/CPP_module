/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:17:15 by jhurpy            #+#    #+#             */
/*   Updated: 2024/02/16 21:32:17 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap claptrap("Dark Knight");
	ScavTrap scavtrap("Scavenger");

	scavtrap.guardGate();
	claptrap.attack("Scavenger");
	scavtrap.takeDamage(0);
	scavtrap.beRepaired(5);
	scavtrap.attack("Dark Knight");
	claptrap.takeDamage(20);
	claptrap.beRepaired(5);
	scavtrap.guardGate();
	return (0);
}
