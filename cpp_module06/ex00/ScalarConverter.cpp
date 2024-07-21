/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 00:20:38 by jhurpy            #+#    #+#             */
/*   Updated: 2024/07/22 00:03:57 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	*this = src;
}

ScalarConverter::~ScalarConverter()
{

}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs)
{
	if (this != &rhs)
	{
		*this = rhs;
	}
	return *this;
}

void ScalarConverter::outChar(double num)
{
	char c;
	if (isnan(num) || isinf(num))
	{
		std::cout << "char: impossible" << std::endl;
	}
	else
	{
		c = static_cast<char>(num);
		if (isprint(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
}

void ScalarConverter::outInt(double num)
{
	if (isnan(num) || isinf(num) || num > std::numeric_limits<int>::max() || num < -std::numeric_limits<int>::max())
	{
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		std::cout << "int: " << static_cast<int>(num) << std::endl;
	}
}

void ScalarConverter::outFloat(double num)
{
	if (isnan(num) || isinf(num))
	{
		std::cout << "float: " << num << "f" << std::endl;
	}
	else if (num > std::numeric_limits<float>::max() || num < -std::numeric_limits<float>::max())
	{
		std::cout << "float: impossible" << std::endl;
	}
	else
	{
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(num) << "f" << std::endl;
	}
}

void ScalarConverter::outDouble(double num)
{
	if (isnan(num) || isinf(num))
	{
		std::cout << "double: " << num << std::endl;
	}
	else if (num > std::numeric_limits<double>::max() || num < -std::numeric_limits<double>::max())
	{
		std::cout << "double: impossible" << std::endl;
	}
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << num << std::endl;
}

void ScalarConverter::convert(std::string _value)
{
	char *endptr;
	double value = std::strtod(_value.c_str(), &endptr);

	if (*endptr != '\0' || (_value.empty() && !(endptr == _value.c_str() + 1 && *_value.c_str() == '-')))
	{
		std::cout << "Error: invalid argument" << std::endl;
		return;
	}
	ScalarConverter::outChar(value);
	ScalarConverter::outInt(value);
	ScalarConverter::outFloat(value);
	ScalarConverter::outDouble(value);
}
