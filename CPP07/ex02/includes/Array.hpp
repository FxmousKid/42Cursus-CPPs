/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 20:42:16 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/27 21:54:52 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>

template <typename T>
class array
{
public:
	array();
	array(const array& rhs);
	array& operator=(const array& rhs);
	~array();
	
	array(unsigned int n);
	T&	operator[](unsigned int n);

	unsigned int size() const;

	class OutOfBoundsIndexException: public std::exception {
		virtual const char *what() const throw();
	};



private:
	T				*_arr;
	unsigned int	_size;
};

#include "Array.tpp"
