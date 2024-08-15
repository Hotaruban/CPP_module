/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:12:27 by jhurpy            #+#    #+#             */
/*   Updated: 2024/08/15 20:23:09 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"

span::span() : N(0)
{

}

span::span(unsigned int n) : N(n)
{
	std::cout << "Span created" << std::endl;
}

span::span(const span &span)
{
	*this = span;
}

span::~span()
{
	std::cout << "Span destroyed" << std::endl;
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
		//std::cout << "Number added: " << number << std::endl;
	}
	else
		throw numberFullException();
}

int span::shortestSpan()
{
	if (vector.size() < 2)
		throw numberEmptyException();
	sort(vector.begin(), vector.end());
	int shortest = vector[1] - vector[0];
	for (size_t i = 1; i < vector.size() - 1; i++)
	{
		if (vector[i + 1] - vector[i] < shortest)
			shortest = vector[i + 1] - vector[i];
	}
	return shortest;
}

int span::longestSpan()
{
	if (vector.size() < 2)
		throw numberEmptyException();
	sort(vector.begin(), vector.end());
	return vector[vector.size() - 1] - vector[0];
}

void span::forAddNumber(int number)
{
	srand(time(0));
	try {
		for (int i = 0; i < number; i++)
		{
			int random = rand();
			addNumber(random);
		}
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
