/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:42:17 by inazaria          #+#    #+#             */
/*   Updated: 2025/02/28 16:53:46 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap(str name):
	ClapTrap(name + "_clap_trap"),
	ScavTrap(name),
	FragTrap(name)
{
	this->_name = name;
	this->_hitpoints = FragTrap::_hitpoints;
	this->_energypoints = ScavTrap::_energypoints;
	this->_attackpoints = FragTrap::_attackpoints;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other._name + "_clap_trap");
		ScavTrap::operator=(other._name);
		FragTrap::operator=(other._name);
		this->_name = other._name;
		this->_hitpoints = other._hitpoints;
		this->_energypoints = other._energypoints;
		this->_attackpoints = other._attackpoints;
	}
	return (*this);
}

DiamondTrap::DiamondTrap(const DiamondTrap& other):
	ClapTrap(other._name + "_clap_trap"),
	ScavTrap(other._name),
	FragTrap(other._name) 
{
		this->_name = other._name;
		this->_hitpoints = other._hitpoints;
		this->_energypoints = other._energypoints;
		this->_attackpoints = other._attackpoints;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->_name << " is destroyed" << std::endl;
}

void	DiamondTrap::attack(const str& target) {
	ScavTrap::attack(target);
}


void	DiamondTrap::whoAmI(void) {
	std::cout << "DiamondTrap name = " << this->_name << " :)" << std::endl;
	std::cout << "ClapTrap name = " << ClapTrap::_name << " :)" << std::endl;
}
