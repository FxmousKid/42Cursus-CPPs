/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:00:00 by inazaria          #+#    #+#             */
/*   Updated: 2025/02/25 19:25:55 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#include "Weapon.hpp"

typedef std::string str;

class HumanB {
public:
	HumanB(str name);
	~HumanB(void);
	void	attack(void);
	void	setWeapon(Weapon &weapon);

private:
	Weapon	*_weapon;
	str		_name;

};
