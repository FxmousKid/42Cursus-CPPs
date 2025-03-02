/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 22:21:54 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/02 18:30:58 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <cstring>

Brain::Brain() {
	std::cout << "[C] Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& other) {
	(*this) = other;
}

Brain&	Brain::operator=(const Brain& other) {
	std::cout << "[A] Brain operator= called" << std::endl;
	if (this != &other) {
		for (size_t i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	return (*this);
}

Brain::~Brain() {
	std::cout << "[D] Brain destructor called" << std::endl;
}
