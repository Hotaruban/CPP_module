/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 00:04:16 by jhurpy            #+#    #+#             */
/*   Updated: 2024/02/17 16:15:29 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap(const FragTrap& other);
	FragTrap& operator=(const FragTrap& other);
	FragTrap(std::string name);
	void highFivesGuys();
	void attack(std::string const& target);
	~FragTrap();
protected:
	FragTrap();
};

#endif
