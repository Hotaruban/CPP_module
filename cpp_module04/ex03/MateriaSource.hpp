/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:14:00 by jhurpy            #+#    #+#             */
/*   Updated: 2024/04/27 19:41:11 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

#define STOCK 4

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &other);
		~MateriaSource(void);
		MateriaSource &operator=(const MateriaSource &other);

		virtual void		learnMateria(AMateria *materia);
		virtual AMateria	*createMateria(const std::string &type);

	private:
		AMateria			*_stockMateria[STOCK];
};


#endif
