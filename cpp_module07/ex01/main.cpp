/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 22:32:50 by jhurpy            #+#    #+#             */
/*   Updated: 2024/07/24 22:36:23 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
	int array[] = {1, 2, 3, 4, 5};
	char array2[] = {'a', 'b', 'c', 'd', 'e'};
	std::string array3[] = {"one", "two", "three", "four", "five"};

	std::cout << "---------------------------------" << std::endl;
	std::cout << "Int array:" << std::endl;
	::iter<int>(array, 5, print);
	std::cout << "\nChar array:" << std::endl;
	::iter<char>(array2, 5, print);
	std::cout << "\nString array:" << std::endl;
	::iter<std::string>(array3, 5, print);
	std::cout << "\n---------------------------------" << std::endl;

	return (0);
}
