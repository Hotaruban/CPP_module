/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:29:30 by jhurpy            #+#    #+#             */
/*   Updated: 2024/02/14 19:42:49 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
	Point a(0, 0); // angle of the triangle
	Point b(0, 2); // angle of the triangle
	Point c(2.1, 0); // angle of the triangle
	Point point(1, 1); // point to check

	if (bsp(a, b, c, point) == true)
		std::cout << "The point is inside the triangle" << std::endl;
	else
		std::cout << "The point is outside the triangle" << std::endl;
}
