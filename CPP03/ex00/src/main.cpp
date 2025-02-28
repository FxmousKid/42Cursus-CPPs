/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 22:44:35 by inazaria          #+#    #+#             */
/*   Updated: 2025/02/28 12:54:41 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap claptrap("Claptrap");
	ClapTrap claptrap2("Claptrap2");

	claptrap.attack("Jack");
	claptrap.takeDamage(10);
	claptrap.beRepaired(5);

	claptrap2.attack("Jack");
	claptrap2.takeDamage(10);
	claptrap2.beRepaired(5);

	
	return (0);
}
