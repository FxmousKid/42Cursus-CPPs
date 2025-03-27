/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 21:23:10 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/27 21:54:46 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
array<T>::array(): _arr(0), _size(0)
{
}

template <typename T>
array<T>::array(unsigned int n)
{
	_arr = new T[n];
	_size = n;
}

template <typename T>
array<T>::array(const array& rhs)
{
	this = rhs;
}

template <typename T>
array<T>&	array<T>::operator=(const array& rhs)
{
	if (this != &rhs)
	{
		if (_arr)
			delete[] (_arr);
		_arr = new T(rhs._size);
		for (int i = 0; i < rhs._size; i++)
			this[i] = rhs[i];
	}
	return (*this);
}

template <typename T>
array<T>::~array()
{
	if (_arr)
		delete[] (_arr);
}

template <typename T>
T&	array<T>::operator[](unsigned int n)
{
	if (n >= _size)
		throw array<T>::OutOfBoundsIndexException();
	return (_arr[n]);
}

template <typename T>
unsigned int array<T>::size() const {
	return (_size);
}

template <typename T>
const char	*array<T>::OutOfBoundsIndexException::what() const throw()
{
	return ("Index is ouf bounds");
}
