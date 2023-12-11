/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 05:48:38 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/11 11:52:20 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# define RESET		"\033[0m"
# define BBLUE		"\033[1;34m"
# define BRED		"\033[1;31m"
# define BGREEN		"\033[1;32m"
# define BYELLOW	"\033[1;33m"
# define BCYAN		"\033[1;36m"
# define BPURPLE	"\033[1;35m"

#include <iostream>

class Zombie
{
private:
	std::string	_name;
public:
	Zombie(void);
	~Zombie(void);
	void	announce(void);
	void	setName(std::string name);
	std::string	getName(void);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
