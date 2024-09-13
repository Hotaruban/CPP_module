/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 13:30:00 by jhurpy            #+#    #+#             */
/*   Updated: 2024/09/14 01:35:01 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

// Use containers std::vector and std::list because they are the most suitable for the merge sort algorithm
// - std::vector is a sequence container representing an array that can change in size
// - std::list is a container that supports constant time insertion and removal of elements from anywhere in the container

int	main(int ac, char **av)
{
	try {
		if (ac == 1)
			throw std::invalid_argument("Usage: ./pmergme [list of integers]");

		PmergeMe pmergeMe(av + 1, ac - 1);


	} catch (std::invalid_argument &e) {
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
