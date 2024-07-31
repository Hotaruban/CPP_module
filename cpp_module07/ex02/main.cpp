/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:04:22 by jhurpy            #+#    #+#             */
/*   Updated: 2024/07/31 22:33:37 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Array.hpp"

int main(void)
{
	std::cout << "------------------------------------" << std::endl;
	Array<std::string> array4(3);

	try {
		array4[0] = "Hello";
		array4[1] = "World";
		array4[2] = "!";
		for (unsigned int i = 0; i < 3; i++)
			std::cout << array4[i] << " ";
		std::cout << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "------------------------------------" << std::endl;
	Array<int> array(5);

	try {
		for (unsigned int i = 0; i < 5; i++)
			array[i] = i;
		for (unsigned int i = 0; i < 5; i++)
			std::cout << array[i] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "------------------------------------" << std::endl;
	Array<int> array2(array);

	try {
		for (unsigned int i = 0; i < 6; i++)
			std::cout << array2[i] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "------------------------------------" << std::endl;
	Array<int> array3;
	array3 = array;

	try {
		for (unsigned int i = 0; i < 5; i++)
			std::cout << array3[i] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "------------------------------------" << std::endl;

	return 0;
}
