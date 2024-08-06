/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:12:27 by jhurpy            #+#    #+#             */
/*   Updated: 2024/08/06 09:51:27 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"

span::span() : N(0)
{

}

span::span(unsigned int n) : N(n)
{

}

span::span(const span &span)
{
	*this = span;
}

span::~span()
{

}

span &span::operator=(const span &span)
{
	N = span.N;
	return *this;
}
