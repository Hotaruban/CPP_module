/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 04:11:57 by jhurpy            #+#    #+#             */
/*   Updated: 2024/08/24 04:20:38 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"

static bool	checkFile(std::string filename)
{
	std::ifstream file(filename);

	if (!file.is_open())
		return false;
	file.close();
	return true;
}

int	main(int ac, char **av)
{
	try {
		if (ac != 2)
			throw std::invalid_argument("Usage: ./btc filename");
		if (!checkFile(av[1]))
			throw std::invalid_argument("Error: could not open file");
		if (!checkFile("../data.csv"))
			throw std::invalid_argument("Error: could not open data.csv");
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}


	return 0;
}
