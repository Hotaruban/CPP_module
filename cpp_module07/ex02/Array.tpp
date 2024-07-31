/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:14:05 by jhurpy            #+#    #+#             */
/*   Updated: 2024/07/31 16:20:09 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include "Array.hpp"

template <typename T>
Array<T>::Array() // Constructor
{
	_array = NULL;
	_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n) // Constructor with size
{
	_array = new T[n];
	_size = n;
}

template <typename T>
Array<T>::Array(const Array &src) // Copy constructor
{
	*this = src;
}

template <typename T>
Array<T>::~Array() // Destructor
{
	if (_array)
		delete [] _array;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &src) // Assignation operator
{
	if (this != &src)
	{
		if (_array)
			delete [] _array;
		_array = new T[src._size];
		for (unsigned int i = 0; i < src._size; i++)
			_array[i] = src._array[i];
		_size = src._size;
	}
	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index) // Operator []
{
	if (index >= _size)
		throw OutOfLimitsException();
	return _array[index];
}

template <typename T>
unsigned int Array<T>::size() const // Size method
{
	return _size;
}

#endif
