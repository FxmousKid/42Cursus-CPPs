/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:55:08 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/02 18:30:45 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal("Cat") {
	std::cout << "[C] Cat constructor called" << std::endl;
	this->_brain = new Brain();
}

Cat::Cat(const Cat& other): Animal(other._type), _brain(0) {
	(*this) = other;
}

Cat&	Cat::operator=(const Cat& other) {
	if (this != &other) {
		Animal::operator=(other);
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return (*this);
}

Cat::~Cat() {
	std::cout << "[D] Cat destructor called" << std::endl;
	delete this->_brain;
}

void	Cat::makeSound() const {
	std::cout << "Cat says meow" << std::endl;
}

Brain	*Cat::getBrain() const {
	return (this->_brain);
}
