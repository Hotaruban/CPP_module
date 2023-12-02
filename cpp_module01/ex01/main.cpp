/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 05:48:28 by jhurpy            #+#    #+#             */
/*   Updated: 2023/11/17 21:41:24 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int		numberZombie;

	numberZombie = 5;
	zombieHorde(numberZombie, "Zombie");
	//for (int i = 0; i < numberZombie; i++)
	//	delete &zombieHorde(numberZombie, "Zombie")[i];
	return (0);
}
