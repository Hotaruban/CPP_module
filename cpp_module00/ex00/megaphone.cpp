/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 00:09:58 by jhurpy            #+#    #+#             */
/*   Updated: 2023/11/10 21:51:23 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
	if (ac == 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *"
			<< std::endl, 0);
	for (int i = 1; av[i]; i++)
	{
		for (int j = 0; av[i][j]; j++)
			std::cout << (char)std::toupper(av[i][j]);
	}
	std::cout << '\n';
	return (0);
}
