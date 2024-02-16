/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:17:15 by jhurpy            #+#    #+#             */
/*   Updated: 2024/02/16 17:56:29 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap claptrap1("ClapTrap");
	ClapTrap claptrap2("ClapTrap2");

	claptrap1.attack("ClapTrap2");
	claptrap2.takeDamage(0);
	claptrap2.beRepaired(3);
	claptrap2.attack("ClapTrap");
	claptrap1.takeDamage(0);
	claptrap1.beRepaired(3);
	return (0);
}
