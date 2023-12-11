/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:12:15 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/11 11:58:59 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int n, std::string name)
{
	Zombie	*zombies = new Zombie[n];

	if (n <= 0)
		return (NULL);
	for (int i = 0; i < n; i++)
	{

		zombies[i].setName(std::string(name).append(std::to_string(i)));
		zombies[i].announce();
	}
	return (zombies);
}
