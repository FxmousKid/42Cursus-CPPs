/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:43:56 by inazaria          #+#    #+#             */
/*   Updated: 2025/02/28 19:07:32 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog(): Animal("Dog") {
	std::cout << "[C] Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other): Animal(other._type) {}

Dog&	Dog::operator=(const Dog& other) {
	if (this != &other) {
		Animal::operator=(other);
	}
	return (*this);
}

Dog::~Dog() {
	std::cout << "[D] Dog destructor called" << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "Dog says woof" << std::endl;
}
