/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 00:08:46 by jhurpy            #+#    #+#             */
/*   Updated: 2024/07/22 00:11:56 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{

}

Serializer::Serializer(const Serializer& other)
{
	*this = other;
}

Serializer& Serializer::operator=(const Serializer& other)
{
	(void)other;
	return *this;
}

Serializer::~Serializer()
{

}

uintptr_t Serializer::serialize(Data *ptr)
{



}

Data *Serializer::deserialize(uintptr_t raw)
{



}
