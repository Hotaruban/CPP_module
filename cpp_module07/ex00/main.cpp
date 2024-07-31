/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:15:21 by jhurpy            #+#    #+#             */
/*   Updated: 2024/07/31 22:54:17 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "whatever.hpp"

int main(void)
{
	std::cout << "------------------------------------" << std::endl;
	int a = 2;
	int b = 3;

	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap<int>(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min<int>(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max<int>(a, b) << std::endl;

	std::cout << "------------------------------------" << std::endl;
	std::string c = "Hello";
	std::string d = "World";

	std::cout << "c = " << c << ", d = " << d << std::endl;
	::swap<std::string>(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min<std::string>(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max<std::string>(c, d) << std::endl;
	std::cout << "------------------------------------" << std::endl;

	return (0);
}
