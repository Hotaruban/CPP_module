/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 00:08:46 by jhurpy            #+#    #+#             */
/*   Updated: 2024/07/22 15:49:54 by jhurpy           ###   ########.fr       */
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
	// convert the Data struct to a uintptr_t
	unsigned long long dataPtr;

	dataPtr = reinterpret_cast<unsigned long long>(ptr);
	return dataPtr;
}

Data *Serializer::deserialize(uintptr_t raw)
{
	// convert the uintptr_t to a Data struct
	Data *data;

	data = reinterpret_cast<Data *>(raw);
	return data;
}
