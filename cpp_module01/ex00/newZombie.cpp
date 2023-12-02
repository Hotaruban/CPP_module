/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 05:48:31 by jhurpy            #+#    #+#             */
/*   Updated: 2023/11/17 17:25:13 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	Zombie	*zombie;

	zombie = new (std::nothrow) Zombie();
	if (zombie == NULL)
	{
		std::cout << "Error: memory allocation failed." << std::endl;
		return (NULL);
	}
	zombie->setName(name);
	return (zombie);
}
