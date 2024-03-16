/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:42:03 by jhurpy            #+#    #+#             */
/*   Updated: 2024/03/16 21:40:58 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal
{
public:
	virtual ~Animal();
	virtual void makeSound() const;
	void setType(std::string type);
	//Brain* getBrain();
	std::string getType() const;
protected:
	Animal();
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);
	std::string type;
//private:
//	Brain* brain;
};

#endif
