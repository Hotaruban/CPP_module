/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 00:19:50 by jhurpy            #+#    #+#             */
/*   Updated: 2024/07/31 14:53:16 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib>
# include <iomanip>
# include <cmath>
# include <cctype>
# include <limits>

class ScalarConverter
{
public:
	static void convert(std::string _value);
	static void outChar(double num);
	static void outInt(double num);
	static void outFloat(double num);
	static void outDouble(double num);

private:
	ScalarConverter();
	ScalarConverter(ScalarConverter const &src);
	~ScalarConverter();

	ScalarConverter &operator=(ScalarConverter const &rhs);
};

#endif
