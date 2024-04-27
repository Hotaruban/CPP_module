/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:12:49 by jhurpy            #+#    #+#             */
/*   Updated: 2024/04/27 19:49:03 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"
#include "MateriaSource.hpp"

#define SLOT 4

class Character : public ICharacter
{
	public:
		Character(std::string const &name);
		Character(const Character &other);
		~Character(void);
		Character &operator=(const Character &other);

		const std::string&	getName(void) const;
		void				equip(AMateria *m);
		void				unequip(int index);
		void				use(int index, ICharacter &target);

	private:
		std::string			_name;
		AMateria			*_inventory[SLOT];
		AMateria			*_remainMateria[500];
};

#endif
