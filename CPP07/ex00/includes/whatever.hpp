/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pairs.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:33:34 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/27 19:27:20 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T> void swap(T& a, T& b)
{
	T tmp = b;
	b = a;
	a = tmp;
}

template <typename T> T	min(T& a, T& b)
{
	if (a < b)
		return (a);
	return (b);
}

template <typename T> T	max(T& a, T& b)
{
	if (a > b)
		return (a);
	return (b);
}
