/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:42:40 by jhurpy            #+#    #+#             */
/*   Updated: 2024/02/20 11:24:59 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "WrongCat created" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
{
	std::cout << "Copy of the WrongCat" << std::endl;
	type = other.type;
	*this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "Assignation of the WrongCat" << std::endl;
	if (this != &other)
	{
		type = other.type;
	}
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongMeow, Coin Coin ?" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destroyed" << std::endl;
}
