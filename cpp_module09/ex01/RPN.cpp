/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:49:07 by jhurpy            #+#    #+#             */
/*   Updated: 2024/09/13 20:57:31 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(const char * str)
{
	_result = 0;

	RPN::_calculate(str);
}

RPN::RPN(const RPN &src)
{
	(void)src;
}

RPN &RPN::operator=(const RPN &src)
{
	if (this != &src)
		(void)src;
	return *this;
}

RPN::~RPN() {}

bool RPN::_isOperator(const char & c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false;
}

void RPN::_makeOperation(const char & c)
{
	int a;
	int b;

	if (_stack.size() < 2)
		throw std::invalid_argument("Error");

	a = _stack.top();
	_stack.pop();
	b = _stack.top();
	_stack.pop();

	if (c == '+')
		_stack.push(b + a);
	else if (c == '-')
		_stack.push(b - a);
	else if (c == '*')
		_stack.push(b * a);
	else if (c == '/')
		_stack.push(b / a);

	_result = _stack.top();
}

bool RPN::_isDigit(const char & c)
{
	if (std::isdigit(c))
		return true;
	return false;
}

void RPN::_calculate(const char * str)
{
	int len = std::strlen(str);
	if (!str)
		throw std::invalid_argument("Error");

	for (int i = 0; i < len; i++)
	{
		if (str[i] == ' ')
			continue;
		else if (RPN::_isOperator(str[i]) && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			RPN::_makeOperation(str[i]);
		else if (_isDigit(str[i]) && str[i + 1] == ' ')
			_stack.push(std::atoi(&str[i]));
		else
			throw std::invalid_argument("Error");
	}

	std::cout << _result << std::endl;
}
