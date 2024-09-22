/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:46:20 by jhurpy            #+#    #+#             */
/*   Updated: 2024/09/22 22:46:15 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// test to do in evaluation ./PmergeMe $(jot -r 3000 1 1000 | tr '\n' ' ')

int main(int argc, char **argv)
{
	std::vector<int> vector;
	std::list<int> list;

	try {
		PmergeMe<std::vector<int> > vectorPmergeMe(vector);
		PmergeMe<std::list<int> > listPmergeMe(list);

		vectorPmergeMe.startClock();
		vectorPmergeMe.makeIntegers(argv, argc);
		vectorPmergeMe.printContainer(BEFORE, SIZE_PRINT);
		vectorPmergeMe.mergeInsertVector();
		vectorPmergeMe.endClock();
		vectorPmergeMe.printContainer(AFTER, SIZE_PRINT);
		vectorPmergeMe.returnTime(VECTOR);

		listPmergeMe.startClock();
		listPmergeMe.makeIntegers(argv, argc);
		//listPmergeMe.printContainer(BEFORE, SIZE_PRINT);
		listPmergeMe.mergeInsertList();
		listPmergeMe.endClock();
		//listPmergeMe.printContainer(AFTER, SIZE_PRINT);
		listPmergeMe.returnTime(LIST);

	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}
