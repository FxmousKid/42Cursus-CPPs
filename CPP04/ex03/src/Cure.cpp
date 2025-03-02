/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:39:30 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/01 14:49:51 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "AMateria.hpp"

Cure::Cure(): AMateria("cure") {	
	std::cout << "[C] Cure constructor called" << std::endl;
}

Cure::Cure(const Cure& other) {
	this->_type = other._type;
}

Cure&	Cure::operator=(const Cure& other) {
	if (this == &other)
		this->_type = "ice";
	return (*this);
}

Cure::~Cure() {
	std::cout << "[D] Cure destructor called" << std::endl;
}

AMateria	*Cure::clone() const {
	AMateria *newCure = new Cure();
	return (newCure);
}

// void		Cure::use(ICharacter& target) {
// 	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
// }
