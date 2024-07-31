/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:05:10 by jhurpy            #+#    #+#             */
/*   Updated: 2024/07/29 16:39:24 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

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
				virtual const char *what() const throw();
		};

	private:

};

#include "Array.tpp"

#endif
