/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 05:48:28 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/11 12:01:02 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// modify the delete of memory the announce

int	main(void)
{
	int		numberZombie;
	Zombie	*zombies;

	numberZombie = 5;
	zombies = zombieHorde(numberZombie, "Zombie");
	delete [] zombies;
	return (0);
}
