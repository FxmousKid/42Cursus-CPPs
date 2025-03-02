/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMteria.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:27:20 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/01 13:55:42 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {
	std::cout << "[C] AMateria constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other) {
	(void)other;
}

AMateria&	AMateria::operator=(const AMateria& other) {
	(void)other;
	return (*this);
}

AMateria::~AMateria() {
	std::cout << "[D] AMateria destructor called" << std::endl;
}

AMateria::AMateria(const str& type): _type(type) {
	std::cout << "[C] AMateria custom constructor called" << std::endl;
}

const str&	AMateria::getType() const {
	return (this->_type);
}

AMateria	*AMateria::clone() const {
	return (NULL);
}
