/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 04:11:57 by jhurpy            #+#    #+#             */
/*   Updated: 2024/09/13 19:33:35 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"

// Use containers std::map because it is a key-value pair container
// Use std::string for the key and int for the value
// The value in data.csv have a key unique so it is logical to use a map

int	main(int ac, char **av)
{
	std::ifstream file(av[1]);

	try {
		if (ac != 2)
			throw std::invalid_argument("Usage: ./btc filename");
		else if (!file.is_open())
				throw std::invalid_argument(INVALID_FILE + std::string(av[1]));
		BitcoinExchange exchange;
		//exchange.displayData();
		exchange.exchangeRate(file);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		if (ac == 2)
			file.close();
		return 1;
	}
	return 0;
}
