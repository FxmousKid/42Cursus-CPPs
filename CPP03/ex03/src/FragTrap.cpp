/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:10:11 by inazaria          #+#    #+#             */
/*   Updated: 2025/02/28 16:49:17 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap(str name): ClapTrap(name) {
	std::cout << "String FragTrap Constructor called" << std::endl;
	this->_hitpoints = 100;
	this->_energypoints = 100;
	this->_attackpoints = 30;
}

FragTrap&	FragTrap::operator=(const FragTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		this->_name = other._name;
		this->_hitpoints = other._hitpoints;
		this->_energypoints = other._energypoints;
		this->_attackpoints = other._attackpoints;
	}
	return (*this);
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other._name) {
	*this = other;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called" << std::endl;
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "Please high five me !" << std::endl;
}
