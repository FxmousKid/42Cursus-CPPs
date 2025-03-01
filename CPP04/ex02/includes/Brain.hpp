/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 22:22:06 by inazaria          #+#    #+#             */
/*   Updated: 2025/02/28 23:25:10 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

typedef std::string str;

class Brain {
public:
	Brain();
	Brain(const Brain& other);
	Brain&	operator=(const Brain& other);
	virtual ~Brain();


	str	ideas[100];
	
};
