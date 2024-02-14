/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 23:37:28 by jhurpy            #+#    #+#             */
/*   Updated: 2024/02/14 19:35:18 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0) , _y(0) { }

Point::Point(const Point& other)
{

}

Point& Point::operator=(const Point& other)
{
	if (this != &other)
	{}
	return *this;
}

Point::Point(const float x, const float y) : _x(x), _y(y) { }

Point::~Point() { }

int	Point::getX() const
{
	return (_x.getRawBits());
}

int	Point::getY() const
{
	return (_y.getRawBits());
}
