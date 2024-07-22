/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 00:07:21 by jhurpy            #+#    #+#             */
/*   Updated: 2024/07/22 15:56:17 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data *data = new Data;
	Data *data2;
	uintptr_t serializedData;

	data->latitude = 48.8566;
	data->longitude = 2.3522;

	serializedData = Serializer::serialize(data);
	data2 = Serializer::deserialize(serializedData);

	std::cout << "-----------------------------------" << std::endl;
	std::cout << "data2 test1: " << std::endl;
	std::cout << "Latitude: " << data2->latitude << std::endl;
	std::cout << "Longitude: " << data2->longitude << std::endl;
	std::cout << "-----------------------------------" << std::endl;

	delete data;
	std::cout << "data deleted" << std::endl;
	data2 = Serializer::deserialize(serializedData);

	std::cout << "-----------------------------------" << std::endl;
	std::cout << "data2 test2: " << std::endl;
	std::cout << "Latitude: " << data2->latitude << std::endl;
	std::cout << "Longitude: " << data2->longitude << std::endl;
	std::cout << "-----------------------------------" << std::endl;

	return (0);
}
