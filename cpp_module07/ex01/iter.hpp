/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 20:38:49 by jhurpy            #+#    #+#             */
/*   Updated: 2024/07/25 00:25:18 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void iter(T *array, int length, void (*function)(T const &))
{
	for (int i = 0; i < length; i++)
		function(array[i]);
}

template <typename T>
void print(T const &element)
{
	std::cout << element << "\t";
}

#endif
