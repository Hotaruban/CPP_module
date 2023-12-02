/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 00:31:48 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/02 15:20:33 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	harl;

	if (argc != 2)
		return (std::cout << BRED << "Usage: ./harl [level] => {DEBUG, INFO, WARNING, ERROR}" << RESET << std::endl, 1);
	harl.complainFilter(argv[1]);
	return (0);
}
