/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:04:13 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/01 14:48:21 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "AMateria.hpp"

Ice::Ice(): AMateria("ice") {
	std::cout << "[C] Ice constructor called" << std::endl;
}

Ice::Ice(const Ice& other) {
	this->_type = other._type;
}

Ice&	Ice::operator=(const Ice& other) {
	if (this == &other)
		this->_type = "ice";
	return (*this);
}

Ice::~Ice() {
	std::cout << "[D] Ice destructor called" << std::endl;
}



AMateria	*Ice::clone() const {
	AMateria *newIce = new Ice();
	return (newIce);
}

// void		Ice::use(ICharacter& target) {
// 	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
// }
