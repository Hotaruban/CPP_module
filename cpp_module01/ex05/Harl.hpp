/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 00:31:46 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/02 02:00:01 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# define RESET		"\033[0m"
# define BBLUE		"\033[1;34m"
# define BRED		"\033[1;31m"
# define BGREEN		"\033[1;32m"
# define BYELLOW	"\033[1;33m"
# define BCYAN		"\033[1;36m"
# define BPURPLE	"\033[1;35m"

# include <iostream>
# include <fstream>

class Harl
{
	public:
		Harl(void);
		~Harl(void);
		void	complain(std::string level);
	private:
		void		debug(void);
		void		info(void);
		void		warning(void);
		void		error(void);
		std::string	level[4];
		void		(Harl::*speak[4])(void);
};

#endif
