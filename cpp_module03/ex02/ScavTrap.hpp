/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 21:30:46 by jhurpy            #+#    #+#             */
/*   Updated: 2024/02/17 16:15:24 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap(const ScavTrap& other);
	ScavTrap& operator=(const ScavTrap& other);
	ScavTrap(std::string name);
	void guardGate();
	void attack(std::string const& target);
	~ScavTrap();
protected:
	ScavTrap();
};

#endif
