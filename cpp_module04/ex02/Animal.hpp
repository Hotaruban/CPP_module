/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:42:03 by jhurpy            #+#    #+#             */
/*   Updated: 2024/03/13 09:14:49 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
private:
	Animal();
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);
public:
	virtual ~Animal();
	virtual void makeSound() const = 0;
	std::string getType() const;
	void setType(std::string type);
protected:
	std::string type;
};

#endif
