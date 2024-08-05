/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:12:54 by jhurpy            #+#    #+#             */
/*   Updated: 2024/08/05 13:22:31 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "easyfind.hpp"

int	main(void)
{
	std::vector<int> vec(5);
	vec[0] = 1;
	vec[1] = 2;
	vec[2] = 3;
	vec[3] = 4;
	vec[4] = 5;

	std::cout << "Test with vector" << std::endl;
	std::cout << "------------------------------------" << std::endl;
	try {
		easyfind(vec, 4);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "------------------------------------" << std::endl;
	try {
		easyfind(vec, 6);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "------------------------------------" << std::endl;

	std::list<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);
	lst.push_back(5);

	std::cout << "Test with list" << std::endl;
	std::cout << "------------------------------------" << std::endl;
	try {
		easyfind(lst, 4);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "------------------------------------" << std::endl;
	try {
		easyfind(lst, 6);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "------------------------------------" << std::endl;


	return (0);
}
