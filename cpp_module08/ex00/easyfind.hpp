/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 20:47:24 by jhurpy            #+#    #+#             */
/*   Updated: 2024/08/05 13:21:56 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <exception>
# include <vector>
# include <list>

template <typename T>
void	easyfind(T &container, int value);

class ValueNotFoundException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Value not found in container.");
		}
};

# include "easyfind.tpp"

#endif
