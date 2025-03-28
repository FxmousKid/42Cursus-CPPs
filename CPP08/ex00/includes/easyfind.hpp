/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:09:55 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/28 17:48:24 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdexcept>
#include <iostream>
#include <algorithm>


template <typename T> void easyfind(T& container, int elem)
{
	typename T::iterator it = std::find(container.begin(), container.end(), elem);
	if (it == container.end()) {
		throw std::runtime_error("Element not found in array");
	}
	std::cout << "Found element " << elem << " at index "
		<< std::distance(container.begin(), it) << std::endl;
}
