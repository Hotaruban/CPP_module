/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 23:37:38 by jhurpy            #+#    #+#             */
/*   Updated: 2024/02/14 19:42:16 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const& a, Point const& b, Point const& c, Point const& point)
{
	Fixed f1 = (b.getX() - point.getX()) * (a.getY() - point.getY()) - (b.getY() - point.getY()) * (a.getX() - point.getX());
	Fixed f2 = (c.getX() - point.getX()) * (b.getY() - point.getY()) - (c.getY() - point.getY()) * (b.getX() - point.getX());
	Fixed f3 = (a.getX() - point.getX()) * (c.getY() - point.getY()) - (a.getY() - point.getY()) * (c.getX() - point.getX());

	std::cout << "f1: " << f1 << std::endl;
	std::cout << "f2: " << f2 << std::endl;
	std::cout << "f3: " << f3 << std::endl;

	if ((f1 > 0 && f2 > 0 && f3 > 0) || (f1 < 0 && f2 < 0 && f3 < 0))
		return (true);
	return (false);
}
