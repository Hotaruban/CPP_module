/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:12:27 by jhurpy            #+#    #+#             */
/*   Updated: 2024/08/07 14:35:37 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"

span::span() : N(0)
{

}

span::span(unsigned int n) : N(n)
{
	std::cout << "span created" << std::endl;
}

span::span(const span &span)
{
	*this = span;
}

span::~span()
{
	std::cout << "span destroyed" << std::endl;
}

span &span::operator=(const span &span)
{
	N = span.N;
	return *this;
}

void span::addNumber(int number)
{
	if (vector.size() < N)
	{
		vector.push_back(number);
		std::cout << "Number added: " << number << std::endl;
	}
	else
		throw numberFullException();
}

int span::shortestSpan()
{
	if (vector.size() < 2)
		throw numberEmptyException();
	

	return 0;
}

int span::longestSpan()
{
	if (vector.size() < 2)
		throw numberEmptyException();


	return 0;
}
