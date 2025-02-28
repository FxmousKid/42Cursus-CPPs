/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 13:13:18 by inazaria          #+#    #+#             */
/*   Updated: 2025/02/28 14:05:11 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(str name): ClapTrap(name) {
	this->_hitpoints = 100;
	this->_energypoints = 50;
	this->_attackpoints = 20;
	std::cout << "String ScavTrap Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other._name) {
	this->_name = other._name;
	this->_hitpoints = other._hitpoints;
	this->_energypoints = other._energypoints;
	this->_attackpoints = other._attackpoints;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other._name);
		this->_hitpoints = other._hitpoints;
		this->_energypoints = other._energypoints;
		this->_attackpoints = other._attackpoints;
	}
	return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap desctructor called" << std::endl;
}

void	ScavTrap::guardGate(void) {
	std::cout << this->_name <<  " is now in guard mode !" << std::endl;
}

