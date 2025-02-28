/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 22:44:35 by inazaria          #+#    #+#             */
/*   Updated: 2025/02/28 14:04:03 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap a("Joe");	
	ScavTrap b("Bob");

	a.attack("Bob");
	b.takeDamage(20);
	b.beRepaired(10);

	a.guardGate();
	b.guardGate();
	return (0);
}
