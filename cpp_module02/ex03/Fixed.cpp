/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:29:22 by jhurpy            #+#    #+#             */
/*   Updated: 2024/02/14 19:18:06 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) { }

Fixed::Fixed(const int value)
{
	_value = value << bits;
}

Fixed::Fixed(const float value)
{
	_value = (int)roundf(value * (1 << bits));
}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
	{
		_value = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed() { }

int Fixed::getRawBits(void) const
{
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

int Fixed::toInt(void) const
{
	return (_value >> bits);
}

float Fixed::toFloat(void) const
{
	return ((float)_value / (1 << bits));
}

bool Fixed::operator>(const Fixed& other) const
{
	return (_value > other.getRawBits());
}

bool Fixed::operator<(const Fixed& other) const
{
	return (_value < other.getRawBits());
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (_value >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (_value <= other.getRawBits());
}

bool Fixed::operator==(const Fixed& other) const
{
	return (_value == other.getRawBits());
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (_value != other.getRawBits());
}

Fixed Fixed::operator+(const Fixed& other) const
{
	return (Fixed(toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed& other) const
{
	return (Fixed(toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed& other) const
{
	return (Fixed(toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed& other) const
{
	if (other.toFloat() == 0)
	{
		std::cerr << "Error: division by zero" << std::endl;
		return (Fixed(0));
	}
	return (Fixed(toFloat() / other.toFloat()));
}

Fixed& Fixed::operator++(void)
{
	_value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed& Fixed::operator--(void)
{
	_value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b ? a : b);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}
