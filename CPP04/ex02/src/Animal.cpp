/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:39:52 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/01 01:29:11 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): _type("Any") {
	std::cout << "[C] Animal [Any] constructor called" << std::endl;
}

Animal::Animal(str type): _type(type) {
	std::cout << "[C] Animal [" << type <<  "] constructor called" << std::endl;
}

Animal::~Animal() {
	std::cout << "[D] Animal [" << _type <<  "] destructor called" << std::endl;
}

Animal::Animal(const Animal &src) {
	*this = src;
}

Animal &Animal::operator=(const Animal &src) {
	if (this != &src) {
		_type = src._type;
	}
	return *this;
}

std::string	Animal::getType() const {
	return (_type);
}

void	Animal::makeSound() const {
	std::cout << "Animals don't make sound" << std::endl;
}
