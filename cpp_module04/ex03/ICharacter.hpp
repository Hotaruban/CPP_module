/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 22:32:32 by jhurpy            #+#    #+#             */
/*   Updated: 2024/04/27 19:49:13 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"

class AMateria;

class ICharacter
{
public:
	virtual ~ICharacter(void){};

	virtual std::string const &getName(void) const = 0;
	virtual void equip(AMateria *m) = 0;
	virtual void unequip(int index) = 0;
	virtual void use(int index, ICharacter &target) = 0;
};

#endif
