/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:43:56 by inazaria          #+#    #+#             */
/*   Updated: 2025/02/28 23:51:17 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"
#include "Brain.hpp"

Dog::Dog(): Animal("Dog") {
	std::cout << "[C] Dog constructor called" << std::endl;
	this->_brain = new Brain();
}

Dog::Dog(const Dog& other): Animal(other._type) {}

Dog&	Dog::operator=(const Dog& other) {
	if (this != &other) {
		Animal::operator=(other);
		this->_brain = other._brain;
	}
	return (*this);
}

Dog::~Dog() {
	std::cout << "[D] Dog destructor called" << std::endl;
	delete this->_brain;
}

void	Dog::makeSound() const {
	std::cout << "Dog says woof" << std::endl;
}

Brain	*Dog::getBrain() const {
	return (this->_brain);
}
