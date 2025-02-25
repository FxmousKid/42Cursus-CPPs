/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:57:49 by inazaria          #+#    #+#             */
/*   Updated: 2025/02/25 19:24:49 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#include "Weapon.hpp"

typedef std::string str;

class HumanA {
public:
	HumanA(str name, Weapon &weapon);
	~HumanA(void);
	void	attack(void); 

private:
	Weapon &_weapon;
	str		_name;


};
