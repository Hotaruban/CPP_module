/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 13:30:00 by jhurpy            #+#    #+#             */
/*   Updated: 2024/09/16 19:37:43 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

// Use containers std::vector and std::list because they are the most suitable for the merge sort algorithm
// - std::vector is a sequence container representing an array that can change in size
// - std::list is a container that supports constant time insertion and removal of elements from anywhere in the container

bool	isNumber(char **av, int & ac)
{
	for (int i = 1; i < ac; i++)
		for (int j = 0; av[i][j]; j++)
			if (!std::isdigit(av[i][j]))
				throw std::invalid_argument("Error: invalid argument: " + std::string(av[i]));
	return (true);
}

int	main(int ac, char **av)
{
	try {
		if (ac <= 3)
			throw std::invalid_argument("Usage: ./pmergme [list of integerS]");
		isNumber(av, ac);

		PmergeMe pmergeMe(av, ac);
		pmergeMe.printUnsortedNumbers(av, ac);

		pmergeMe.sortVec();
		pmergeMe.sortList();

	} catch (std::invalid_argument &e) {
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
