/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:04:22 by jhurpy            #+#    #+#             */
/*   Updated: 2024/07/31 23:11:18 by jhurpy           ###   ########.fr       */
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

//#define MAX_VAL 750
//int main(int, char**)
//{
//	Array<int> numbers(MAX_VAL);
//	int* mirror = new int[MAX_VAL];
//	srand(time(NULL));
//	for (int i = 0; i < MAX_VAL; i++)
//	{
//		const int value = rand();
//		numbers[i] = value;
//		mirror[i] = value;
//	}
//	//SCOPE
//	{
//		Array<int> tmp = numbers;
//		Array<int> test(tmp);
//	}

//	for (int i = 0; i < MAX_VAL; i++)
//	{
//		if (mirror[i] != numbers[i])
//		{
//			std::cerr << "didn't save the same value!!" << std::endl;
//			return 1;
//		}
//	}
//	try
//	{
//		numbers[-2] = 0;
//	}
//	catch(const std::exception& e)
//	{
//		std::cerr << e.what() << '\n';
//	}
//	try
//	{
//		numbers[MAX_VAL] = 0;
//	}
//	catch(const std::exception& e)
//	{
//		std::cerr << e.what() << '\n';
//	}

//	for (int i = 0; i < MAX_VAL; i++)
//	{
//		numbers[i] = rand();
//	}
//	delete [] mirror;//
//	return 0;
//}
