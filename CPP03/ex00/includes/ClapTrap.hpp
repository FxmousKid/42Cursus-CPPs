/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 22:46:59 by inazaria          #+#    #+#             */
/*   Updated: 2025/02/28 13:13:52 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

typedef std::string str;

class ClapTrap {
public:
	ClapTrap(str name);
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);
	~ClapTrap(void);

	void	attack(const str& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

private:
	str _name;
	int	_hitpoints;
	int	_energypoints;
	int	_attackpoints;
};
