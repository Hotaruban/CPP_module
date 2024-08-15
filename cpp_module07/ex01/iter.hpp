/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 20:38:49 by jhurpy            #+#    #+#             */
/*   Updated: 2024/08/15 12:39:00 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void iter(T *array, size_t length, void (*function)(T const &))
{
	for (size_t i = 0; i < length; i++)
		function(array[i]);
}

template <typename T>
void print(T const &element)
{
	std::cout << element << "\t";
}

#endif
