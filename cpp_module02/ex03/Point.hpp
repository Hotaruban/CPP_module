/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 23:37:33 by jhurpy            #+#    #+#             */
/*   Updated: 2024/02/14 19:34:34 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
public:
	Point();
	Point(const Point& other);
	Point& operator=(const Point& other);
	Point(const float x, const float y);
	~Point();
	int getX() const;
	int getY() const;
private:
	const Fixed _x;
	const Fixed _y;
};

bool	bsp(Point const& a, Point const& b, Point const& c, Point const& point);

#endif
