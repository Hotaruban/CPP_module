/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 05:48:28 by jhurpy            #+#    #+#             */
/*   Updated: 2023/11/17 21:11:38 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	zombie1;
	Zombie	*zombie2 = newZombie("Bar");

	zombie1.setName("Foo");
	zombie1.announce();
	zombie2->announce();
	randomChump("Baz");
	delete zombie2;
	return (0);
}
