/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:45:58 by inazaria          #+#    #+#             */
/*   Updated: 2025/02/25 19:20:38 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {
	return;
}

Weapon::Weapon() {
	return;
}

Weapon::~Weapon() {
	return;
}

const str  &Weapon::getType() const {
	return (this->_type);
}

void	Weapon::setType(str type) {
	this->_type = type;
}
