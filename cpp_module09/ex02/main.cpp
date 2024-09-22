/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:46:20 by jhurpy            #+#    #+#             */
/*   Updated: 2024/09/22 17:07:52 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


int main(int argc, char **argv)
{
	std::vector<int> vector;
	std::list<int> list;

	try {
		PmergeMe<std::vector<int> > vectorPmergeMe(vector);
		//PmergeMe<std::list<int> > listPmergeMe(list);

		vectorPmergeMe.startClock();
		vectorPmergeMe.makeIntegers(argv, argc);
		vectorPmergeMe.printContainer("Before sorting:\t", SIZE_PRINT);
		vectorPmergeMe.mergeInsert();
		vectorPmergeMe.endClock();
		vectorPmergeMe.printContainer("After sorting:\t", SIZE_PRINT);
		vectorPmergeMe.returnTime("std::vector");

		//listPmergeMe.startClock();
		//listPmergeMe.makeIntegers(argv, argc);
		//listPmergeMe.printContainer("Before sorting:\t", SIZE_PRINT);
		//listPmergeMe.mergeInsert();
		//listPmergeMe.endClock();
		//listPmergeMe.printContainer("After sorting:\t", SIZE_PRINT);
		//listPmergeMe.returnTime("std::list");

	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}
