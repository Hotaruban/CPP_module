/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:56:23 by jhurpy            #+#    #+#             */
/*   Updated: 2024/04/27 18:16:06 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	public:
		AMateria(std::string const & type);
		AMateria(const AMateria& other);
		virtual ~AMateria(void);

		std::string const &	getType() const;
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);

	protected:
		std::string			_type;
};

#endif
