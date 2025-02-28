/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 22:46:25 by inazaria          #+#    #+#             */
/*   Updated: 2025/02/28 13:09:18 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(str name): 
	_name(name),
	_hitpoints(10),
	_energypoints(10),
	_attackpoints(0) {
	std::cout << "String constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other): 
	_name(other._name),
	_hitpoints(other._hitpoints),
	_energypoints(other._energypoints),
	_attackpoints(other._attackpoints) {}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other) {
		this->_name = other._name;
		this->_hitpoints = other._hitpoints;
		this->_attackpoints = other._attackpoints;
		this->_energypoints = other._energypoints;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void) {
	std::cout << "Destructor has been called" << std::endl;
}

void	ClapTrap::attack(const str& target) {
	std::cout << this->_name << " attacks " << target << " and deals ";
	std::cout << this->_attackpoints << " damage points !" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	this->_hitpoints -= (signed) amount;
	std::cout << this->_name << " took " << amount << " points of damage, putting";
	std::cout << " his total hp from " << this->_hitpoints + amount << " to ";
	std::cout << this->_hitpoints << " !" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	this->_hitpoints += (signed) amount;
	std::cout << this->_name << " has been repaired for " << amount << " points, ";
	std::cout << "putting his total hp from " << this->_hitpoints - amount << " to ";
	std::cout << this->_hitpoints << " !" << std::endl;
}
