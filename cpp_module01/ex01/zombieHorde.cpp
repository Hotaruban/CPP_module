/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:12:15 by jhurpy            #+#    #+#             */
/*   Updated: 2024/02/15 14:32:30 by jhurpy           ###   ########.fr       */
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
		std::stringstream ss;
		zombies[i].setName(name + ss.str());
		zombies[i].announce();
	}
	return (zombies);
}
