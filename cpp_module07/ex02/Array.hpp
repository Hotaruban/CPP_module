/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:05:10 by jhurpy            #+#    #+#             */
/*   Updated: 2024/07/31 19:44:08 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template <typename T>
class Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &src);
		~Array();

		Array &operator=(const Array &src);
		T &operator[](unsigned int index);

		unsigned int size() const;

		class OutOfLimitsException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Index is out of limits.");
				}
		};

	private:
		T * _array;
		unsigned int _size;
};

#include "Array.tpp"

#endif
