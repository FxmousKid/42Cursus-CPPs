/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 19:38:17 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/27 22:37:01 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <iostream>

template <typename T> void iter(T *arr, size_t len, void f(T&))
{
	size_t i;

	i = 0;
	while (i < len)
	{
		f(arr[i]);
		i++;
	}
}

template <typename T> void print_item(T item)
{
	std::cout << item << " ";
}
